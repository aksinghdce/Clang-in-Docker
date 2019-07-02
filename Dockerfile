# Check http://releases.llvm.org/download.html#8.0.0 for the latest available binaries
FROM ubuntu

# Make sure the image is updated, install some prerequisites,
# Download the latest version of Clang (official binary) for Ubuntu
# Extract the archive and add Clang to the PATH
RUN apt-get update && apt-get install -y \
  xz-utils \
  build-essential \
  curl \
  && rm -rf /var/lib/apt/lists/* \
  && curl -SL http://releases.llvm.org/8.0.0/clang+llvm-8.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz \
  | tar -xJC . && \
  mv clang+llvm-8.0.0-x86_64-linux-gnu-ubuntu-18.04 clang_8.0.0 && \
  echo 'export PATH=/clang_8.0.0/bin:$PATH' >> ~/.bashrc && \
  echo 'export LD_LIBRARY_PATH=/clang_8.0.0/lib:LD_LIBRARY_PATH' >> ~/.bashrc

RUN mkdir /FAQs/
COPY FAQs /FAQs/
# Install CMake and Cpp library for PyTorch
RUN mkdir /cmake/
COPY cmake /cmake/
RUN cd /cmake/cmake-3.15.0-rc1/ \
  && ./bootstrap \
  && make -j4 \
  && make install
RUN mkdir /CPPyTorch/
COPY CPPyTorch /CPPyTorch/
# Start from a Bash prompt
# Install MLPack Later
RUN echo "deb http://archive.ubuntu.com/ubuntu/ bionic main universe" >> /etc/apt/sources.list
RUN apt-get update
RUN apt-get install -y mlpack-bin
RUN apt-get install -y libmlpack-dev
RUN apt-get install -y libboost-all-dev
CMD [ "/bin/bash" ]
