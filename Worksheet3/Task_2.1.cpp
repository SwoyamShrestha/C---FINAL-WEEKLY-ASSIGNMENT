/*Create a base class Vehicle and two derived classes Car and Bike:
1.Vehicle has registration number and color
2.Car adds number of seats
3.Bike adds engine capacity
4.Each class should have its own method to write its details to a file
5.Include proper inheritance and method overriding
*/

#include <iostream>
#include <fstream>
#include <memory>
using namespace std;

class Vehicle // Base Class
{
protected:
    string regNo;
    string paint;
public:
    Vehicle(const string& reg, const string& clr) : regNo(reg), paint(clr) {}
    virtual void saveToFile(ofstream& out) const
    {
        out << "Vehicle - Reg: " << regNo << ", Color: " << paint << endl;
    }
    virtual void print() const
    {
        cout << "Vehicle -> Reg No: " << regNo << ", Color: " << paint << endl;
    }
    virtual ~Vehicle() {}
};

class FourWheeler : public Vehicle // Derived Class - Four Wheeler
{
    int seatCount;
public:
    FourWheeler(const string& reg, const string& clr, int seats) : Vehicle(reg, clr), seatCount(seats) {}
    void saveToFile(ofstream& out) const override
    {
        out << "Car - Reg: " << regNo << ", Color: " << paint << ", Seats: " << seatCount << endl;
    }
    void print() const override
    {
        cout << "Car Reg No: " << regNo << ",\nColor: " << paint << ",\nSeats: " << seatCount << endl;
    }
};

class TwoWheeler : public Vehicle // Derived Class - Two Wheeler
{
    int cc;
public:
    TwoWheeler(const string& reg, const string& clr, int engineCC) : Vehicle(reg, clr), cc(engineCC) {}
    void saveToFile(ofstream& out) const override
    {
        out << "Bike - Reg: " << regNo << ", Color: " << paint << ", Engine: " << cc << "cc" << endl;
    }
    void print() const override
    {
        cout << "Bike Reg No: " << regNo << ",\nColor: " << paint << ",\nEngine: " << cc << "cc" << endl;
    }
};

int main()
{
    ofstream record("Vehicle's Registration.txt", ios::app);
    if (!record.is_open())
    {
        cerr << "The file does not exist!" << endl;
        return -1;
    }

    int option = 0;
    do
    {
        cout << "\n******* Vehicle Entry Menu *******" << endl;
        cout << "1. Add Car\n2. Add Bike\n3. Save & exit\nSelect Option: ";
        cin >> option;
        cin.ignore(); //clears the input buffer

        string rno, col;
        unique_ptr<Vehicle> ptr = nullptr;

    switch (option)
    {
        case 1:
        {
            int seats;
            cout << "Enter Car Registration Number: ";
            getline(cin, rno);
            cout << "Enter Car Color: ";
            getline(cin, col);
            cout << "Enter Seat Count: ";
            cin >> seats;
            cin.ignore(); //clears newline from buffer
            ptr = make_unique<FourWheeler>(rno, col, seats);
            break;
        }
        case 2:
        {
            int engine;
            cout << "Enter Bike Registration Number: ";
            getline(cin, rno);
            cout << "Enter Bike Color: ";
            getline(cin, col);
            cout << "Enter Engine Capacity (cc): ";
            cin >> engine;
            cin.ignore();
            ptr = make_unique<TwoWheeler>(rno, col, engine);
            break;
        }
            case 3:
                cout << "Saving and exiting program..." << endl;
                break;
            default:
                cout << "Invalid input! Please choose 1, 2, or 3." << endl;
        }

        if (ptr)
        {
            ptr->saveToFile(record);
            cout << "Vehicle registration successfully recorded:\n";
            ptr->print();
        }

    } while (option != 3);

    record.close();
    return 0;
}
