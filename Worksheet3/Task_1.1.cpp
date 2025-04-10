/*Create a Time class to store hours and minutes. Implement:
1.Overload the + operator to add two Time objects
2.Overload the > operator to compare two Time objects
3.Handle invalid time (>24 hours or >60 minutes) by throwing a custom exception
*/

#include <iostream>
#include <stdexcept>
using namespace std;

class ITE : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Invalid time! Time Hours must be less than or equals to 24 and minutes must be less than 60.";
    }
};

class Time
{
private:
    int hours;
    int minutes;

    void validate()
    {
        if (hours > 24 || minutes >= 60)
            {
                throw ITE();
            }
    }

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) // Constructor with default values
    {
        validate();
    }

    Time operator+(const Time& other) const
    {
        int totalHours = hours + other.hours;
        int totalMinutes = minutes + other.minutes;

        if (totalMinutes >= 60)
            {
                totalHours += totalMinutes / 60;
                totalMinutes %= 60;
            }
        return Time(totalHours, totalMinutes);
    }

    bool operator>(const Time& other) const
    {
        return (hours * 60 + minutes) > (other.hours * 60 + other.minutes);
    }

    void display() const
    {
        cout << hours << " hours " << minutes << " minutes" << endl;
    }
};

int main()
{
    try
    {
        int h1, m1, h2, m2;

        cout << "Enter first time (hours minutes): ";
        cin >> h1 >> m1;
        Time t1(h1, m1);

        cout << "Enter second time (hours minutes): ";
        cin >> h2 >> m2;
        Time t2(h2, m2);

        Time sum = t1 + t2; //sum of times
        cout << "Sum: ";
        sum.display();

        if (t1 > t2) //comparing time
            {
                cout << "First time is greater." << endl;
            }
        else
            {
                cout << "Second time is greater or equal." << endl;
            }

    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
