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
* Multiplication (`*`)
* Division (`/`)
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
│   ├── utils.c
│   └── print.c
│
├── test/
│
├── Makefile
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

# Modules

## main.c

* Program entry point
* Validates command-line arguments
* Calls parser
* Executes requested arithmetic operation
* Displays result
* Releases allocated memory

---

## parser.c

Responsible for:

* Validating operands
* Parsing command-line arguments
* Creating linked lists from strings

---

## list.c

Implements linked list operations:

* Insert at front
* Insert at end
* Delete list
* Traverse list
* Print list
* Compute length

---

## addition.c

Implements addition using carry propagation.

---

## subtraction.c

Implements subtraction using borrow propagation.

---

## multiplication.c

Implements multiplication using the traditional grade-school algorithm.

---

## division.c

Implements integer division using long division principles.

---

## utils.c

Contains helper routines such as:

* Compare numbers
* Remove leading zeros
* Copy linked lists
* Reverse traversal helpers
* Check for zero

---

## print.c

Responsible for formatting and displaying the final result.

---

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

# Future Improvements

* Signed integer support
* Modulus operator (`%`)
* Exponentiation
* Factorial
* Parentheses support
* Expression parser
* Scientific notation
* Hexadecimal and binary support
* Interactive shell mode
* Decimal (floating-point) support
* Performance optimizations

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
✔ Write Makefile
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
✔ Implement division
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