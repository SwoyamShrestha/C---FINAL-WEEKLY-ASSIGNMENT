/*3.	Queue Problem: Implement a queue using arrays (not STL) that:
1.	Has basic enqueue and dequeue operations
2.	Has a function to reverse first K elements
3.	Has a function to interleave first half with second half
4.	Handle queue overflow/underflow
*/
#include <iostream>
using namespace std;
#define MAX_SIZE 10  // Fixed queue size
class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear, size;
public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == MAX_SIZE;
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        size++;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue.\n";
            return -1;
        }
        int removedValue = arr[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        return removedValue;
    }
    void reverseFirstK(int k) {
        if (k > size || k <= 0) {
            cout << "Invalid K value.\n";
            return;
        }
        for (int i = 0; i < k / 2; i++) {
            swap(arr[(front + i) % MAX_SIZE], arr[(front + k - 1 - i) % MAX_SIZE]);
        }

        cout << "First " << k << " elements reversed.\n";
    }
    void interleaveQueue() {
        if (size % 2 != 0) {
            cout << "Queue size must be even to interleave.\n";
            return;
        }
        int halfSize = size / 2;
        int temp[MAX_SIZE];
        for (int i = 0; i < halfSize; i++) {
            temp[i * 2] = arr[(front + i) % MAX_SIZE];
            temp[i * 2 + 1] = arr[(front + halfSize + i) % MAX_SIZE];
        }
        for (int i = 0; i < size; i++) {
            arr[(front + i) % MAX_SIZE] = temp[i];
        }
        cout << "Queue interleaved successfully.\n";
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements (front to rear): ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % MAX_SIZE] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue queue;
    int choice, value, k;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Reverse First K Elements\n4. Interleave First Half with Second Half\n5. Display Queue\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                value = queue.dequeue();
                if (value != -1)
                    cout << "Dequeued: " << value << endl;
                break;
            case 3:
                cout << "Enter K value: ";
                cin >> k;
                queue.reverseFirstK(k);
                break;
            case 4:
                queue.interleaveQueue();
                break;
            case 5:
                queue.display();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
