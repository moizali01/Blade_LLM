import sys
import pysqlite3

sys.modules['sqlite3'] = pysqlite3

import os
import re
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
from LLM_Util.exist_coverage import update_code_with_coverage
import subprocess


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

    def __init__(self):
        self.timestamp = ""

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

    # gemini model definition and call
    def call_gemini(self,prompt):

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
        model_name="gemini-1.5-pro",
        generation_config=generation_config,
        safety_settings = safe
        # See https://ai.google.dev/gemini-api/docs/safety-settings
        )
        llm = model.start_chat(history=[])

        response = None
        try_count = 0
        while try_count < 3:
            try:
                response = llm.send_message(prompt).text
                break
            except Exception as e:
                print("Error: ", e)
                time.sleep(5)
                try_count += 1
                print("Retrying No. ", try_count)

        return response

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
        llm = self.call_gemini

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

            def run(self, query, context_query, coverage, fifty_clean, function_context):

                # define retriever
                retriever = self.outer_instance._db.as_retriever(search_type="similarity", search_kwargs={"k": 4})

                # Use similarity_search_with_score instead of invoke
                retrieved_docs_with_scores = self.outer_instance._db.similarity_search_with_score(context_query, k=4)

                retrieved_docs = [doc for doc, _ in retrieved_docs_with_scores]
                similarity_scores = [score for _, score in retrieved_docs_with_scores]


                # Sort both lists based on similarity scores in descending order
                sorted_pairs = sorted(zip(retrieved_docs, similarity_scores), key=lambda x: x[1], reverse=True)

                # Unzip the sorted pairs
                retrieved_docs, similarity_scores = zip(*sorted_pairs)

                formatted_context_2 = "Function in which the code snippet was called:\n\n" + function_context + "\n\n" + self.outer_instance.combine_docs(retrieved_docs[:2])
                function_lines = function_context
                function_lines = function_lines.splitlines()
                if len(function_lines) < 10:
                    formatted_context_2 = "Function in which the code snippet was called:\n\n" + function_context + "\n\n" + self.outer_instance.combine_docs(retrieved_docs)
                elif len(function_lines) > 1000:
                    first_100_lines = "\n".join(fifty_clean.splitlines()[:100])
                    last_100_lines = "\n".join(fifty_clean.splitlines()[-100:])
                    formatted_context_2 = "Snippet.0: \n\n" + first_100_lines + "\n\n" "Snippet.1: \n\n" + last_100_lines + "\n\n" + self.outer_instance.combine_docs(retrieved_docs[:2])
                # if len(query.splitlines()) > 10:
                #     formatted_context_2 = self.outer_instance.combine_docs(retrieved_docs)
                # else:
                #     formatted_context_2 = "Snippet.0: \n\n" + fifty_clean + "\n\n" + self.outer_instance.combine_docs(retrieved_docs[:2])
                
                return self.outer_instance.call_llm(query, formatted_context_2, coverage, llm)


        return CustomQAChain(self)
    
    # need to make three calls to LLM, 1) relevance of context, 2) generality and 3) security
    def call_llm(self, query, formatted_context, coverage, llm):

        # if coverage:
        #     with open('../LLM_Util/prompt_in_coverage.txt', 'r') as file:
        #         prompt_template = file.read()
        # else:
        #     with open('../LLM_Util/prompt_not_in_coverage.txt', 'r') as file:
        #         prompt_template = file.read()

        # prompt = prompt_template.format(sec_list=sec_list, formatted_context=formatted_context, query=query)
        # prompt_to_send = prompt
        # Classify the context as relevant or not. If not, retain
        print("Checking Relevance")
        relevance, summary = self.check_relevance(query, formatted_context, llm)
        print(relevance)
        if relevance == "no":
            return "final verdict: class 4"
        else:
            # query functionality
            print("Checking Functionality")
            functionality = self.check_functionality(query, formatted_context, llm, coverage, summary)
            print(functionality)
            # retain since it is needed for required functionality
            if functionality == "yes":
                return "final verdict: class 4"
            else:
                # query security
                print("Checking Security")
                security = self.check_security(query, formatted_context, llm, coverage)
                print(security)
                # retain since it is needed for required security
                if security == "yes":
                    return "final verdict: class 4"
                else:
                    return "final verdict: class 1"
                

    # function to check relevance of context with query
    def check_relevance(self, query, formatted_context, llm):
        
        with open("../LLM_Util/check_relevance_prompt.txt", 'r') as file:
            prompt_template = file.read()

        prompt = prompt_template.format(context=formatted_context, query=query)
        os.makedirs("../LLM_Util/cands/prompt", exist_ok=True)
        with open("../LLM_Util/cands/prompt/prompt" + "_time_"+ str(self.timestamp) + ".blade.c.txt", 'w') as file:
            file.write(prompt)

        response = llm(prompt)

        if response == None:  
            return "no", "No response from LLM"

        # call agent 2 here
        with open("../LLM_Util/confirm_relevance_prompt.txt", 'r') as file:
            confirm_relevance_prompt = file.read()

        prompt = confirm_relevance_prompt.format(context=formatted_context, query=query, summary=response)
        response2 = llm(prompt)

        if response2 == None:
            return "no", response

        merged_response = response + "\n\n" + response2
        file_name = "../LLM_Util/cands/multiagent/new_relevance/relevance" + "_time_"+ str(self.timestamp) + ".blade.c.txt"
        with open (file_name, 'w') as file:
            file.write(merged_response)

        # # save response to cands/multiagent/security
        # file_name = "../LLM_Util/cands/multiagent/relevance/relevance" + "_time_"+ str(self.timestamp) + ".blade.c.txt"
        # with open(file_name, 'w') as file:
        #     file.write(response)


        # # parse response to get "yes" or "no"
        # match = re.search(r'\b(yes|no)\b', response.lower().strip())
        # if match is not None:
        #     return match.group(1).lower()
        # else:
        #     return "no"

        # parse response to get "yes" or "no"
        match = re.search(r'Final Verdict\s*:\s*(yes|no)', response2.strip(), re.IGNORECASE)
        print(match)
        if match is not None:
            return match.group(1).lower(), response
        else:
            return "no", response
        
        return "no", response

    def check_functionality(self, query, formatted_context, llm, coverage, summary):
        with open("../LLM_Util/functionality_prompt.txt", 'r') as file:
            prompt_template = file.read()

        # in_cov_statement = "This code snippet included in the code execution path for the required functionality, therefore verify if the given code snippet is important for required functionality of the program."
        # not_cov_statement = "This code snippet is not included in the code execution path for the required functionality, therefore verify if the given code snippet is important for the required functionality of the program."

        with open("../LLM_Util/req_list.txt", 'r') as file:
            req_list = file.read()

        # cov_info = in_cov_statement if coverage else not_cov_statement
        # code_with_cov = update_code_with_coverage(self.timestamp)
        

        prompt = prompt_template.format(context=formatted_context, query=query, summary=summary, req_list=req_list)

        response = llm(prompt)

        # save response to cands/multiagent/functionality
        file_name = "../LLM_Util/cands/multiagent/functionality/functionality" + "_time_"+ str(self.timestamp) + ".blade.c.txt"
        with open(file_name, 'w') as file:
            file.write(response)

        # parse response to get "yes" or "no"
        match = self.extract_imp_score_new_prompt(response)
        if match is not None:
            if match == 9:
                return "yes"
            elif match == 1:
                return "no"

        # retain if there is any issue in extracting importance score
        return "yes"

    def check_security(self, query, formatted_context, llm, coverage):

        if os.path.exists("../LLM_Util/sec_list.txt"):
            with open("../LLM_Util/sec_list.txt", 'r') as file:
                sec_list = file.read()
            # print("sec_list found and read")
        else:
            sec_list = self.get_security_checks()
            print(sec_list)
            print("Sec List Read")

        with open("../LLM_Util/security_prompt.txt", 'r') as file:
            prompt_template = file.read()

        in_cov_statement = "This code snippet included in the code execution path for the required functionality, therefore verify if the given code snippet is important for any of the listed potential security vulnerabilities in the program."
        not_cov_statement = "This code snippet is not included in the code execution path for the required functionality, therefore verify if the given code snippet is important for any of the listed potential security vulnerabilities in the program."

        cov_info = in_cov_statement if coverage else not_cov_statement

        prompt = prompt_template.format(context=formatted_context, query=query, coverage_info=cov_info, sec_list=sec_list)

        response = llm(prompt)

        # save response to cands/multiagent/security
        file_name = "../LLM_Util/cands/multiagent/security/security" + "_time_"+ str(self.timestamp) + ".blade.c.txt"
        with open(file_name, 'w') as file:
            file.write(response)

        # parse response to get "yes" or "no"
        match = self.extract_imp_score_new_prompt(response)
        if match is not None:
            if match == 9:
                return "yes"
            elif match == 1:
                return "no"

        # retain if there is any issue in extracting importance score
        return "yes"

    def invoke(self, query, prompt_type, context_query, fifty_clean, passed_time, function_context):
        # Retrieve documents based on context query
        print("Querying: ", query)
        # print("Context Retrived from DB: ", formatted_context)

        self.timestamp = passed_time

        if prompt_type == 'generality':
            return self.llm_chain.run(query, context_query, False, fifty_clean, function_context)
        elif prompt_type == 'security':
            return self.llm_chain.run(query, context_query, True, fifty_clean, function_context)
        

    def get_security_checks(self):
        code_path = "original.txt"
        with open(code_path, 'r') as file:
            code = file.read()

        with open("../LLM_Util/req_list.txt", 'r') as file:
            req_list = file.read()

        sec_prompt = f"""The program to analyze is a core Linux utility. Your task is to analyze the provided program code and the list of **required functionality** to generate a concise list of potential security vulnerabilities that could affect the required functionality. 

### Instructions:
- Consider security and exception-related issues such as buffer overflows, race conditions, input validation issues, improper use of system calls, privilege escalation, and resource management vulnerabilities.
- Focus only on vulnerabilities that could impact the **required functionality**. 
- Address security concerns related to **input validation**, **boundary checking**, **memory management**, and **handling of special file types**.
- Do not include points related to excluded or unrequired functionality.
- **Do not** discuss generality, flags, or unrelated features of the program.
- Ensure the list is limited to a maximum of **20 concise bullet points**.

### Reference Information:
{req_list}

- **Program Code**: 
########
{code}
########

### Output:
- Provide a list of bullet points, each describing a potential security vulnerability or exception that should be tested in the context of the **required functionality** only, including issues related to input validation, memory usage, boundary checks, race conditions, and resource handling. Make sure the list is concise and limited to a maximum of 20 bullet points."""      
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
        # genai.configure(api_key="AIzaSyCeL2G0fQvkgYn95s7p0orgbgOqtO-lZ28")
        genai.configure(api_key=os.environ.get("GENAI_API_KEY"))
        generation_config = {
        "temperature": 0.1,
        "top_p": 0.95,
        "top_k": 64,
        "max_output_tokens": 8192,
        "response_mime_type": "text/plain",
        }
        model = genai.GenerativeModel(
        model_name="gemini-1.5-pro",
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


    def extract_imp_score_new_prompt(self,text): 

        # Convert the text to lowercase
        lower_text = text.lower()
        target = "final verdict"

        # Find the position of "importance score"
        start_index = lower_text.find(target)
        if start_index == -1:
            return None  # "Importance Score" not found

        # Move the start index to the end of "importance score"
        start_index += len(target)

        # Find the next newline character after "importance score"
        end_index = text.find('\n', start_index)
        if end_index == -1:
            end_index = len(text)  # if no newline, go to the end of the text

        # Extract the substring between "importance score" and the newline
        substring = text[start_index:end_index]

        # Find the number in the substring
        import re
        match = re.search(r'\b([0-9]|[1-9][0-9]|100)\b', substring)
        if match:
            assigned_class = int(match.group(0))
            # removal class
            if assigned_class < 3:
                return 1
            else:
                return 9
        else:
            return None  # No number found