FROM ubuntu:18.04 as base

RUN cp /etc/apt/sources.list /etc/apt/sources.list.bak && \
    echo "deb http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse\n" > etc/apt/sources.list && \
    echo "deb http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse\n" >> etc/apt/sources.list && \
    echo "deb http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse\n" >> etc/apt/sources.list && \
    echo "deb http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse\n" >> etc/apt/sources.list && \
    echo "deb http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse\n" >> etc/apt/sources.list && \
    echo "deb-src http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse\n" >> etc/apt/sources.list && \
    echo "deb-src http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse\n" >> etc/apt/sources.list && \
    echo "deb-src http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse\n" >> etc/apt/sources.list && \
    echo "deb-src http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse\n" >> etc/apt/sources.list && \
    echo "deb-src http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse\n" >> etc/apt/sources.list && \
    apt-get -y update && \
    apt-get -y install sudo && \
    sudo apt-get -y install build-essential gcc-multilib gdb curl && \
    curl https://packages.edgedb.com/keys/edgedb.asc \
    | sudo apt-key add - && \
    echo deb https://packages.edgedb.com/apt bionic main \
    | sudo tee /etc/apt/sources.list.d/edgedb.list && \
    sudo apt-get update
     