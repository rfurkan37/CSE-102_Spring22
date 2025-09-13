# Assignment 1: Customer Account Management System

## 📋 Problem Description

This assignment implements a customer account management system that handles customer data operations including account creation, balance management, and file I/O operations.

## 🎯 Objectives

- Learn basic file I/O operations in C
- Understand structure usage for data organization
- Implement modular programming with separate header and source files
- Practice data validation and error handling

## 📁 Files Structure

```
hw1/
├── main.c              # Main program entry point
├── utils.c             # Utility functions implementation
├── utils.h             # Function declarations and structures
├── customeraccount.txt # Customer data file
└── makefile           # Build configuration
```

## 🚀 How to Compile and Run

### Using Makefile (Recommended):
```bash
make
./main.out
```

### Manual Compilation:
```bash
gcc -o main main.c utils.c
./main
```

## 🔧 Program Features

### Part 1: Data Processing
- Customer account initialization
- Basic account operations
- Data validation

### Part 2: File Operations
- Reading customer data from `customeraccount.txt`
- Processing account information
- Writing results to output files

## 📊 Input Data Format

The `customeraccount.txt` file contains customer information in a structured format:
- Customer ID
- Customer Name
- Account Balance
- Account Type

## 🎯 Learning Outcomes

After completing this assignment, you will understand:
- ✅ File I/O operations (`fopen`, `fread`, `fwrite`, `fclose`)
- ✅ Structure definition and usage
- ✅ Modular programming with header files
- ✅ Data validation techniques
- ✅ Error handling in file operations

## 🔍 Key Functions

| Function | Purpose | Location |
|----------|---------|----------|
| `part1recep()` | Handles first part of assignment | utils.c |
| `part2recep()` | Handles second part of assignment | utils.c |
| `main()` | Program entry point | main.c |

## 🧪 Testing

Test the program with different scenarios:
1. Valid customer data
2. Invalid file paths
3. Corrupted data files
4. Empty input files

## 💡 Implementation Notes

- Uses modular design with separate utility functions
- Implements proper error checking for file operations
- Follows C coding standards and conventions
- Includes comprehensive data validation

## 🎓 Academic Context

**Course:** CSE 102 - Computer Programming  
**Student:** Recep Furkan Akın (210104004042)  
**Semester:** Spring 2022  
**Assignment:** Homework 1

---

*This assignment demonstrates fundamental C programming concepts including file operations, structures, and modular programming design.*