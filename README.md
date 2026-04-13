# TADS Person CRUD Project

## Creator
**Arthur Gabriel Teotonio Stellato**  
[GitHub](https://github.com/TADS-Person)

---

## 📌 About
This project aims to review the C programming language and better understand data structures.

---

### ⚙️ Features:
- Data registration (Create)
- Information visualization (Read)
- Record updating (Update)
- Data deletion (Delete)

### 🎯 Objective:
- Learn programming logic  
- Introduction to Struct (C)
- Data structure

- # C Project - VS Code Setup Guide

This repository contains a C project developed using Visual Studio Code. Follow the instructions below to configure your environment and run the code successfully.

---

## 🚀 Prerequisites

Before you begin, ensure you have the following installed on your machine:

1.  **C Compiler:**
    * **Windows:** [MSYS2](https://www.msys2.org/) (Install the MinGW-w64 toolchain).
    * **Linux:** `sudo apt install build-essential`
    * **macOS:** `xcode-select --install`
2.  **Visual Studio Code**
3.  **C/C++ Extension:** Install the official extension by Microsoft from the VS Code Marketplace.

> **Note for Windows users:** You **must** add the compiler's `bin` folder path (e.g., `C:\msys64\ucrt64\bin`) to your system's **Environment Variables (PATH)** for the terminal to recognize the `gcc` command.

---

## 🛠️ VS Code Configuration

1. Open the project folder in VS Code: `File > Open Folder`.
2. Open your `.c` file.
3. To enable IntelliSense (code completion), VS Code might ask to configure the compiler path. You can do this manually by pressing `Ctrl+Shift+P` and searching for `C/C++: Edit Configurations (UI)`.

---

## 🏃 How to Run

### Via Terminal (Recommended)
Open the integrated terminal in VS Code (`Ctrl + ` `) and run:

1. **Compile:**
   ```bash
   gcc main.c -o program
