Task 04 – Specifying a Class with an Array Inside It

## Objective:

To implement a Savings Account Mini-Statement using a C++ class containing a fixed-size array and understand encapsulation, member functions and transaction management.

## Problem Statement:

Design a Savings Account class that stores account details, balance and the last 10 transactions. When a new transaction is added after reaching the capacity, the oldest transaction must be discarded.

## Concepts Used:

- Classes and Objects
- Encapsulation
- Private and Public Access Specifiers
- Array Inside a Class
- Inline Member Functions
- Scope Resolution Operator
- Constructors
- Circular Buffer
- Fixed-Size Arrays

## Algorithm:

1. Start the program.
2. Define a SavingsAccount class.
3. Declare account number, balance and transaction array as private members.
4. Initialize account details using a constructor.
5. Implement deposit() and withdraw() functions.
6. Record each valid transaction in the array.
7. Use a circular index to manage the latest 10 transactions.
8. When the array is full, overwrite the oldest transaction.
9. Display the account details and mini-statement.
10. Stop the program.

## Program:

Q4_SavingsAccount.cpp

## Compiler:

GCC 16.2.0

## Compilation:

g++ -std=c++17 -Wall -Wextra Q4_SavingsAccount.cpp -o q4

## Execution:

.\q4.exe

## Transaction Management:

The program uses a circular buffer to store the latest 10 transactions. When the 11th transaction is added, the oldest transaction is overwritten.

## Handling the 11th Transaction:

A shifting approach moves the remaining 9 transactions one position to the left, requiring O(n) time for each insertion after the array becomes full.

The circular buffer updates the starting index and overwrites the oldest transaction in O(1) time without shifting elements.

## Design for 50 Transactions:

For storing the latest 50 transactions, the circular buffer is still suitable because it supports constant-time insertion and uses fixed memory. Only the capacity needs to be changed from 10 to 50.

## Alternative Approach:

A std::deque can also be used with push_back() and pop_front() to maintain a fixed number of recent transactions. However, the circular buffer provides direct control over storage and avoids shifting elements.

## Complexity Analysis:

- Deposit: O(1) time
- Withdrawal: O(1) time
- Adding a transaction: O(1) time
- Displaying the mini-statement: O(n) time
- Extra storage: O(n), where n is the transaction capacity

## Conclusion:

The program successfully implements a Savings Account Mini-Statement using a class and an internal array. The circular buffer retains the latest 10 transactions and discards the oldest transaction when the capacity is exceeded.
