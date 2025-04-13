/*3.Queue Problem: Implement a queue using arrays (not STL) that:
1.Has basic enqueue and dequeue operations
2.Has a function to reverse first K elements
3.Has a function to interleave first half with second half
4.Handle queue overflow/underflow
*/

#include <iostream>
using namespace std;

const int MAX = 10;

class Queue
{
private:
    int arr[MAX];
    int front, rear, Size;

public:
    Queue()
    {
        front = 0;
        rear = -1;
        Size = 0;
    }

    bool isFull()
    {
        return Size == MAX;
    }

    bool isEmpty()
    {
        return Size == 0;
    }

    void add(int val)
    {
        if (isFull())
        {
            cout << "Queue is full. Can't enqueue " << val << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = val;
        Size++;
    }

int remove()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Nothing to dequeue.\n";
        return -1;
    }
    int removed = arr[front];
    front = (front + 1) % MAX;
    Size--;
    return removed;
}

void reverseK(int k)
{
    if (k > Size || k <= 0)
    {
        cout << "K is invalid for current queue.\n";
        return;
    }
    for (int i = 0; i < k / 2; i++)
    {
        int a = (front + i) % MAX;
        int b = (front + k - 1 - i) % MAX;
        swap(arr[a], arr[b]);
    }
    cout << "First " << k << " elements reversed.\n";
}
void interleave()
{
        if (Size % 2 != 0)
        {
            cout << "Queue must have even number of elements to interleave.\n";
            return;
        }

int temp[MAX];
int half = Size / 2;

for (int i = 0; i < half; i++)
    {
        temp[2 * i] = arr[(front + i) % MAX];
        temp[2 * i + 1] = arr[(front + half + i) % MAX];
    }

for (int i = 0; i < Size; i++)
{
    arr[(front + i) % MAX] = temp[i];
}
cout << "Queue interleaved successfully.\n";
}

void show()
{
    if (isEmpty())
    {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue (front to rear): ";
    for (int i = 0; i < Size; i++)
        {
            cout << arr[(front + i) % MAX] << " ";
        }
    cout << endl;
}
};

int main()
{
    Queue q;
    int choice, num, k;

    while (true)
    {
        cout << "\n*** Queue ***\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Reverse First K\n";
        cout << "4. Interleave Halves\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

    switch (choice)
        {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> num;
                q.add(num);
                break;
            case 2:
                num = q.remove();
                if (num != -1)
                    cout << "Dequeued: " << num << endl;
                break;
            case 3:
                cout << "Enter value of K: ";
                cin >> k;
                q.reverseK(k);
                break;
            case 4:
                q.interleave();
                break;
            case 5:
                q.show();
                break;
            case 6:
                cout << "Program ended.\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
    return 0;
}
