
# Task 06 – Friend Functions and Inline Functions

## Objective:

To demonstrate friend functions and inline functions in C++ by developing a Train Journey Planner that calculates the time difference between two times and determines which time is earlier.

## Problem Statement:

Design a Time class that stores hours and minutes as private data members. Use friend functions to calculate the difference between two times and identify the earlier time. Compare inline and non-inline function performance.

## Concepts Used:

- Friend Functions
- Inline Functions
- Classes and Objects
- Private Data Members
- Encapsulation
- Function Calls
- Scope and Access Control
- Chrono Library
- Performance Measurement

## Algorithm:

1. Start the program.
2. Define a Time class with private hours and minutes.
3. Declare minutesBetween() and earlier() as friend functions.
4. Implement minutesBetween() to calculate the absolute difference in minutes.
5. Implement earlier() to identify the earlier time.
6. Test departure at 09:45 and arrival at 13:10.
7. Test times around noon and identical times.
8. Define inline and non-inline square functions.
9. Execute each function 10 million times.
10. Measure execution time using the chrono library.
11. Display the results.
12. Stop the program.

## Program:

Q6_FriendInlineTime.cpp

## Compiler:

GCC 16.2.0

## Compilation Without Optimization (-O0):

g++ -std=c++17 -O0 -Wall -Wextra Q6_FriendInlineTime.cpp -o q6_O0

## Execution:

.\q6_O0.exe

## Compilation With Optimization (-O2):

g++ -std=c++17 -O2 -Wall -Wextra Q6_FriendInlineTime.cpp -o q6_O2

## Execution:

.\q6_O2.exe

## Expected Functional Results:

- Minutes between 09:45 and 13:10: 205
- Minutes between 11:59 and 12:01: 2
- Minutes between identical times: 0
- The earlier() function returns true for 09:45 compared with 13:10.
- The earlier() function returns false for identical times.

## Friend Function Explanation:

A friend function is not a member of the class, but it can access the private and protected members of that class when declared using the friend keyword.

Friend functions are called like normal functions. They can access private data directly, whereas ordinary non-member functions cannot.

## Inline Function Explanation:

An inline function suggests that the compiler may replace a function call with the function body to reduce function-call overhead. The compiler is not required to follow this suggestion.

The program compares inline and non-inline function execution times using 10 million iterations at -O0 and -O2 optimization levels.

## Alternative Approach:

The Time class could provide public getter functions and ordinary member functions instead of friend functions. This improves encapsulation by controlling access to private data through the class interface.

For a production design, member functions or getters are generally preferable unless a non-member operation genuinely needs friend access.

## Complexity Analysis:

- minutesBetween(): O(1) time and O(1) extra space.
- earlier(): O(1) time and O(1) extra space.
- Performance benchmark: O(n) time for n function calls and O(1) extra space.

## Performance Observation:

Record the actual inline and non-inline execution times at both optimization levels (-O0 and -O2) after running the program.

The compiler may optimize ordinary functions as well, so inline functions are not guaranteed to be faster in every test.

## Conclusion:

The program demonstrates friend functions for accessing private class data, inline functions, time comparison and performance measurement. It also compares alternative approaches that provide better encapsulation.
