/*Create a program with these overloaded functions named findMax:
One that finds maximum between two integers
One that finds maximum between two floating-point numbers
One that finds maximum among three integers
One that finds maximum between an integer and a float */

#include <iostream>
using namespace std;

class MaxFinder
{
public:
    int findMax(int x, int y)
    {
        return (x > y) ? x : y; //finds maximum of two integers
    }
    float findMax(float x, float y) //finds maximum between two floating point numbers
    {
        return (x > y) ? x : y;
    }
        int findMax(int x, int y, int z) //finds maximum among three integers
    {
        if (x > y && x > z)//Comparing all
            {
                return x;
            }
        else if (y > x && y > z)
            {
                return y;
            }
        else
            {
                return z;
            }
    }
    float findMax(int x, float y) //finds maximum between an integer and floating-point number
    {
        return (x > y) ? x : y;
    }
};

int main()
{
    MaxFinder maxFinder;  //Creating an object of MaxFinder class
    int int1, int2, int3; //Declared variables to store user input
    float float1, float2;

    cout << "Enter two integers: ";
    cin >> int1 >> int2;
    cout << "\nThe maximum of the two integers is: " << maxFinder.findMax(int1, int2) << endl;

    cout << "\nEnter two floating-point numbers: ";
    cin >> float1 >> float2;
    cout << "The maximum of the two floating-point numbers is: " << maxFinder.findMax(float1, float2) << endl;

    cout << "\nEnter three integers: ";
    cin >> int1 >> int2 >> int3;
    cout << "The maximum among the three integers is: " << maxFinder.findMax(int1, int2, int3) << endl;

    cout << "\nEnter an integer and a floating-point number: ";
    cin >> int1 >> float1;
    cout << "\nThe maximum between the integer and the float is: " << maxFinder.findMax(int1, float1) << endl;

    return 0;
}
