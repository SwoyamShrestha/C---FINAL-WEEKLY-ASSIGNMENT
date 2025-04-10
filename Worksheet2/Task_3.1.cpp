//Write a program that reads the titles of 10 books (use an array of 150 characters) and writes them in a binary file selected by the user.
//The program should read a title and display a message to indicate if it is contained in the file or not.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    char books[10][150];  //using array to store 10 book titles with each of 150 characters
    ofstream outputFile;
    outputFile.open("books.dat", ios::binary | ios::app);
    if (!outputFile)
        {
            cout << "Unable to open file for writing!" << endl;
            return 1;
        }

    cout << "Enter the titles of 10 books:" << endl;
    cin.ignore();
    for (int i = 0; i < 10; i++)
        {
            cout << "Title of Book " << i + 1 << ": ";
            cin.getline(books[i], 150);
            outputFile.write(books[i], sizeof(books[i]));
        }

    outputFile.close();  //closes file

    char searchTitle[150];
    cout << "Enter the book title you want to search for: ";
    cin.getline(searchTitle, 150);

    ifstream testFile("books.dat", ios::binary);
    if (!testFile)
    {
        ofstream createFile("books.dat", ios::binary);
        createFile.close();
    }
    testFile.close();

    ifstream inFile("books.dat", ios::binary); //binary file
    if (!inFile)
        {
            cout << "Error opening file for reading!" << endl;
            return 1;
        }
    bool isfound = false;
    char title[150];
    while (inFile.read(title, sizeof(title)))
    {
        if (strcmp(title, searchTitle) == 0)
        {
            isfound = true;
            break;
        }
    }
    if (isfound)
    {
            cout << "The book title is available in the file." << endl;
    }
    else
    {
            cout << "Sorry, the book title is not available in the file." << endl;
    }
    inFile.close();
    return 0;
}
