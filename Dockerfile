# Build Environment stage
FROM mcr.microsoft.com/devcontainers/cpp:ubuntu24.04 AS dev-container

# Install essential dev tools
# RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
#     sudo \
#     git \
#     curl \
#     wget \
#     zip \
#     unzip \
#     ca-certificates \
#     software-properties-common \
#     build-essential \
#     cmake \
#     ninja-build \
#     gdb \
#     lldb \
#     lcov \
#     clang \
#     lld \
#     pkg-config \
#     python3 \
#     python3-pip


# Workspace stage
CMD ["/bin/bash"]