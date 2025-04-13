/*2.Stack Problem: Implement a stack using arrays (not STL) that:
1.Has basic push and pop operations
2.Has a function to find middle element
3.Has a function to reverse only bottom half of stack
4.Maintain stack size of 10
*/

#include <iostream>
using namespace std;

const int SIZE = 10;

class MyStack
{
private:
    int stackArr[SIZE];
    int top;

public:
    MyStack()
    {
        top = -1;
    }
    void pushItem(int val)//pushes data into stack
    {
        if (top == SIZE - 1)
            {
            cout << "Stack is full. Can't push! " << val << endl;
            return;
            }
        top++;
        stackArr[top] = val;
    }

    int popItem() //removes top item from stack.
    {
        if (top == -1)
        {
            cout << "Stack is empty. Nothing to pop.\n";
            return -1;
        }
        int poppedVal = stackArr[top];
        top--;
        return poppedVal;
    }

    void showMiddle()  //shows the middle value.
    {
        if (top == -1)
        {
            cout << "Stack is empty.\n";
            return;
        }

        int mid = top / 2;
        cout << "Middle element: " << stackArr[mid] << endl;
    }

void reverseLowerHalf() //reverse bottom half of the stack
{
    if (top < 1)
    {
        cout << "Not enough elements to reverse bottom half.\n";
        return;
    }

int halfCount = (top + 1) / 2;

for (int i = 0; i < halfCount / 2; i++)
{
    int temp = stackArr[i];
    stackArr[i] = stackArr[halfCount - i - 1];
    stackArr[halfCount - i - 1] = temp;
}
    cout << "Bottom half reversed.\n";
    }

void printStack() //prints the stack
{
    if (top == -1)
{
    cout << "Stack is empty.\n";
    return;
}
    cout << "Stack from top to bottom:\n";
    for (int i = top; i >= 0; i--)
        {
            cout << stackArr[i] << " ";
        }
    cout << endl;
}
};

int main()
{
    MyStack s;
    int option, num;

    while (true)
        {
            cout << "\n*** Stack ***\n";
            cout << "1. Push\n";
            cout << "2. Pop\n";
            cout << "3. Find Middle\n";
            cout << "4. Reverse Bottom Half\n";
            cout << "5. Display Stack\n";
            cout << "6. Exit\n";
            cout << "Choose: ";
            cin >> option;

        switch (option)
        {
            case 1:
                cout << "Enter number to push: ";
                cin >> num;
                s.pushItem(num);
                break;
            case 2:
                num = s.popItem();
                if (num != -1)
                    cout << "Popped: " << num << endl;
                break;
            case 3:
                s.showMiddle();
                break;
            case 4:
                s.reverseLowerHalf();
                break;
            case 5:
                s.printStack();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid input. Please try again.\n";
        }
    }

    return 0;
}
