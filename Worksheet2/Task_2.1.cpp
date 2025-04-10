//Write a program with a class Circle having:
//Private member: radius (float)
//A constructor to initialize radius
//A friend function compareTwoCircles that takes two Circle objects and prints which circle has the larger area


#include <iostream>
using namespace std;

class Circle
{
private:
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }

    float calcArea() const
    {
        return 3.14159 * radius * radius;
    }

    void compare(const Circle& other) const //function for comparing two circles
    {
        float area1 = this-> calcArea();
        float area2 = other.calcArea();

        cout << "Area of First Circle: " << area1 << endl;
        cout << "Area of Second Circle: " << area2 << endl;

        if (area1 > area2)
        {
            cout << "First circle has Larger Area." << endl;
        }
        else if (area2 > area1)
        {
            cout << "Second Circle has Larger Area." << endl;
        }
        else
        {
            cout << "Both circle have the same area." << endl;
        }
    }
};
int main()
{
    float r1, r2;

    cout << "Radius of First Circle: ";
    cin >> r1;

    cout << "Radius of Second circle: ";
    cin >> r2;

    Circle circle1(r1), circle2(r2);

    circle1.compare(circle2); //comparing two circles

    return 0;
}
