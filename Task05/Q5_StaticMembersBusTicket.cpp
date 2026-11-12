
#include <iostream>
#include <string>
using namespace std;

class BusTicket
{
private:
    static int issued;
    static const int CAPACITY = 3;

    int seat;
    string name;

public:
    // Constructor
    BusTicket(string passengerName)
    {
        name = passengerName;

        if (issued < CAPACITY)
        {
            seat = ++issued;
        }
        else
        {
            seat = 0; // Waiting list
        }
    }

    // Static member function
    static int count()
    {
        return issued;
    }

    // Display ticket details
    void display() const
    {
        if (seat == 0)
            cout << name << ": Waiting" << endl;
        else
            cout << name << ": Seat " << seat << endl;
    }
};

// Definition of static data member
int BusTicket::issued = 0;

// Create an array of ticket objects
void createFirstBatch()
{
    cout << "\nFirst Batch:\n";

    BusTicket tickets[5] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev"),
        BusTicket("Esha")
    };

    for (int i = 0; i < 5; i++)
        tickets[i].display();

    cout << "Issued: " << BusTicket::count() << endl;
}

// Function called again to show static count persists
void createSecondBatch()
{
    cout << "\nSecond Batch:\n";

    BusTicket tickets[2] = {
        BusTicket("Farah"),
        BusTicket("Gokul")
    };

    for (int i = 0; i < 2; i++)
        tickets[i].display();

    cout << "Issued: " << BusTicket::count() << endl;
}

// Token example from the assignment
class Token
{
    static int next;
    int id;

public:
    Token()
    {
        id = ++next;
    }

    int get() const
    {
        return id;
    }

    static int issued()
    {
        return next - 100;
    }
};

int Token::next = 100;

int main()
{
    cout << "COLLEGE BUS SEAT TICKET SYSTEM\n";
    cout << "Capacity: 3 seats\n";

    createFirstBatch();
    createSecondBatch();

    cout << "\nToken Prediction Demonstration:\n";

    Token counter[3];
    Token extra;

    cout << counter[0].get() << " "
         << counter[2].get() << " "
         << extra.get() << " "
         << Token::issued() << endl;

    return 0;
}
