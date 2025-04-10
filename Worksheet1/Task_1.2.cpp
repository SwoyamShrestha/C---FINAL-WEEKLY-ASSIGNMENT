//Write a C++ program to implement a number guessing game with different difficulty levels.
//Easy difficulty ranges from 1-8, medium from 1-30, hard from 1-50. Then, generate a random number to check if the guess is correct based on the user's selection.


#include <iostream>
#include <ctime>  //generates random numbers
using namespace std;
int main()
{
    srand(time(0));
    int easy = rand() % 8 + 1;
    int medium = rand() % 30 + 1;
    int hard = rand() % 50 + 1;
    int guess;
    char difficulty;
    cout << "*******************  Number Guessing Game  *******************" << endl;
    cout << "" << endl;
    cout << "Choose the level: Easy (e), Medium (m), Hard (h): ";
    cin >> difficulty;
    switch (difficulty)
    {
        case 'e': case 'E':
            cout << "Guess a number between 1 to 8: ";
            cin >> guess;
            if (guess == easy)
            {
                cout << "Congratulations! You guessed the correct number." << endl;
            }
            else
            {
                cout << "Wrong guess! The correct number was " << easy << "." << endl;
            }
            break;
            case 'm': case 'M':
                cout << "Guess a number between 1 and 30: ";
                cin >> guess;
                if (guess == medium)
                    {
                        cout << "Congratulations! You guessed the correct number." << endl;
                    }
                else
                    {
                        cout << "Wrong guess! The correct number was " << medium << "." << endl;
                    }
                break;
                case 'h': case 'H':
                    cout << "Guess a number between 1 and 50: ";
                    cin >> guess;
                    if (guess == hard)
                        {
                            cout << "Congratulations! You guessed the correct number." << endl;
                        }
                    else
                        {
                            cout << "Wrong guess! The correct number was " << hard << "." << endl;
                        }
                    break;
                    default:
                        cout << "Invalid input! Kindly choose a valid difficulty." << endl;
    }
    return 0;
}
