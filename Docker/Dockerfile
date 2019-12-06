# Ubuntu Dockerfile
#image
FROM ubuntu:18.04
#install
RUN \
    apt-get update && \
    apt-get install g++ && \
    apt-get install valgrind && \
    apt-get install git && \
    apt-get install make && \ 
    apt-get autoclean && \
    rm -rf /var/lib/apt/lists/*
    
