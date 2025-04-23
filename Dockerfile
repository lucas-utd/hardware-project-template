# Build Environment stage
FROM ubuntu:24.10 AS build-env

# Install essential dev tools
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    sudo \
    git \
    curl \
    wget \
    zip \
    unzip \
    ca-certificates \
    software-properties-common \
    build-essential \
    cmake \
    ninja-build \
    gdb \
    lldb \
    lcov \
    clang \
    lld \
    pkg-config \
    python3 \
    python3-pip

RUN chsh -s /bin/bash

# Dev container stage
FROM build-env AS dev-container

# Set build arguments
ARG USERNAME=devuser
ARG USER_UID=1001
ARG USER_GID=$USER_UID

# Create non-root user
RUN groupadd --gid $USER_GID $USERNAME

RUN useradd --uid $USER_UID --gid $USER_GID -m $USERNAME 

RUN echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/$USERNAME 

RUN chmod 0440 /etc/sudoers.d/$USERNAME

# Workspace stage
FROM dev-container AS workspace
COPY . /home/$USERNAME/workspaces/project
RUN chown -R $USERNAME:$USERNAME /home/$USERNAME/workspaces/project
USER $USERNAME

# Set working directory
WORKDIR /home/$USERNAME/workspaces/project
CMD ["/bin/bash"]