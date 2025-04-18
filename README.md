[![Build](https://github.com/lucas-utd/hardware-project-template/actions/workflows/cmake-vcpkg-build.yml/badge.svg)](https://github.com/lucas-utd/hardware-project-template/actions/workflows/cmake-vcpkg-build.yml)

# 🚀 Hardware Project Template (C++ 23)

## ✈️ Overview  
This is a cross-platform hardware project template built with **C++ 23** and **vcpkg**. The project is designed with **modern C++ features** (such as concepts in template programming) and follows **software design patterns** to ensure maintainability and scalability.  

## 🎯 Features  
- Cross-platform support (**Windows & Linux**)  
- Uses **CMake** for project configuration  
- Dependency management via **vcpkg**  
- Leverages **modern C++** (C++23 concepts, smart pointers, and more)  
- Implements **software design patterns** for better code organization  
- **GitHub Workflow** for automatic testing on **Windows** and **Ubuntu** 
- Use **vcpkg** as a submodule to get the same experience on all platforms
- Use **CMakePresets** to simplify the build process
- **CMakeUserPresets.json** for user-specific CMake configurations (Optional)

## 🛠️ Build Instructions  

### 🔹 Prerequisites  
Ensure you have the following installed:  
- **CMake** (≥3.28)  
- **C++ 23 compiler** (MSVC, GCC, or Clang)  
- **vcpkg** for dependency management  
- **CMakePresets.json** for the default CMake configurePresets (Optional)

### 🔹 Windows (MSVC + vcpkg)  
```PowerShell
# Run those commands in Developer PowerShell for VS 2022
git clone --recurse-submodules -j8 https://github.com/lucas-utd/hardware-project-template.git
cd hardware-project-template

# Configure and build
cmake --workflow --preset x64-release
```

### 🔹 Linux (GCC + vcpkg)  
```sh
git clone --recurse-submodules -j8 https://github.com/lucas-utd/hardware-project-template.git
cd hardware-project-template

# Configure and build
cmake --workflow --preset x64-release
```

## 🏗️ Code Structure  
- **`src/`** - Game source files  
- **`include/`** - Header files  
- **`CMakeLists.txt`** - Build configuration  
- **`CMakePresets.json`** - CMake Preset  
- **`.github/workflows/`** - GitHub Actions workflow files  

## 🔄 Continuous Integration (CI)  
This project includes a **GitHub Actions workflow** that automatically builds and tests the project on **Windows** and **Ubuntu**. The workflow ensures that all commits and pull requests maintain code quality and compatibility across platforms.  

## 📌 Key Technologies  
- **C++ 23** (Concepts, smart pointers, structured bindings)  
- **CMake** (Cross-platform build system)  
- **vcpkg** (Dependency management)  
- **Software Design Patterns** (Dependency Injection, etc.) 
- **GitHub Actions** (Automated CI testing)  
- **Unit Testing** (Google Test, Catch2) 
- **CMakePresets** (Simplified build process)

## 🤝 Contributing  
Contributions are welcome! If you’d like to improve the project, follow these steps:  
1. Fork the repository  
2. Create a new branch (`git checkout -b feature-xyz`)  
3. Commit your changes (`git commit -m "Add feature XYZ"`)  
4. Push the branch (`git push origin feature-xyz`)  
5. Open a **Pull Request**  

## 📜 License  
This project is licensed under the **MIT License** – feel free to use and modify it!  


