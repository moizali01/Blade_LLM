import sys
import pysqlite3

sys.modules['sqlite3'] = pysqlite3

import os
import time
import warnings
import ollama
from datetime import datetime
from functools import cached_property
from langchain_community.llms import AzureOpenAI
from langchain_community.document_loaders import PyPDFLoader,TextLoader
from langchain_text_splitters import (Language,RecursiveCharacterTextSplitter)
from langchain_community.vectorstores import Chroma
from langchain_community.embeddings import OpenAIEmbeddings
from langchain_community.embeddings import HuggingFaceEmbeddings
from langchain_community.llms import Ollama
import google.generativeai as genai
from groq import Groq
from langchain_google_genai import GoogleGenerativeAIEmbeddings
import requests
import voyageai
from langchain.retrievers import ContextualCompressionRetriever
from langchain_voyageai import VoyageAIEmbeddings,VoyageAIRerank
from tree_sitter_languages import get_language, get_parser
from llama_index.core.text_splitter import CodeSplitter
from dotenv import load_dotenv
from LLM_Util.chunker import get_code_chunks
import subprocess
import re

dotenv_path = '../.env'
load_dotenv(dotenv_path)

class Document:
    def __init__(self, page_content, metadata=None):
        self.page_content = page_content
        self.metadata = metadata

def doc_merger(splits):
    current = 0
    while True:
        doc_lines = len(splits[current].splitlines())
        if doc_lines < 3:
            # merge with next doc
            splits[current] += splits[current + 1]
            splits.pop(current + 1)
        else:
            current += 1
        
        if current == len(splits) - 1:
            return splits

