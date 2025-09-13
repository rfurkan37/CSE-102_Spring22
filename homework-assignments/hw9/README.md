# Assignment 9: Loan Management System

## 📋 Problem Description

This assignment implements a comprehensive loan management system for a bank, handling customer information, multiple loan types, and complex financial calculations using advanced C programming concepts.

## 🎯 Objectives

- Implement complex data structures using unions and structures
- Handle multiple customer accounts with various loan types
- Perform financial calculations and interest computations
- Demonstrate advanced file processing capabilities
- Practice recursive programming techniques

## 📁 Files Structure

```
hw9/
├── main.c      # Complete loan management implementation
├── loans.txt   # Loan data input file
└── makefile    # Build configuration
```

## 🚀 How to Compile and Run

### Using Makefile (Recommended):
```bash
make
./main.out
```

### Manual Compilation:
```bash
gcc -o loan_system main.c
./loan_system
```

## 🏗️ Data Structures

### Union Person
```c
union Person {
    char name[50];
    char address[50];
    int phone;
};
```

### Union Loan
```c
union Loan {
    float arr[3];  // Stores loan amount, interest rate, duration
};
```

### Structure BankAccount
```c
struct BankAccount {
    union Person Customer;
    union Loan Loans[3];   // Up to 3 loans per customer
};
```

## 🔧 Key Features

### Customer Management
- Store customer personal information
- Handle multiple customers (up to 50)
- Manage customer identification and contact details

### Loan Processing
- Support multiple loan types per customer
- Calculate loan payments and interest
- Process loan applications and approvals
- Generate loan reports and summaries

### Financial Calculations
- **Recursive Power Function:** `artificialPower()` for compound interest
- Interest rate calculations
- Payment schedule generation
- Loan balance tracking

## 📊 Input Data Format

The `loans.txt` file contains:
- Customer information (name, address, phone)
- Loan details (amount, interest rate, duration)
- Loan type specifications
- Payment history data

## 💰 Loan Types Supported

1. **Personal Loans:** Short-term, higher interest
2. **Home Loans:** Long-term, lower interest, collateral-based
3. **Auto Loans:** Medium-term, asset-backed financing

## 🧮 Mathematical Operations

### Power Calculation (Recursive)
```c
float artificialPower(float base, int power) {
    if (power != 0)
        return base * artificialPower(base, power - 1);
    else
        return 1;
}
```

### Interest Calculations
- Compound interest using recursive power function
- Monthly payment calculations
- Total payment amount determination
- Interest vs. principal breakdown

## 🔍 Key Functions

| Function | Purpose | Complexity |
|----------|---------|------------|
| `artificialPower()` | Recursive power calculation | O(n) |
| `loadCustomerData()` | Read customer data from file | O(n) |
| `calculateLoanPayment()` | Compute monthly payments | O(1) |
| `generateLoanReport()` | Create detailed loan reports | O(n) |
| `processLoanApplication()` | Handle new loan requests | O(1) |

## 🎯 Learning Outcomes

After completing this assignment, you will master:
- ✅ **Advanced Data Structures:** Unions and nested structures
- ✅ **Memory Management:** Efficient data organization
- ✅ **Recursive Programming:** Mathematical computations using recursion
- ✅ **File Processing:** Complex data input/output operations
- ✅ **Financial Algorithms:** Real-world banking calculations
- ✅ **Error Handling:** Robust input validation and error management

## 🧪 Testing Scenarios

### Valid Operations
1. Load customer data from file
2. Calculate loan payments for different loan types
3. Generate comprehensive loan reports
4. Process multiple loans per customer

### Edge Cases
1. Zero loan amount handling
2. Invalid interest rates
3. Corrupted input data
4. Maximum customer limit reached

### Error Handling
- File not found scenarios
- Invalid data format handling
- Memory allocation failures
- Mathematical operation errors

## 💡 Implementation Highlights

### Advanced Features
- **Union Usage:** Efficient memory utilization for customer data
- **Recursive Mathematics:** Custom power function implementation
- **Complex File I/O:** Multi-format data processing
- **Modular Design:** Well-organized function structure

### Performance Considerations
- Optimized data structures for fast access
- Efficient recursive algorithms
- Minimal memory footprint
- Fast file processing capabilities

## 🏆 Real-World Applications

This loan management system demonstrates:
- Banking software development principles
- Financial calculation accuracy
- Customer data management
- Regulatory compliance considerations
- Scalable system architecture

## 📈 Complexity Analysis

- **Time Complexity:** O(n) for most operations, O(n log n) for sorting
- **Space Complexity:** O(n) for customer storage
- **Recursive Depth:** O(power) for interest calculations

## 🎓 Academic Context

**Course:** CSE 102 - Computer Programming  
**Student:** Recep Furkan Akın (210104004042)  
**Semester:** Spring 2022  
**Assignment:** Homework 9 - Advanced Data Structures

**Key Concepts Demonstrated:**
- Union and structure integration
- Recursive algorithm implementation
- Complex file processing
- Real-world application development
- Financial mathematics programming

---

*This assignment represents the culmination of advanced C programming concepts, demonstrating practical application development skills in a real-world banking scenario.*