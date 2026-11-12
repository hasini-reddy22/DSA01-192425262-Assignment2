
# Task 03 – Default Arguments and Function Overloading

## Objective:

To demonstrate default arguments and function overloading in C++ using a Courier Charge Calculator and understand how ambiguity occurs during function overload resolution.

## Problem Statement:

Design a Courier Charge Calculator to calculate delivery charges based on parcel weight, express delivery and insurance options. Identify ambiguity in overloaded functions and redesign them using suitable default arguments and function overloading.

## Concepts Used:

- Default Arguments
- Function Overloading
- Function Overload Resolution
- Exact Match
- Type Promotion
- Type Conversion
- Structures and Functions
- Compile-Time Polymorphism

## Algorithm:

1. Start the program.
2. Define a Parcel structure.
3. Create an overloaded function to calculate charges using weight in kilograms.
4. Use default arguments for express delivery and insurance.
5. Create another overload to accept weight in grams.
6. Create an overload to accept a Parcel object.
7. Execute six different function calls.
8. Observe the overload selected by the compiler.
9. Display the courier charges.
10. Stop the program.

## Program:

Q3_DefaultArgumentsOverloading.cpp

## Compiler:

GCC 16.2.0

## Compilation:

g++ -std=c++17 -Wall -Wextra Q3_DefaultArgumentsOverloading.cpp -o q3

## Execution:

.\q3.exe

## Prediction and Observation:

The program tests six function calls, including charge(2) and charge(2.0f).

The integer argument selects the int overload, while the float argument is promoted to double. The double and Parcel arguments select their corresponding overloads.

## Explanation:

Function overloading allows multiple functions to have the same name with different parameter lists.

Default arguments provide predefined values when optional arguments are not supplied.

Ambiguity occurs when the compiler finds multiple equally suitable overloaded functions. It can be avoided by designing distinct parameter lists and using default arguments carefully.

The compiler selects an overloaded function at compile time using exact matching, type promotion and type conversion.

## Alternative Approach:

A Parcel structure can group weight, express delivery and insurance details into a single object. This makes the program easier to extend when additional parcel options are introduced.

## Complexity Analysis:

Courier charge calculation requires O(1) time and O(1) extra space for each function call. Function overload resolution takes place at compile time.

## Conclusion:

The program demonstrates default arguments and function overloading. It explains how ambiguity can occur and shows how suitable overloads can handle different input types successfully.
