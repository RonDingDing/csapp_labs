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
    sudo apt-get -y install build-essential && \
    sudo apt-get -y install gcc-multilib && \
    sudo apt-get -y install gdb