

# C++ Module 02 Project README

## Project Overview

This C++ project is part of Module 02 at Code 42 school, focusing on the implementation of a Fixed-point number class in Orthodox Canonical Form. The project covers key concepts such as ad-hoc polymorphism, operator overloading, and class design. It consists of three exercises, progressively building on each other to enhance the functionality of the Fixed-point class.

## Table of Contents

- [Subject Overview](#subject-overview)
- [Building and Running](#building-and-running)
- [Testing](#testing)
- [Exercise Details](#exercise-details)
  - [Exercise 00: My First Class in Orthodox Canonical Form](#exercise-00-my-first-class-in-orthodox-canonical-form)
  - [Exercise 01: Towards a more useful fixed-point number class](#exercise-01-towards-a-more-useful-fixed-point-number-class)
  - [Exercise 02: Now we're talking](#exercise-02-now-were-talking)
  - [Exercise 03: BSP (Binary Space Partitioning)](#exercise-03-bsp-binary-space-partitioning)

## Subject Overview

The project revolves around creating a Fixed-point number class that adheres to the Orthodox Canonical Form. Each exercise introduces new features, starting from basic class structure to more advanced functionality like arithmetic operations, comparisons, and Binary Space Partitioning.

## Building and Running

To build and run the project, navigate to each exercise directory using the provided Makefiles:

```bash
cd ex00
make
./a.out
```

Repeat this process for each exercise (ex01, ex02, ex03).

## Testing

Testing is an integral part of this project. Each exercise includes a `main` function that tests the implemented features. Run the test functions to ensure the correctness of your implementation:

```bash
./a.out
```

## Exercise Details

### Exercise 00: My First Class in Orthodox Canonical Form

- **Objective**: Create a basic Fixed-point number class adhering to Orthodox Canonical Form.
- **Key Features**:
  - Default constructor, copy constructor, copy assignment, destructor.
  - Private members: integer value, static constant for fractional bits.
  - Public members: getRawBits, setRawBits.
  - Follow Orthodox Canonical Form.

### Exercise 01: Towards a more useful fixed-point number class

- **Objective**: Enhance the Fixed-point class with additional constructors and conversion functions.
- **Key Features**:
  - Constructors for integer and floating-point parameters.
  - Member functions: toFloat, toInt.
  - Overload insertion (<<) operator.
  - Implement proper conversions and display functionality.

### Exercise 02: Now we're talking

- **Objective**: Overload various operators for the Fixed-point class.
- **Key Features**:
  - Comparison operators: >, <, >=, <=, ==, !=.
  - Arithmetic operators: +, -, *, /.
  - Increment/decrement operators: ++, --.
  - Static member functions: min, max for fixed-point numbers.
  - Test the implemented features.

### Exercise 03: BSP (Binary Space Partitioning)

- **Objective**: Implement a function to check if a point is inside a triangle using Binary Space Partitioning.
![Screenshot from 2023-12-28 15-15-03](https://github.com/LuisBalsa/CPP02/assets/81270660/d50afe78-fce6-4469-875a-daec3cc7fe50)
- **Key Features**:
  - Create a Point class for 2D points in Orthodox Canonical Form.
  - Function: bsp - checks if a point is inside a triangle.
  - Testing the Barycentric coordinate system.

Feel free to explore the source code in each exercise directory for a detailed understanding of the implementation for each objective.
