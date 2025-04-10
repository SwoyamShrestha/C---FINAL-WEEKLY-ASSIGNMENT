//Create a program that:

//Reads student records (roll, name, marks) from a text file
//Throws an exception if marks are not between 0 and 100
//Allows adding new records with proper validation
//Saves modified records back to file

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

struct Student
{
    int roll;
    string name;
    int marks;
};

void validateMarks(int marks)
{
    if (marks < 0 || marks > 100)
    {
        throw out_of_range("Marks should be between 0 and 100.");
    }
}

vector<Student> readRecords(string fileName)
{
    vector<Student> records;
    ifstream File(fileName);

    if (!File)
    {
        cout << "The file does not exist.\n";
        return records;
    }

    Student student;
    while (File >> student.roll >> student.name >> student.marks)
        {
            records.push_back(student);
        }

    File.close();
    return records;
}

void saveStdRecords(string fileName, vector<Student> records)
{
    ofstream File(fileName);

    if (!File)
    {
        cout << "Error opening file for writing!\n";
        return;
    }

    for (const auto& records : records)
    {
        File << records.roll << " " << records.name << " " << records.marks << endl;
    }
    File.close();
}

int main()
{
    string fileName = "Student's Record.txt";
    vector<Student> studentlist = readRecords(fileName);

    if (!studentlist.empty())
    {
        cout << "Existing Student Records:\n";
        for (const auto& student : studentlist)
        {
                cout << "Roll: " << student.roll << ", Name: " << student.name << ", Marks: " << student.marks << endl;
        }
    }
    else
    {
        cout << "No records found.\n";
    }

    bool running = true;
    while (running)
        {
            int userchoice;
            cout << "\nChoose an option:\n";
            cout << "1. Add new student record\n";
            cout << "2. Modify existing student record\n";
            cout << "3. Save and Exit\n";
            cout << "Enter choice: ";
            cin >> userchoice;

        if (userchoice == 1)
            {
                Student newStudent; // Option to add a new student
                cout << "Enter Roll: ";
                cin >> newStudent.roll;
                cin.ignore(); // To clear the buffer after taking integer input
                cout << "Enter Name: ";
                getline(cin, newStudent.name);
                cout << "Enter Marks: ";
                cin >> newStudent.marks;

                try
                {
                    validateMarks(newStudent.marks);
                    studentlist.push_back(newStudent);
                    cout << "New student record added successfully.\n";
                }
        catch (const out_of_range& e)
        {
            cout << "Error: " << e.what() << endl;
        }
            }

        else if (userchoice == 2)
            {
                int rollNoToModify;
                cout << "Enter Roll No of student to modify: ";
                cin >> rollNoToModify;

                bool recfound = false;
                for (auto& student : studentlist)
                    {
                        if (student.roll == rollNoToModify)
                            {
                                recfound = true;
                                cout << "Enter new marks: ";
                                int newMarks;
                                cin >> newMarks;

                        try
                            {
                            validateMarks(newMarks);
                            student.marks = newMarks;
                            cout << "Marks updated successfully.\n";
                            }
                        catch (const out_of_range& e)
                            {
                                cout << "Error: " << e.what() << endl;
                            }
                        break;
                            }
                    }
                        if (!recfound)
                            {
                                cout << "Student with Roll No " << rollNoToModify  << " not found.\n";
                            }
            }

        else if (userchoice == 3)
            {
                saveStdRecords(fileName, studentlist);
                cout << "Records saved successfully! Exiting program.\n";
                running = false;
            }

        else
            {
                cout << "Invalid choice. Please try again.\n";
            }
        }

    return 0;
}
