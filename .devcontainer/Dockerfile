FROM mcr.microsoft.com/devcontainers/cpp:1-ubuntu-24.04

RUN apt-get update && apt-get install -y --no-install-recommends \
    cmake \
    build-essential \
    libxrandr-dev \
    libxcursor-dev \
    libxi-dev \
    libudev-dev \
    libfreetype-dev \
    libflac-dev \
    libvorbis-dev \
    libgl1-mesa-dev \
    libegl1-mesa-dev \
    && rm -rf /var/lib/apt/lists/*

ARG USERNAME=USERNAME

# Create and user
RUN useradd -m -g users ${USERNAME}

# Set working directory (optional)
WORKDIR /home/${USERNAME}

# Switch to the new user
USER ${USERNAME}