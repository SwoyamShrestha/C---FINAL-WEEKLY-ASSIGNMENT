// Create a program that takes a positive integer as input and determines whether it's a "bouncy number".
// A bouncy number is one where the digits neither consistently increase nor consistently decrease when read from left to right. For example:
// 123 is NOT bouncy (digits consistently increase)
// 321 is NOT bouncy (digits consistently decrease)
// 120 is bouncy (neither consistently increasing nor decreasing)


#include <iostream>
using namespace std;
bool BouncyNum(int num)
{
    if (num < 100) return false;
    bool increasing = false, decreasing = false;
    int lastDigit = num % 10;
    num /= 10;  //removes last digit
    while (num > 0)
        {
            int currentDigit = num % 10;
            if (currentDigit < lastDigit) increasing = true;
            if (currentDigit > lastDigit) decreasing = true;
            if (increasing && decreasing) return true;  //if both are true, it's bouncy
            lastDigit = currentDigit;
            num /= 10;
        }
        return false;
}
int main()
{
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    if (BouncyNum(num))
        {
            cout << num << " is a bouncy number." << endl;
        }
    else
        {
            cout << num << " is not a bouncy number." << endl;
        }
    return 0;
}
