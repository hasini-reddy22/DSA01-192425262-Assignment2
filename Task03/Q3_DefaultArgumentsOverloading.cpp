
#include <iostream>
#include <iomanip>
using namespace std;

// Parcel structure
struct Parcel
{
    double weightKg;
    bool express;
    bool insured;
};

/*
Problematic overloaded functions:

double charge(double weight);
double charge(double weight, bool express);
double charge(double weight, bool express = false,
              bool insured = false);

These declarations can cause ambiguity for calls
such as charge(2.0) and charge(2.0, true).
*/

// Overload 1: Weight in kilograms with default arguments
double charge(double weightKg, bool express = false,
              bool insured = false)
{
    double amount = 50 + (weightKg * 20);

    if (express)
        amount += 30;

    if (insured)
        amount += 15;

    return amount;
}

// Overload 2: Weight in grams
double charge(int weightGrams)
{
    double weightKg = weightGrams / 1000.0;
    return 50 + (weightKg * 20);
}

// Overload 3: Parcel object
double charge(const Parcel& p)
{
    return charge(p.weightKg, p.express, p.insured);
}

int main()
{
    cout << fixed << setprecision(2);

    cout << "COURIER CHARGE CALCULATOR\n";
    cout << "-------------------------\n";

    // Six function calls
    cout << "\n1. charge(2) = "
         << charge(2);

    cout << "\n2. charge(2.0f) = "
         << charge(2.0f);

    cout << "\n3. charge(2.0) = "
         << charge(2.0);

    cout << "\n4. charge(2.0, true) = "
         << charge(2.0, true);

    cout << "\n5. charge(2.0, true, true) = "
         << charge(2.0, true, true);

    Parcel p = {3.0, true, false};

    cout << "\n6. charge(Parcel) = "
         << charge(p);

    cout << "\n\nAll six function calls executed successfully.";

    cout << "\n\nOverload Resolution:";
    cout << "\ncharge(2)       -> int overload";
    cout << "\ncharge(2.0f)    -> double overload (promotion)";
    cout << "\ncharge(2.0)     -> double overload (exact match)";
    cout << "\ncharge(2.0,true)-> double overload";
    cout << "\ncharge(2.0,true,true) -> double overload";
    cout << "\ncharge(Parcel)  -> Parcel overload";

    return 0;
}
