#include <iostream>
#include <vector>
using namespace std;

// Return by reference
int& highestMark(int marks[], int size)
{
    int highest = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highest])
            highest = i;
    }

    return marks[highest];
}

// Return by const reference
const int& highestMarkConst(const int marks[], int size)
{
    int highest = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highest])
            highest = i;
    }

    return marks[highest];
}

// Return by copy
int highestMarkCopy(const int marks[], int size)
{
    int highest = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highest])
            highest = i;
    }

    return marks[highest];
}

// Dangerous function: returning reference to local variable
int& dangerousFunction()
{
    int local = 50;
    return local;  // Dangling reference: undefined behaviour
}

int main()
{
    int marks[] = {75, 88, 92, 81, 85};
    int size = 5;

    cout << "Original Marks: ";
    for (int i = 0; i < size; i++)
        cout << marks[i] << " ";

    cout << "\n\nHighest Mark: " << highestMark(marks, size);

    // Modify array element using returned reference
    highestMark(marks, size) += 2;

    cout << "\nAfter Moderation (+2): ";
    for (int i = 0; i < size; i++)
        cout << marks[i] << " ";

    cout << "\n\nHighest Mark using const reference: "
         << highestMarkConst(marks, size);

    cout << "\nHighest Mark using copy: "
         << highestMarkCopy(marks, size);

    // Vector growth demonstration
    vector<int> scores = {70, 80, 90};

    int* oldAddress = &scores[0];
    size_t oldCapacity = scores.capacity();

    scores.reserve(oldCapacity + 100);

    cout << "\n\nVector capacity before growth: " << oldCapacity;
    cout << "\nVector capacity after growth: " << scores.capacity();

    cout << "\nA reference to an old vector element may now be invalid.";

    // Alternative: return an index
    int index = 0;
    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[index])
            index = i;
    }

    cout << "\n\nHighest Mark Index: " << index;
    cout << "\nHighest Mark using index: " << marks[index];

    // Pointer alternative
    int* ptr = &marks[index];
    cout << "\nHighest Mark using pointer: " << *ptr;

    return 0;
}