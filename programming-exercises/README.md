# 💡 Programming Exercises

This directory contains additional programming practice exercises, algorithm implementations, and problem-solving challenges beyond the regular coursework.

## 📁 Directory Structure

```
programming-exercises/
├── binary_search/          # Binary Search Algorithm Implementation
├── exam/                   # Exam Preparation Materials  
├── itu_gecis_hesaplama/    # ITU GPA Calculation Tool
├── old_exercises/          # Foundational Programming Exercises
├── recursion_examples/     # Recursive Algorithm Implementations
├── roman_to_integer/       # Roman Numeral Converter
├── two_sum/                # Two Sum Problem (LeetCode Style)
└── valid_parentheses/      # Parentheses Validation Algorithm
```

## 🎯 Exercise Categories

### 🔍 Algorithm Implementations

#### Binary Search (`binary_search/`)
- **File:** `binary_search.c`
- **Algorithm:** Efficient searching in sorted arrays
- **Time Complexity:** O(log n)
- **Learning Focus:** Divide and conquer strategy

#### Recursion Examples (`recursion_examples/`)
- **Files:** `factorial.c`, `fibonacci.c`, `recursion_sorting.c`
- **Concepts:** Recursive problem solving, base cases, stack management
- **Algorithms Covered:**
  - Factorial calculation
  - Fibonacci sequence generation
  - Recursive sorting algorithms

### 🧩 Problem Solving Challenges

#### Two Sum Problem (`two_sum/`)
- **File:** `main.c`
- **Problem Type:** Array manipulation, hash table concepts
- **Difficulty:** Easy-Medium
- **Origin:** LeetCode-style interview question

#### Valid Parentheses (`valid_parentheses/`)
- **File:** `main.c`
- **Problem Type:** Stack-based validation
- **Difficulty:** Easy
- **Concepts:** Stack data structure, string parsing

#### Roman to Integer (`roman_to_integer/`)
- **File:** `main.c`
- **Problem Type:** String processing, conversion algorithms
- **Difficulty:** Easy-Medium
- **Learning Focus:** Pattern recognition, edge case handling

### 📚 Foundational Exercises (`old_exercises/`)

Collection of fundamental programming exercises:

| Exercise | File | Focus Area |
|----------|------|------------|
| **Hello World** | `hello world.c` | Basic syntax, compilation |
| **Bilgi Yarışması** | `bilgiYarismasi.c` | Quiz game logic |
| **Çarpım Tablosu** | `çarpımtable.c` | Nested loops, multiplication |
| **Döngü Örnekleri** | `döngü.c` | Loop constructs |
| **Faktöriyel** | `faktöriyel.c` | Mathematical computation |
| **Fonksiyonlu Üs** | `fonklu üs hesaplama.c` | Power calculation with functions |
| **Pointer Örnekleri** | `pointer1.c`, `pointer2.c` | Memory addressing, indirection |
| **Tek-Çift Kontrolü** | `tek çift fonklu.c` | Even/odd checking with functions |
| **Toplam Hesaplama** | `toplam fonklu.c`, `toplamke.c` | Summation algorithms |
| **HackerRank Exercise** | `hacherrank ex 3.c` | Competitive programming practice |

### 🎓 Academic Tools

#### ITU GPA Calculator (`itu_gecis_hesaplama/`)
- **File:** `main.c`
- **Purpose:** Calculate GPA according to ITU grading system
- **Features:** Grade conversion, credit calculation
- **Practical Application:** Real-world utility tool

#### Exam Preparation (`exam/`)
- **File:** `1.c`
- **Purpose:** Practice problems for exam preparation
- **Focus:** Common exam patterns and question types

## 🚀 Getting Started

### Prerequisites
```bash
# GCC Compiler
gcc --version

# Basic C development environment
```

### Running Exercises

#### Standard Compilation:
```bash
# Navigate to exercise directory
cd binary_search

# Compile
gcc -o binary_search binary_search.c

# Run
./binary_search
```

