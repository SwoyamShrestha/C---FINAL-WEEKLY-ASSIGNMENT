//Write a program that manages a cinema ticket booking system. The program should display a 5x5 seating arrangement

#include <iostream>
using namespace std;
int main()
{
    char tbs[5][5] = //5x5 seat
    {
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'}
    };

    while (true)//looping for seat booking
    {
        cout << "****** Cinema Seat Reservation ******:\n";
        for (int row = 0; row < 5; row++)//shows current seat
        {
            for (int col = 0; col < 5; col++)
            {
                cout << tbs[row][col] << " ";  //shows seat availability status
            }
            cout << endl;
        }

        cout << "Select a Row (1-5)? ";
        int row;
        cin >> row;

        cout << "Select a Column (1-5)? ";
        int col;
        cin >> col;

        if (row == 0 && col == 0)
            {
            cout << "Exit\n";
            break;
            }

        if (row < 1 || row > 5 || col < 1 || col > 5)  //checks if row and column are within valid range
        {
            cout << "Please select between 1 and 5.\n";
            continue;
        }

        row--;
        col--;

        if (tbs[row][col] == 'X') { //Checks if the seat is already booked
            cout << "The seat is already reserved. Try another\n";
            continue;
        }

        tbs[row][col] = 'X';
        cout << "Seat booked successfully!\n";

        char choice;
        cout << "Do you want to book more seats? (y/n): ";
        while (true)
            {
                cin >> choice;
                if (choice == 'y' || choice == 'Y')
                {
                    break;
                }
        else if (choice == 'n' || choice == 'N')
            {
                cout << "Thank you for booking, Enjoy watching!\n";
                return 0; //exits the program after booking is complete
            }
            else
            {
                cout << "Invalid input! Please enter 'y' for yes or 'n' for no: ";
            }
            }
    }
    return 0;
}
