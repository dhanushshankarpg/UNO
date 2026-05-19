FROM ubuntu:22.04

RUN DEBIAN_FRONTEND=noninteractive \
    apt-get update \
    && apt-get install -y \
    build-essential \
    cmake \
    wget \
    bzip2 \
    make \
    unzip \
    cppcheck \
    clang-format-12 \
    git \
    iputils-ping \
    gdb \
    ninja-build \
    sudo

# X11
RUN DEBIAN_FRONTEND=noninteractive \
    sudo apt-get install -y \
    libfreetype6-dev \
    libx11-dev \
    libxrandr-dev \
    libxcursor-dev \
    libxi-dev \
    libudev-dev \
    libgl1-mesa-dev \
    libvorbis-dev \
    libogg-dev \
    libflac-dev \
    libopenal-dev

RUN useradd -rm -d /home/ubuntu -s /bin/bash -g root -G sudo \
    -u 1001 ubuntu \
    && echo "ubuntu ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

USER ubuntu

WORKDIR /workspace