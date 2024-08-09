FROM debian:buster

# Install prerequisites
RUN apt-get update && apt-get install -y software-properties-common wget gnupg build-essential

# Add the LLVM APT repository and install LLVM 14
RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - && \
    apt-add-repository "deb http://apt.llvm.org/buster/ llvm-toolchain-buster-14 main" && \
    apt-get update && \
    apt-get install -y clang-14 libclang-14-dev llvm-14-dev cmake git wget clang-format

# Create symlinks for LLVM tools
RUN ln -s /usr/bin/clang-14 /usr/bin/clang && ln -s /usr/bin/llvm-config-14 /usr/bin/llvm-config

# Install other required packages
RUN apt-get install -y libcurl4-openssl-dev astyle

# Install Python 3.10.14 from source
RUN apt-get update && \
    apt-get install -y \
    libffi-dev \
    libssl-dev \
    zlib1g-dev \
    libbz2-dev \
    libreadline-dev \
    libsqlite3-dev \
    wget \
    libncursesw5-dev \
    libgdbm-dev \
    libc6-dev \
    tk-dev \
    libdb5.3-dev \
    libexpat1-dev \
    liblzma-dev \
    libgdbm-compat-dev && \
    cd /usr/src && \
    wget https://www.python.org/ftp/python/3.10.14/Python-3.10.14.tgz && \
    tar xzf Python-3.10.14.tgz && \
    cd Python-3.10.14 && \
    ./configure --enable-optimizations && \
    make altinstall && \
    rm /usr/src/Python-3.10.14.tgz

# Install pip
RUN wget https://bootstrap.pypa.io/get-pip.py && \
    python3.10 get-pip.py && \
    rm get-pip.py

# Create symlink for python3
RUN ln -sf /usr/local/bin/python3.10 /usr/bin/python3

# Clone and build the Chisel project
RUN git clone https://github.com/moizali01/Blade_LLM

# Install Python dependencies
RUN pip install -r Blade_LLM/LLM_Util/requirements.txt

# Install curl
RUN apt install -y curl

# Set environment variables
ENV CC=clang

# Install additional dependencies for sanitizers
RUN apt-get install -y libstdc++-8-dev

# Set environment variables for sanitizers
ENV ASAN_OPTIONS=detect_stack_use_after_return=1
ENV MSAN_OPTIONS=msan_track_origins=1
ENV UBSAN_OPTIONS=print_stacktrace=1

# Uncomment if you need to make these scripts executable
# RUN chmod +x Blade_LLM/automated_runs/run_mkdir.sh
# RUN chmod +x Blade_LLM/automated_runs/run_rm.sh
# RUN chmod +x Blade_LLM/automated_runs/run_uniq.sh
# RUN chmod +x Blade_LLM/automated_runs/run_sort.sh