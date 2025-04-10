/*Write a program that manages a simple student grade calculator with the following requirements.
Create a Student class that has:
1.	Student name (string)
2.	Three subject marks (integers)
3.	A basic member function to calculate average
The program should:
1.	Accept student details (name and marks) from user input
2.	Calculate and display:
  	Total marks
  	Average marks
  	Grade (A for ≥90%, B for ≥80%, C for ≥70%, D for ≥60%, F for <60%)
3.	Display a message if any mark is below 0 or above 100
*/

#include <iostream>
using namespace std;

class Student
{
    string name;
    int marks[3];

public:
        void stdDetails()
        {
            cout << "Student's Name: ";
            cin >> name;
            cout << "Marks of three subjects: ";
            for (int i = 0; i < 3; i++)
            {
                cin >> marks[i];
            if (marks[i] < 0 || marks[i] > 100) // uses marks input range between 0 and 100
                {
                    cout << "Invalid! Marks should be in between 0 and 100." << endl;
                    return;
                }
            }
        }
int calcTotalmarks()
    {
    return marks[0] + marks[1] + marks[2];
    }
    float calcAverage()
    {
        return calcTotalmarks() / 3.0;
    }
    char calcGrade()
    {
        float percentage = (calcTotalmarks() / 300.0) * 100;
        if (percentage >= 90) return 'A';
        else if (percentage >= 80) return 'B';
        else if (percentage >= 70) return 'C';
        else if (percentage >= 60) return 'D';
        else return 'F';
    }
    void displayResults()
        {
            int total = calcTotalmarks();
            float avg = calcAverage();
            char grade = calcGrade();
            cout << "\nStudent's Name: " << name << endl;
            cout << "Total Marks gained: " << total << endl;
            cout << "Average Marks: " << avg << endl;
            cout << "Grade: " << grade << endl;
        }
    };
int main()
{
    Student student;

    student.stdDetails();
    student.displayResults();

    return 0;
}
