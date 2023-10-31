#include <bits/stdc++.h>
using namespace std;

// Creating a linked list node
class Node
{
public:
    int data;
    Node *link;
    Node(int n)
    {
        this->data = n;
        this->link = NULL;
    }
};

// Defining a Stack class using a linked list
class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL; // Initialize the top of the stack as NULL
    }

    // Function to push an element onto the stack
    void push(int data)
    {
        Node *temp = new Node(data); // Create a new node with the given data

        if (!temp)
        {
            cout << "\nStack Overflow"; // Check for memory allocation failure
            exit(1);
        }

        temp->link = top; // Set the new node's link to the current top
        top = temp;       // Update the top to the new node
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return top == NULL; // The stack is empty if the top is NULL
    }

    // Function to get the top element of the stack
    int peek()
    {
        if (!isEmpty())
            return top->data; // Return the data of the top element
        else
            exit(1); // Exit the program if the stack is empty
    }

    // Function to pop (remove) the top element from the stack
    void pop()
    {
        Node *temp;

        if (top == NULL)
        {
            cout << "\nStack Underflow" << endl; // Check if the stack is empty
            exit(1);
        }
        else
        {
            temp = top;      // Save the top element in a temporary variable
            top = top->link; // Update the top to the next element
            free(temp);      // Free the memory of the removed top element
        }
    }

    // Function to display the elements of the stack
    void display()
    {
        Node *temp;
        if (top == NULL)
        {
            cout << "\nStack Underflow"; // Check if the stack is empty
            exit(1);
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                cout << temp->data; // Print the data of the current node

                temp = temp->link;
                if (temp != NULL)
                    cout << " -> "; // Print an arrow between elements
            }
        }
    }
};

int main()
{
    Stack s;

    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);

    s.display();

    cout << "\nTop element is " << s.peek() << endl;
    s.pop();
    s.pop();

    s.display();
    cout << "\nTop element is " << s.peek() << endl;

    return 0;
}
