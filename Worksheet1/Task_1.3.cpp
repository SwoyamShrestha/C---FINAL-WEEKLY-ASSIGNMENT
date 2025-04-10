//Write a program that reads an array of integer numbers from the user and sorts the numbers in the ascending order.

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, arr[100];
    cout << "Enter number of element: ";
    cin >> n;
    if (n > 100 || n <= 0)
        {
            cout << "Invalid input! Please enter a number between 1 and 100." << endl;
            return 1;  //quits Program
        }
    cout << "Enter numbers: ";
    for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    sort(arr, arr + n);
    cout << "Sorted numbers: ";
    for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    cout << endl;
    return 0;
}
