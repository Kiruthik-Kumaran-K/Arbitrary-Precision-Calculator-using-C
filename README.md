# Arbitrary Precision Calculator (APC)

## Overview

The **Arbitrary Precision Calculator (APC)** is a command-line calculator written in **C** that performs arithmetic operations on integers of virtually unlimited size.

Unlike built-in C integer types (`int`, `long`, `long long`), which are limited by the machine architecture, this calculator represents numbers using a **Doubly Linked List (DLL)**. Each node stores a single decimal digit, allowing calculations on numbers containing thousands (or even millions) of digits.

This project is designed as a learning exercise to strengthen concepts in:

* Data Structures
* Dynamic Memory Allocation
* Modular Programming
* Command Line Argument Processing
* Software Design
* Memory Management
* Clean C Programming Practices

---

# Features

* Addition (`+`)
* Subtraction (`-`)
* Multiplication (`X`)
* Division (`/`) *(implemented using repeated subtraction)*
* Arbitrary precision integer support using a doubly linked list
* Unlimited number of digits
* Command-line interface
* Modular source code organization
* Memory-safe implementation
* Easy to extend with additional operations

---

# Project Objective

Implement an arbitrary precision integer calculator without relying on external libraries such as GMP.

The project demonstrates how large integers can be represented and manipulated using linked data structures.

---

# How It Works

Each decimal digit is stored in a node of a doubly linked list.

Example:

Number:

```
123456
```

Representation:

```
NULL

1 ⇄ 2 ⇄ 3 ⇄ 4 ⇄ 5 ⇄ 6

NULL
```

Advantages:

* Efficient traversal from both directions
* Simplifies carry and borrow operations
* No need to reverse numbers during arithmetic

---

# Project Structure

```
APC/
│
├── include/
│   └── apc.h
│
├── src/
│   ├── main.c
│   ├── parser.c
│   ├── list.c
│   ├── addition.c
│   ├── subtraction.c
│   ├── multiplication.c
│   ├── division.c
│   ├── compare.c
│   └── print.c
│   └── execute_operation.c
│   └── valiadtion.c
│
│
├── LICENSE
│
└── README.md
```

---

# Build Instructions

Compile the project using:

```bash
make
```

Clean generated files:

```bash
make clean
```

Rebuild:

```bash
make rebuild
```

---

# Usage

General syntax:

```bash
./apc <operand1> <operator> <operand2>
```

Examples:

Addition

```bash
./apc 12345678901234567890 + 98765432109876543210
```

Subtraction

```bash
./apc 1000000000000 - 999999999999
```

Multiplication

```bash
./apc 123456789 X 987654321
```

Division

```bash
./apc 999999999999 / 9
```

---

# Input Validation

The program validates:

* Number of command-line arguments
* Supported operators
* Numeric operands
* Invalid characters
* Leading zeros (handled appropriately)
* Division by zero
* Memory allocation failures

---

# Software Design

The application follows a modular architecture.

```
            main
              │
      Argument Validation
              │
          Parser Module
              │
      Create Linked Lists
              │
      Arithmetic Module
              │
        Result Linked List
              │
          Display Module
```

Each module has a single responsibility, making the code easier to understand, maintain, and test.

---

# Data Structure

```c
typedef struct node
{
    int digit;
    struct node *prev;
    struct node *next;
} Dlist;
```

Each node stores:

* One decimal digit
* Pointer to previous node
* Pointer to next node

---

## Modules

### main.c

Responsible for:

* Program entry point
* Validates command-line arguments
* Creates operand linked lists
* Calls execute_operation()
* Prints the final result
* Releases all allocated memory

---

### validation.c

Responsible for validating user input before any arithmetic operation.

Responsibilities:

* Validate the number of command-line arguments.
* Validate the arithmetic operator.
* Validate operand format.
* Ensure operands contain only decimal digits.
* Detect invalid operators.
* Return appropriate error codes for invalid input.

---

### parser.c

Responsible for:

* Converting operand strings into doubly linked lists.
* Creating linked-list representations of arbitrary precision integers.

---

### list.c

Implements fundamental doubly linked list operations:

* insert_first()
* insert_last()
* delete_list()

---

### compare.c

Responsible for comparing two arbitrary precision integers.

Responsibilities:

* Compute the length of operands.
* Compare operands based on length.
* Compare digits when lengths are equal.
* Return:
  * GREATER_THAN
  * LESS_THAN
  * EQUAL

Used by subtraction and division modules.

---

### addition.c

Implements arbitrary precision addition.

Responsibilities:

* Traverse operands from least significant digit.
* Perform digit-by-digit addition.
* Propagate carry.
* Store the result in a new linked list.

---

### subtraction.c

Implements arbitrary precision subtraction.

Responsibilities:

* Traverse operands from least significant digit.
* Perform borrow propagation.
* Remove leading zeros from the result.
* Return the difference as a linked list.

---

### multiplication.c

Implements arbitrary precision multiplication using the grade-school multiplication algorithm.

Responsibilities:

* Multiply one operand by a single digit.
* Generate partial products.
* Append positional zeros.
* Accumulate partial products using addition.
* Return the final product.

---

### division.c

Implements arbitrary precision integer division using the repeated subtraction algorithm.

Responsibilities:

* Check for division by zero.
* Repeatedly subtract the divisor from the dividend.
* Count the number of successful subtractions.
* Return the quotient as a linked list.

> **Note:** This implementation is functionally correct but not optimal for very large numbers. A long-division algorithm can be implemented in future versions for better performance.

---

### execute_operation.c

Acts as the arithmetic dispatcher.

Responsibilities:

* Select the requested arithmetic operation.
* Invoke:
  * Addition
  * Subtraction
  * Multiplication
  * Division
* Compare operands before subtraction.
* Handle negative subtraction results.
* Return the operation status to `main()`.

---

### print.c

Responsible for displaying the final result.

Responsibilities:

* Print the linked-list representation as an integer.
* Display negative sign when required.

# Development Process

The project follows a structured development approach.

1. Requirement Analysis
2. System Design
3. Data Structure Design
4. Module Implementation
5. Unit Testing
6. Integration Testing
7. Memory Leak Testing
8. Final Validation

---

# Learning Outcomes

This project reinforces:

* Doubly Linked Lists
* Dynamic Memory Allocation
* Pointer Manipulation
* Modular C Programming
* Header File Organization
* Command Line Arguments
* Error Handling
* Software Design Principles
* Testing and Debugging
* Memory Management

---

# License

This project is intended for educational purposes and may be modified or extended for personal learning.


✔ Create project structure
        ↓
✔ Write README
        ↓
✔ Write apc.h
        ↓
✔ Minimal main.c
        ↓
✔ Validate command-line arguments
        ↓
✔ Create linked list module
        ↓
✔ Convert string → linked list
        ↓
✔ Print linked list
        ↓
✔ Implement addition
        ↓
✔ Implement subtraction
        ↓
✔ Implement multiplication
        ↓
✔ Implement division (repeated subtraction)
        ↓
✔ Free all memory
        ↓
✔ Test edge cases




main()
   │
   ▼
validate_arguments()
   │
   ▼
create_operand_lists()
   │
   ▼
choose_operation()
   │
   ▼
addition/subtraction/
multiplication/division
   │
   ▼
print_result()
   │
   ▼
delete_lists()