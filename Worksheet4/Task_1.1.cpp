/*STL Container Practice: Write a program using STL containers that:
1.Uses vector<string> to store names
2.Uses map<string, int> to store age against each name
3.Implements functions to:
1.Add new name-age pair
2.Find all people above certain age
3.Sort and display names alphabetically
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

void addNNAP(vector<string>& names, map<string, int>& ages, const string& name, int age)
{
    names.push_back(name);
    ages[name] = age;
}

void showPAA(const map<string, int>& ages, int limit)
{
    cout << "People with age above " << limit << ":\n";
    for (const auto& p : ages)
    {
        if (p.second > limit)
        {
            cout << p.first << " - " << p.second << " years old" << endl;
        }
    }
}
void DisplaySortedNames(vector<string>& names)
{
    vector<string> sortedname = names;
    sort(sortedname.begin(), sortedname.end());
    cout << "Sorted Names:\n";
    for (const auto& name : sortedname)
    {
        cout << name << endl;
    }
}
int main()
{
    vector<string> names;
    map<string, int> ages;
    int option;
    do
    {
        cout << "\n1. Add new name-age pair\n";
        cout << "2. Show people older than a certain age\n";
        cout << "3. Display names in alphabetical order\n";
        cout << "4. Exit\n";
        cout << "Choose Option: ";
        cin >> option;

        if (option == 1)
        {
            string name;
            int age;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            addNNAP(names, ages, name, age);
            cout << "Added.\n";
        }
        else if (option == 2)
        {
            int limit;
            cout << "Enter the age limit: ";
            cin >> limit;
            showPAA(ages, limit);
        }
        else if (option == 3)
        {
            DisplaySortedNames(names);
        }
        else if (option == 4)
        {
            cout << "Exiting program.\n";
        }
        else
        {
            cout << "Invalid option.\n";
        }

    }
    while (option != 4);

    return 0;
}