class QAClass:
    # Class-level attributes
    _embeddings = None
    _db = None

    @classmethod
    def initialize_embeddings_and_db(cls):
        if cls._embeddings is None or cls._db is None:

            ########### Voyage Code Embeddings ############

            command = ["clang-format","-style={ColumnLimit: 300, AllowShortFunctionsOnASingleLine: All, AllowShortIfStatementsOnASingleLine: true}","-i","original.txt"]

            # Run the command
            subprocess.run(command, check=True)

            file_path = "original.txt"
            with open(file_path, "r") as f:
                docs = f.read()

            # code_splitter=CodeSplitter(language="c", parser=get_parser("c"), max_chars=1500)
            # splits = code_splitter.split_text(docs)
            # new_splits = [split for split in splits if len(split) > 4]
            # new_splits2 = doc_merger(new_splits)
            # documents = [Document(page_content=split) for split in new_splits2]
            # os.environ["VOYAGE_API_KEY"] = os.environ.get("VOYAGE_API_KEY")
            # cls._embeddings = VoyageAIEmbeddings(model="voyage-code-2")

            splits = get_code_chunks(docs)
            new_splits = [split for split in splits if len(split) > 2]
            new_splits2 = doc_merger(new_splits)
            # documents = [Document(page_content=split) for split in splits]
            documents = [Document(page_content=split) for split in new_splits2]
            os.environ['GOOGLE_API_KEY'] = os.environ.get("GOOGLE_API_KEY")
            cls._embeddings = GoogleGenerativeAIEmbeddings(model="models/text-embedding-004")
            cls._db = Chroma.from_documents(documents=documents, embedding=cls._embeddings)



    # ********************************************
    # LOCAL LLM FUNCTIONS ADDED HERE

    def call_ollama(self, prompt):
        response = requests.post('http://10.103.73.29:6970', json={'message': prompt})
        # response = ollama.chat(model='llama3:8b-instruct-fp16', messages=[{'role': 'user', 'content': prompt}],options={"temperature":0.1})
        # return response['message']['content']
        return response.json()['response']


    def combine_docs(self, docs):
        return "\n\n".join(f"Snippet.{i+1}:\n\n{doc.page_content}" for i, doc in enumerate(docs))

    # os.environ["GROQ_API_KEY"] = os.environ.get("GROQ_API_KEY")
    # def call_groq(self,prompt):
    #         client = Groq(
    #             api_key=os.environ.get("GROQ_API_KEY"),
    #         )
    #         chat_completion = client.chat.completions.create(
    #             temperature=0.1,
    #             messages=[{"role": "user", "content": prompt},],
    #             model="gemma-7b-it",
    #         )

    #         return chat_completion.choices[0].message.content

    # LOCAL LLM FUNCTIONS END HERE
    # ********************************************

    @cached_property
    def llm_chain(self):

        # ***** Model Initialization Starts Here *****
        # Set up your LLM with API key Below (Not required for Ollama)

        # 1. ***** OpenAI API (Azure AI Search) *****

        # Setting up environment variables 
        # os.environ["OPENAI_API_TYPE"] = "Azure"
        # os.environ["OPENAI_API_VERSION"] = "2023-05-15"
        # os.environ["OPENAI_API_BASE"] = "https://debb.openai.azure.com/"
        # os.environ["OPENAI_API_KEY"] = os.environ.get("OPENAI_API_KEY")

        # # Suppressing warnings
        # with warnings.catch_warnings():
        #     warnings.simplefilter("ignore")

        #     # Initialize AzureOpenAI model
        #     llm = AzureOpenAI(
        #         model_name="gpt-3.5-turbo-16k",
        #         model_kwargs={"engine": "openaidemo-15999-16k"},
        #         temperature=0.2
        #     )

        # 2. ***** Gemini *****

        safe = [
            {
                "category": "HARM_CATEGORY_HARASSMENT",
                "threshold": "BLOCK_NONE",
            },
            {
                "category": "HARM_CATEGORY_HATE_SPEECH",
                "threshold": "BLOCK_NONE",
            },
            {
                "category": "HARM_CATEGORY_SEXUALLY_EXPLICIT",
                "threshold": "BLOCK_NONE",
            },
            {
                "category": "HARM_CATEGORY_DANGEROUS_CONTENT",
                "threshold": "BLOCK_NONE",
            },
        ]
        genai.configure(api_key=os.environ.get("GENAI_API_KEY"))
        generation_config = {
        "temperature": 0.1,
        "top_p": 0.95,
        "top_k": 64,
        "max_output_tokens": 8192,
        "response_mime_type": "text/plain",
        }
        model = genai.GenerativeModel(
        model_name="gemini-1.5-flash",
        generation_config=generation_config,
        safety_settings = safe
        # See https://ai.google.dev/gemini-api/docs/safety-settings
        )
        llm = model.start_chat(history=[])

        # 3. ***** Local LLM (Ollama) *****

        # llm = self.call_ollama

        # 4. ***** GROQQ CLOUD *****

        # llm = self.call_groq

        # ***** Model Initialization Ends Here *****

        # Ensure embeddings and database are initialized
        self.initialize_embeddings_and_db()

        # Instead of creating a standard RetrievalQA chain, we'll use our custom rag_chain function
        class CustomQAChain:
            def __init__(self, outer_instance):
                self.outer_instance = outer_instance

            def run(self, query, context_query, coverage, fifty_clean):

                # compressor = VoyageAIRerank(
                #     model="rerank-1", voyageai_api_key=os.environ["VOYAGE_API_KEY"], top_k=10
                # )

                # define retriever
                retriever = self.outer_instance._db.as_retriever(search_type="similarity", search_kwargs={"k": 4})

                # make compression retrieval
                # compression_retriever = ContextualCompressionRetriever(
                #     base_compressor=compressor, base_retriever=retriever
                # )
                retrieved_docs = retriever.invoke(context_query)

                formatted_context = self.outer_instance.combine_docs(retrieved_docs)

                if len(query.splitlines()) > 10:
                    formatted_context_2 = formatted_context
                else:
                    formatted_context_2 = "Snippet.0: \n\n" + fifty_clean + "\n\n" + formatted_context
                
                return self.outer_instance.call_llm(query, formatted_context_2, coverage, llm)


        return CustomQAChain(self)
    

    def call_llm(self, query, formatted_context, coverage, llm):

        if os.path.exists("../LLM_Util/sec_list.txt"):
            with open("../LLM_Util/sec_list.txt", 'r') as file:
                sec_list = file.read()
            # print("sec_list found and read")
        else:
            sec_list = self.get_security_checks()
            # print(sec_list)
            # print("Sec List Read")

        if os.path.exists("../LLM_Util/func_output.txt"):
            with open("../LLM_Util/func_output.txt", 'r') as file:
                func_list = file.read()
            print("func_list found and read")
        else:
            func_list = self.get_func_lists()
            print(func_list)
            print("Sec List Read")

        if coverage:
            with open('../LLM_Util/prompt_in_coverage.txt', 'r') as file:
                prompt_template = file.read()
        else:
            with open('../LLM_Util/prompt_not_in_coverage.txt', 'r') as file:
                prompt_template = file.read()

        prompt = prompt_template.format(sec_list=sec_list, formatted_context=formatted_context, query=query, func_list=func_list)
        prompt_to_send = prompt

        # UNCOMMENT YOUR REQUIRED LLM BELOW

        # 1. GEMINI
        # if it fails try 3 times
        try_count = 0
        while try_count < 3:
            try:
                response = llm.send_message(prompt_to_send).text
                break
            except:
                time.sleep(5)
                try_count += 1
                print("Retrying No. ", try_count)


        # 2. GPT (via Azure AI Search)
        # response = llm(prompt_to_send)

        # 3. Local LLM (via Ollama)
        # response = llm(prompt_to_send)

        return response

    def invoke(self, query, prompt_type, context_query, fifty_clean):
        # Retrieve documents based on context query
        print("Querying: ", query)
        # print("Context Retrived from DB: ", formatted_context)

        if prompt_type == 'generality':
            return self.llm_chain.run(query, context_query, False, fifty_clean)
        elif prompt_type == 'security':
            return self.llm_chain.run(query, context_query, True, fifty_clean)
        

    def get_func_lists(self):

        with open("../LLM_Util/file_names.txt", "r") as f:
            c_program = f.readline().strip()
            test_oracle = f.readline().strip()

        binary_name = c_program.split(".")[0]
        
        os.system(f'clang -w target-program/{c_program} -D __msan_unpoison\(s,z\) -lpcre -lpthread -o target-program/{binary_name}')

        output = subprocess.check_output([f"""./target-program/{binary_name}""", '--help'])
        functionality_list = output.decode('utf-8')

        with open('../LLM_Util/functionality_prompt.txt', 'r') as file:
            func_template = file.read()

        with open(f"target-program/{test_oracle}", 'r') as file:
            train_oracle = file.read()

        func_prompt = func_template.format(functionality_list = functionality_list, train_oracle=train_oracle)


        safe = [
            {
                "category": "HARM_CATEGORY_HARASSMENT",
                "threshold": "BLOCK_NONE",
            },
            {
                "category": "HARM_CATEGORY_HATE_SPEECH",
                "threshold": "BLOCK_NONE",
            },
            {
                "category": "HARM_CATEGORY_SEXUALLY_EXPLICIT",
                "threshold": "BLOCK_NONE",
            },
            {
                "category": "HARM_CATEGORY_DANGEROUS_CONTENT",
                "threshold": "BLOCK_NONE",
            },
        ]
        genai.configure(api_key=os.environ.get("GENAI_API_KEY"))
        generation_config = {
        "temperature": 0.1,
        "top_p": 0.95,
        "top_k": 64,
        "max_output_tokens": 8192,
        "response_mime_type": "text/plain",
        }
        model = genai.GenerativeModel(
        model_name="gemini-1.5-flash",
        generation_config=generation_config,
        safety_settings = safe
        # See https://ai.google.dev/gemini-api/docs/safety-settings
        )
        llm_func = model.start_chat(history=[])

        response = (llm_func.send_message(func_prompt)).text

        response = re.sub(r"\*\*Reasoning:\*\*.*\n", "", response)

        with open("../LLM_Util/func_output.txt", 'w') as file:
            file.write(response)

        return response




    def get_security_checks(self):
        code_path = "original.txt"
        with open(code_path, 'r') as file:
            code = file.read()

        sec_prompt = f"""The program to analyze is a core utility in linux. 

Make a list in bullet points to list down the exception and security related issues that must be kept in mind while testing this program. Do not include anything else in your response to this message. Do not include any point regarding the generality or the flags of the program. Make sure that the list is concise and under 20 points in total.

Here is the entire program code for the utility: 

########

{code}

########

Make a list in bullet points to list down the exception and security related issues that must be kept in mind while testing this program. Do not include anything else in your response to this message. Do not include any point regarding the generality or the flags of the program. Make sure that the list is concise and under **20 points** in total.
"""      
        safe = [
            {
                "category": "HARM_CATEGORY_HARASSMENT",
                "threshold": "BLOCK_NONE",
            },
            {
                "category": "HARM_CATEGORY_HATE_SPEECH",
                "threshold": "BLOCK_NONE",
            },
            {
                "category": "HARM_CATEGORY_SEXUALLY_EXPLICIT",
                "threshold": "BLOCK_NONE",
            },
            {
                "category": "HARM_CATEGORY_DANGEROUS_CONTENT",
                "threshold": "BLOCK_NONE",
            },
        ]
        genai.configure(api_key=os.environ.get("GENAI_API_KEY"))
        generation_config = {
        "temperature": 0.1,
        "top_p": 0.95,
        "top_k": 64,
        "max_output_tokens": 8192,
        "response_mime_type": "text/plain",
        }
        model = genai.GenerativeModel(
        model_name="gemini-1.5-flash",
        generation_config=generation_config,
        safety_settings = safe
        # See https://ai.google.dev/gemini-api/docs/safety-settings
        )
        llm_sec = model.start_chat(history=[])

        ###
        sec_list = (llm_sec.send_message(sec_prompt)).text

        with open("../LLM_Util/sec_list.txt", 'w') as file:
            file.write(sec_list)

        return sec_list