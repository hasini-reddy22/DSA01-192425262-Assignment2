#include <iostream>
using namespace std;

// Call by value
void concessionByValue(double fee, int percent)
{
    fee = fee - (fee * percent / 100);
    cout << "Inside call by value: " << fee << endl;
}

// Call by reference
void concessionByReference(double &fee, int percent)
{
    fee = fee - (fee * percent / 100);
}

// Call by pointer
void concessionByPointer(double *fee, int percent)
{
    *fee = *fee - (*fee * percent / 100);
}

int main()
{
    double fee1 = 45000;
    double fee2 = 45000;
    double fee3 = 45000;

    cout << "Original Hostel Fee: 45000" << endl;

    concessionByValue(fee1, 10);
    cout << "After call by value: " << fee1 << endl;

    concessionByReference(fee2, 15);
    cout << "After call by reference: " << fee2 << endl;

    concessionByPointer(&fee3, 25);
    cout << "After call by pointer: " << fee3 << endl;

    return 0;
}
