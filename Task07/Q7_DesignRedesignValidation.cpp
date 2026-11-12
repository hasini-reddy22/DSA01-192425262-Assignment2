
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

const int CAPACITY = 10;
const int TOTAL_TRANSACTIONS = 100000;

// Original design: shifting array
class ShiftingBuffer
{
private:
    int data[CAPACITY];
    int count;
    long long movements;

public:
    ShiftingBuffer()
    {
        count = 0;
        movements = 0;
    }

    void add(int value)
    {
        if (count < CAPACITY)
        {
            data[count] = value;
            count++;
        }
        else
        {
            // Shift elements to remove the oldest
            for (int i = 1; i < CAPACITY; i++)
            {
                data[i - 1] = data[i];
                movements++;
            }

            data[CAPACITY - 1] = value;
        }
    }

    long long getMovements() const
    {
        return movements;
    }

    void display() const
    {
        cout << "Latest transactions: ";

        for (int i = 0; i < count; i++)
            cout << data[i] << " ";

        cout << endl;
    }

    int getValue(int index) const
    {
        return data[index];
    }

    int getCount() const
    {
        return count;
    }
};

// Redesigned approach: Circular buffer
class CircularBuffer
{
private:
    int data[CAPACITY];
    int count;
    int start;
    long long movements;

public:
    CircularBuffer()
    {
        count = 0;
        start = 0;
        movements = 0;
    }

    void add(int value)
    {
        int position;

        if (count < CAPACITY)
        {
            position = (start + count) % CAPACITY;
            count++;
        }
        else
        {
            position = start;
            start = (start + 1) % CAPACITY;
        }

        data[position] = value;
    }

    long long getMovements() const
    {
        return movements;
    }

    void display() const
    {
        cout << "Latest transactions: ";

        for (int i = 0; i < count; i++)
        {
            int position = (start + i) % CAPACITY;
            cout << data[position] << " ";
        }

        cout << endl;
    }

    int getValue(int index) const
    {
        return data[(start + index) % CAPACITY];
    }

    int getCount() const
    {
        return count;
    }
};

int main()
{
    ShiftingBuffer original;
    CircularBuffer redesigned;

    cout << "TASK 07 - DESIGN REDESIGN AND VALIDATION\n";
    cout << "----------------------------------------\n";

    cout << "\nCapacity: " << CAPACITY;
    cout << "\nTotal Transactions: "
         << TOTAL_TRANSACTIONS << endl;

    // Measure original shifting implementation
    auto startOriginal = high_resolution_clock::now();

    for (int i = 1; i <= TOTAL_TRANSACTIONS; i++)
        original.add(i);

    auto endOriginal = high_resolution_clock::now();

    auto originalTime =
        duration_cast<microseconds>(
            endOriginal - startOriginal).count();

    // Measure redesigned circular buffer
    auto startRedesign = high_resolution_clock::now();

    for (int i = 1; i <= TOTAL_TRANSACTIONS; i++)
        redesigned.add(i);

    auto endRedesign = high_resolution_clock::now();

    auto redesignTime =
        duration_cast<microseconds>(
            endRedesign - startRedesign).count();

    // Validate both implementations
    bool correct = true;

    if (original.getCount() != redesigned.getCount())
        correct = false;

    for (int i = 0; i < CAPACITY; i++)
    {
        if (original.getValue(i) != redesigned.getValue(i))
            correct = false;
    }

    cout << "\nORIGINAL DESIGN - SHIFTING ARRAY\n";
    original.display();

    cout << "Element movements: "
         << original.getMovements() << endl;

    cout << "Execution time: "
         << originalTime << " microseconds\n";

    cout << "\nREDESIGNED - CIRCULAR BUFFER\n";
    redesigned.display();

    cout << "Element movements: "
         << redesigned.getMovements() << endl;

    cout << "Execution time: "
         << redesignTime << " microseconds\n";

    cout << "\nVALIDATION RESULT\n";

    if (correct)
        cout << "PASS: Both designs store the same latest transactions.\n";
    else
        cout << "FAIL: Transaction results do not match.\n";

    cout << "\nREDESIGN ANALYSIS\n";
    cout << "Original insertion after full capacity: O(n)\n";
    cout << "Circular buffer insertion: O(1)\n";
    cout << "Both designs use O(n) storage.\n";

    cout << "\nRedesign completed successfully.\n";

    return 0;
}
