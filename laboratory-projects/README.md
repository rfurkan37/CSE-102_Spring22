# 🔬 Laboratory Projects

This directory contains all laboratory exercises and projects completed during CSE 102 - Computer Programming course lab sessions in Spring 2022.

## 📋 Lab Session Overview

| Lab | Title | Focus Area | Complexity | Status |
|-----|-------|------------|------------|---------|
| **Lab 2** | Basic Programming Foundations | Fundamental C Concepts | Beginner | ✅ Complete |
| **Lab 3** | Control Structures | Loops, Conditionals | Beginner | ✅ Complete |
| **Lab 4** | Functions & Modular Design | Function Implementation | Intermediate | ✅ Complete |
| **Lab 5** | Arrays & Data Processing | Array Manipulation | Intermediate | ✅ Complete |
| **Lab 6** | Advanced Data Handling | Complex Data Operations | Intermediate | ✅ Complete |
| **Lab 7** | File Operations | I/O Programming | Intermediate | ✅ Complete |
| **Lab 8** | String Processing | Text Manipulation | Intermediate | ✅ Complete |
| **Lab 9** | Memory Management | Dynamic Allocation | Advanced | ✅ Complete |
| **Lab 10** | Data Structures | Advanced Data Handling | Advanced | ✅ Complete |
| **Lab 11** | System Programming | Advanced Concepts | Advanced | ✅ Complete |
| **Lab 13** | File Processing Systems | Complex File Operations | Advanced | ✅ Complete |
| **Final Lab** | Comprehensive Project | Binary File Operations | Expert | ✅ Complete |

## 🎯 Learning Objectives

### Core Programming Skills
- **Syntax Mastery:** C language fundamentals and best practices
- **Problem Solving:** Algorithmic thinking and solution design
- **Code Organization:** Modular programming and clean code principles
- **Debugging:** Error identification and resolution techniques

### Advanced Concepts
- **Memory Management:** Dynamic allocation and deallocation
- **File Operations:** Text and binary file handling
- **Data Structures:** Implementation of complex data types
- **System Integration:** Understanding program execution environment

## 🚀 Quick Start Guide

### Prerequisites
```bash
# Ensure you have GCC compiler installed
gcc --version

# Make utility (for labs with makefiles)
make --version
```

### Running Lab Exercises

#### For Labs with Makefiles:
```bash
# Navigate to lab directory
cd lab2

# Compile using make
make

# Run the program
./main.out
```

#### For Labs without Makefiles:
```bash
# Manual compilation
gcc -Wall -Wextra -std=c99 -o lab_program main.c

# Execute
./lab_program
```

## 📚 Detailed Lab Descriptions

### Lab 2: Programming Foundations
- **File:** `main.c`
- **Topics:** Variables, basic I/O, simple calculations
- **Skills Developed:** Understanding C syntax, compilation process

### Lab 3: Control Structures
- **File:** `main.c`
- **Topics:** if-else statements, loops, logical operations
- **Skills Developed:** Program flow control, decision making

### Lab 4: Functions & Modularity
- **File:** `main.c`
- **Topics:** Function definition, parameters, return values
- **Skills Developed:** Code reusability, modular design

### Lab 5: Arrays & Data Processing
- **Files:** `main.c`, `makefile`
- **Topics:** Array declaration, initialization, manipulation
- **Skills Developed:** Data collection handling, iteration

### Lab 6: Advanced Data Operations
- **Files:** `main.c`, `makefile`
- **Topics:** Multi-dimensional arrays, complex data processing
- **Skills Developed:** Advanced data structure usage

### Lab 7: File I/O Programming
- **File:** `210104004042_recep_furkan_akın.c`
- **Topics:** File reading, writing, error handling
- **Skills Developed:** External data management, robust programming

### Lab 8: String Manipulation
- **File:** `210104004042_recep_furkan_akın.c`
- **Topics:** String functions, text processing, parsing
- **Skills Developed:** Text data handling, string algorithms

### Lab 9: Memory Management
- **Files:** `main.c`
- **Topics:** Dynamic memory allocation, pointers
- **Skills Developed:** Memory efficiency, pointer arithmetic

### Lab 10: Data Structures Implementation
- **File:** `210104004042.c`
- **Topics:** Structures, data organization
- **Skills Developed:** Custom data type creation

### Lab 11: Advanced System Programming
- **Files:** `main.c`
- **Topics:** System calls, advanced programming concepts
- **Skills Developed:** System-level programming understanding

### Lab 13: Complex File Systems
- **Files:** `210104004042.c`, `source.txt`, `makefile`
- **Topics:** File parsing, data extraction, processing pipelines
- **Skills Developed:** Complex file operations, data transformation

### Final Lab: Binary File Operations
- **Files:** `RECEP FURKAN AKIN 210104004042.c`, `Lab11_data.bin`
- **Topics:** Binary file handling, data serialization
- **Skills Developed:** Advanced file operations, binary data management

## 🛠️ Development Environment

### Recommended Setup
- **Compiler:** GCC with C99 standard
- **Editor:** Any text editor or IDE (VS Code, Code::Blocks, etc.)
- **Operating System:** Cross-platform compatible
- **Build Tools:** Make utility for automated compilation

### Compilation Standards
```bash
# Standard compilation flags used
gcc -Wall -Wextra -std=c99 -pedantic -o program source.c
```

## 📊 Lab Statistics

- **Total Lab Sessions:** 12 (Labs 2-13 + Final)
- **Completion Rate:** 100%
- **Programming Paradigms:** Procedural Programming
- **Code Quality:** Production-ready with proper error handling
- **Total Lines of Code:** ~1500+

## 🔧 Common Lab Challenges & Solutions

### Compilation Issues
```bash
# Missing header warnings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# Linking errors - ensure all source files are included
gcc -o program main.c utils.c
```

### Runtime Problems
- **File Access:** Ensure input files exist and have proper permissions
- **Memory Issues:** Always free dynamically allocated memory
- **Input Validation:** Check user input for validity

### Best Practices Applied
- Consistent code formatting and indentation
- Meaningful variable and function names
- Comprehensive error checking
- Memory leak prevention
- Proper documentation

## 🎓 Skills Progression

### Beginner Labs (2-4)
- Basic syntax and program structure
- Simple input/output operations
- Control flow understanding

### Intermediate Labs (5-8)
- Data structure manipulation
- File operations
- String processing
- Modular programming

### Advanced Labs (9-13, Final)
- Memory management
- Complex data structures
- System programming concepts
- Binary file operations

## 📁 File Organization

Each lab directory contains:
- **Source files (.c):** Main implementation
- **Header files (.h):** When applicable
- **Makefiles:** For automated compilation
- **Data files:** Input/test data
- **Executables:** Compiled programs

## 🏆 Achievement Summary

- ✅ **All Labs Completed:** Successfully finished all assigned lab exercises
- ✅ **Code Quality:** Maintained high standards throughout
- ✅ **Problem Solving:** Demonstrated progressive skill development
- ✅ **Best Practices:** Applied professional programming standards

---

**Student:** Recep Furkan Akın  
**Student ID:** 210104004042  
**Course:** CSE 102 - Computer Programming  
**Semester:** Spring 2022  
**Lab Instructor:** Course Lab Team