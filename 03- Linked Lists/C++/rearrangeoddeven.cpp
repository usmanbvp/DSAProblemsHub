/* C++ program to rearrange a linked list in such a
 way that all odd positioned node are stored before
all even positioned nodes 

examples:
Input:   1->2->3->4
Output:  1->3->2->4
Input:   10->22->30->43->56->70
Output:  10->30->56->22->43->70
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to rearrange the linked list with odd and even positions
Node* rearrangeOddEven(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* oddHead = head;
    Node* evenHead = head->next;
    Node* oddCurrent = oddHead;
    Node* evenCurrent = evenHead;

    while (evenCurrent != NULL && evenCurrent->next != NULL) {
        oddCurrent->next = evenCurrent->next;
        oddCurrent = oddCurrent->next;
        evenCurrent->next = oddCurrent->next;
        evenCurrent = evenCurrent->next;
    }

    oddCurrent->next = evenHead;
    return oddHead;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    int n, data;

    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the data for node " << i + 1 << ": ";
        cin >> data;
        insertAtEnd(&head, data);
    }

    cout << "Original Linked List: ";
    printList(head);

    head = rearrangeOddEven(head);

    cout << "Rearranged Linked List: ";
    printList(head);

    return 0;
}
