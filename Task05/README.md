
# Task 05 – Static Members and Arrays of Objects

## Objective

To demonstrate static data members, static member functions and arrays of objects in C++ by developing a College Bus Seat Ticket System.

## Problem Statement

Design a bus ticket system with a fixed seating capacity. Each BusTicket object receives the next available seat number. When the capacity is reached, additional passengers are placed on the waiting list.

## Concepts Used

- Static Data Members
- Static Member Functions
- Arrays of Objects
- Constructors
- Object Initialization
- Scope Resolution Operator
- Class and Object
- Encapsulation

## Algorithm

1. Start the program.
2. Define a BusTicket class.
3. Declare static members to store issued ticket count and bus capacity.
4. Define a constructor to assign the next available seat number.
5. If the capacity is reached, place the passenger on the waiting list.
6. Define a static function to return the number of issued tickets.
7. Create an array of ticket objects.
8. Display the seat numbers and waiting-list status.
9. Call the ticket creation function again to verify that the static count persists.
10. Demonstrate the Token example and display its output.
11. Stop the program.

## Program

Q5_StaticMembersBusTicket.cpp

## Compiler

GCC 16.2.0

## Compilation

g++ -std=c++17 -Wall -Wextra Q5_StaticMembersBusTicket.cpp -o q5

## Execution

.\q5.exe

## Expected Token Output

101 103 104 4

The static variable starts at 100. The constructor executes four times, so the generated IDs are 101, 102, 103 and 104. The issued() function returns 4.

## Static Member Explanation

A static data member is shared by all objects of a class. It is defined outside the class using the scope resolution operator.

A static member function can be called using the class name. It cannot directly access non-static members because it does not have a this pointer.

## Array of Objects

An array of BusTicket objects is used to create multiple passenger tickets. Each object invokes the constructor and receives a seat number if capacity is available.

## Static Count Persistence

The ticket creation function is called twice. The static issued count remains unchanged between function calls because it belongs to the class rather than an individual object.

## Alternative Approach

A separate TicketOffice class could manage seat allocation instead of using a static counter inside BusTicket. This approach is useful when multiple buses need independent seat counts and capacities.

## Complexity Analysis

- Ticket creation: O(1) time per object
- Seat allocation: O(1) time per object
- Displaying an array of n tickets: O(n) time
- Static counter storage: O(1) extra space

## Conclusion

The program demonstrates static data members, static member functions and arrays of objects. It successfully assigns seats according to the fixed bus capacity, places additional passengers on the waiting list and verifies that static counts persist across function calls.
