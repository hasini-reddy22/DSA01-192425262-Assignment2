
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Time
{
private:
    int h, m;

public:
    Time(int hours, int minutes)
    {
        h = hours;
        m = minutes;
    }

    // Friend function declarations
    friend int minutesBetween(const Time& t1, const Time& t2);
    friend bool earlier(const Time& t1, const Time& t2);
};

// Friend function to calculate absolute difference in minutes
int minutesBetween(const Time& t1, const Time& t2)
{
    int first = t1.h * 60 + t1.m;
    int second = t2.h * 60 + t2.m;

    int difference = first - second;

    return (difference < 0) ? -difference : difference;
}

// Friend function to check which time is earlier
bool earlier(const Time& t1, const Time& t2)
{
    int first = t1.h * 60 + t1.m;
    int second = t2.h * 60 + t2.m;

    return first < second;
}

// Inline function
inline int inlineSquare(int x)
{
    return x * x;
}

// Non-inline function (GCC-specific attribute prevents inlining)
__attribute__((noinline))
int normalSquare(int x)
{
    return x * x;
}

int main()
{
    cout << "TRAIN JOURNEY PLANNER\n";
    cout << "---------------------\n";

    Time departure(9, 45);
    Time arrival(13, 10);

    cout << "\nDeparture: 09:45";
    cout << "\nArrival: 13:10";

    cout << "\nMinutes Between: "
         << minutesBetween(departure, arrival);

    cout << "\nIs Departure Earlier? "
         << boolalpha << earlier(departure, arrival);

    // Test around noon
    Time beforeNoon(11, 59);
    Time afterNoon(12, 1);

    cout << "\n\nNoon Test:";
    cout << "\nMinutes Between 11:59 and 12:01: "
         << minutesBetween(beforeNoon, afterNoon);

    cout << "\nIs 11:59 Earlier Than 12:01? "
         << earlier(beforeNoon, afterNoon);

    // Test same time
    Time sameTime1(14, 30);
    Time sameTime2(14, 30);

    cout << "\n\nSame Time Test:";
    cout << "\nMinutes Between: "
         << minutesBetween(sameTime1, sameTime2);

    cout << "\nIs First Time Earlier? "
         << earlier(sameTime1, sameTime2);

    // Benchmark 10 million calls
    const int ITERATIONS = 10000000;
    volatile long long result = 0;

    auto startInline = high_resolution_clock::now();

    for (int i = 0; i < ITERATIONS; i++)
    {
        result = result + inlineSquare(i % 100);
    }

    auto endInline = high_resolution_clock::now();

    auto inlineTime =
        duration_cast<milliseconds>(endInline - startInline).count();

    auto startNormal = high_resolution_clock::now();

    for (int i = 0; i < ITERATIONS; i++)
    {
        result = result + normalSquare(i % 100);
    }

    auto endNormal = high_resolution_clock::now();

    auto normalTime =
        duration_cast<milliseconds>(endNormal - startNormal).count();

    cout << "\n\nFUNCTION PERFORMANCE";
    cout << "\nIterations: " << ITERATIONS;
    cout << "\nInline Function Time: "
         << inlineTime << " ms";
    cout << "\nNon-Inline Function Time: "
         << normalTime << " ms";

    cout << "\n\nFinal Result: " << result << endl;

    return 0;
}