#### Advanced Compilation (with debugging):
```bash
# Compile with debug flags
gcc -Wall -Wextra -g -std=c99 -o program source.c

# Run with debugging
gdb ./program
```

## 📊 Exercise Statistics

- **Total Exercise Categories:** 8
- **Algorithm Implementations:** 4+
- **Problem Solving Challenges:** 3
- **Foundational Exercises:** 10+
- **Difficulty Range:** Beginner to Intermediate
- **Code Quality:** Educational with comments

## 🎯 Learning Outcomes

### Algorithmic Thinking
- ✅ **Search Algorithms:** Binary search implementation and optimization
- ✅ **Recursion:** Understanding recursive problem decomposition
- ✅ **Sorting:** Various sorting algorithm approaches
- ✅ **Pattern Recognition:** Identifying common algorithmic patterns

### Problem Solving Skills
- ✅ **Interview Preparation:** LeetCode-style problem solutions
- ✅ **Edge Case Handling:** Robust input validation
- ✅ **Optimization:** Time and space complexity considerations
- ✅ **Code Reusability:** Modular function design

### Programming Fundamentals
- ✅ **Syntax Mastery:** Advanced C language features
- ✅ **Memory Management:** Pointer usage and memory allocation
- ✅ **Control Structures:** Complex loop and conditional logic
- ✅ **Function Design:** Parameter passing and return strategies

## 🔧 Development Best Practices

### Code Organization
```c
// Standard header structure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int binarySearch(int arr[], int size, int target);

// Main function
int main() {
    // Implementation
    return 0;
}

// Function definitions
int binarySearch(int arr[], int size, int target) {
    // Algorithm implementation
}
```

### Error Handling
- Input validation for all user inputs
- Boundary checking for array operations
- Memory allocation verification
- File operation error checking

### Performance Considerations
- Algorithm complexity analysis
- Memory usage optimization
- Efficient data structure selection
- Code profiling and benchmarking

## 📈 Skill Progression Path

### Beginner Level
1. **Basic Syntax** (`old_exercises/hello world.c`)
2. **Control Structures** (`old_exercises/döngü.c`)
3. **Functions** (`old_exercises/toplam fonklu.c`)

### Intermediate Level
1. **Recursion** (`recursion_examples/`)
2. **Algorithm Implementation** (`binary_search/`)
3. **Problem Solving** (`two_sum/`, `valid_parentheses/`)

### Advanced Level
1. **Complex Algorithms** (`recursion_examples/recursion_sorting.c`)
2. **Real-world Applications** (`itu_gecis_hesaplama/`)
3. **Competitive Programming** (`exam/`)

## 🏆 Exercise Highlights

### Most Challenging
- **Recursive Sorting:** Complex algorithm implementation
- **Binary Search:** Efficient search strategy
- **Roman to Integer:** Pattern recognition and conversion logic

### Most Practical
- **ITU GPA Calculator:** Real-world utility
- **Valid Parentheses:** Common interview question
- **Two Sum Problem:** Algorithm interview staple

### Most Educational
- **Recursion Examples:** Understanding recursive thinking
- **Pointer Exercises:** Memory management concepts
- **Old Exercises Collection:** Fundamental skill building

## 🤝 Usage Guidelines

### For Learning
- Start with `old_exercises/` for foundational concepts
- Progress to `recursion_examples/` for advanced thinking
- Practice with LeetCode-style problems for interview prep

### For Review
- Use as reference for algorithm implementations
- Compare different solution approaches
- Analyze time and space complexity improvements

### For Portfolio
- Demonstrates algorithmic thinking capabilities
- Shows progression from basic to advanced concepts
- Includes practical problem-solving examples

---

**Student:** Recep Furkan Akın  
**Student ID:** 210104004042  
**Purpose:** Supplementary programming practice and skill development  
**Level:** Beginner to Intermediate C Programming