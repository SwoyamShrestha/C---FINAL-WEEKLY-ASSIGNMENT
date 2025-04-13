/* 4.	Linked List Problem: Create a singly linked list (not STL) that:
1.	Has functions to insert at start/end/position
2.	Has a function to detect and remove loops
3.	Has a function to find nth node from end
4.	Has a function to reverse list in groups of K nodes
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class MyList
{
    Node* head;

public:
    MyList()
    {
        head = NULL;
    }

    void addAtStart(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtEnd(int val)
    {
        Node* newNode = new Node(val);
        if (head == NULL)
            {
                head = newNode;
                return;
            }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void addAtPos(int val, int pos)
    {
        if (pos <= 0)
            {
                cout << "Invalid position!" << endl;
                return;
            }
        if (pos == 1)
            {
                addAtStart(val);
                return;
            }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            {
                temp = temp->next;
            }
        if (temp == NULL)
            {
                cout << "Position out of range!" << endl;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
    }

    void findLoopAndRemove()
    {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next)
            {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                {
                    cout << "Loop found, removing..." << endl;
                    removeLoop(slow);
                    return;
                }
            }
        cout << "No loop found." << endl;
    }

    void removeLoop(Node* loopNode)
    {
        Node* ptr1 = head;
        Node* ptr2 = loopNode;
        while (ptr1->next != ptr2->next)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr2->next = NULL;
    }

    void printNthFromEnd(int n)
    {
        Node* p1 = head;
        Node* p2 = head;
        for (int i = 0; i < n; i++)
            {
            if (p1 == NULL)
            {
                cout << "N is too large!" << endl;
                return;
            }
            p1 = p1->next;
            }
        while (p1 != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        cout << n << "th node from end is: " << p2->data << endl;
    }

    Node* reverseK(Node* node, int k)
    {
        if (!node || k <= 1) return node;
        Node* prev = NULL;
        Node* curr = node;
        Node* next = NULL;
        int cnt = 0;
        Node* temp = node;

        for (int i = 0; i < k && temp; i++)
            {
            temp = temp->next;
            cnt++;
            }

        if (cnt < k) return node;

        cnt = 0;
        while (curr && cnt < k)
            {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
            }

        if (next != NULL)
            {
                node->next = reverseK(next, k);
            }

        return prev;
    }

    void reverseInK(int k)
    {
        head = reverseK(head, k);
        cout << "Reversed in group of " << k << endl;
    }

    void show()
    {
        Node* temp = head;
        while (temp != NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
        cout << "NULL" << endl;
    }
};

int main() {
    MyList mylist;
    int ch, val, pos, k;

    do {
        cout << "\n1. Add at Start\n";
        cout << "2. Add at End\n";
        cout << "3. Add at Position\n";
        cout << "4. Detect and Remove Loop\n";
        cout << "5. Find Nth from End\n";
        cout << "6. Reverse in Groups of K\n";
        cout << "7. Show List\n";
        cout << "8. Exit\n";
        cout << "Choose: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                mylist.addAtStart(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                mylist.addAtEnd(val);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                mylist.addAtPos(val, pos);
                break;
            case 4:
                mylist.findLoopAndRemove();
                break;
            case 5:
                cout << "Enter N: ";
                cin >> pos;
                mylist.printNthFromEnd(pos);
                break;
            case 6:
                cout << "Enter K: ";
                cin >> k;
                mylist.reverseInK(k);
                break;
            case 7:
                mylist.show();
                break;
            case 8:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }

    } while (ch != 8);

    return 0;
}
