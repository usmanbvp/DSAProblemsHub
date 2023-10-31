#include <bits/stdc++.h>
using namespace std;

// Function to insert an element at the bottom of the stack
void insert_at_bottom(stack<int> &st, int x)
{
    if (st.size() == 0)
    {
        st.push(x); // If the stack is empty, push the element
    }
    else
    {
        int a = st.top();        // Save the top element of the stack
        st.pop();                // Remove the top element
        insert_at_bottom(st, x); // Recursively insert the element at the bottom
        st.push(a);              // Push the saved top element back on top
    }
}

// Function to reverse a stack using recursion
void reverse(stack<int> &st)
{
    if (st.size() > 0)
    {
        int x = st.top();        // Save the top element of the stack
        st.pop();                // Remove the top element
        reverse(st);             // Recursively reverse the remaining elements
        insert_at_bottom(st, x); // Insert the saved element at the bottom
    }
    return;
}

int main()
{
    stack<int> st, st2;
    for (int i = 1; i <= 4; i++)
    {
        st.push(i); // Push elements 1 to 4 onto the stack 'st'
    }

    st2 = st; // Create a copy of the original stack 'st'

    cout << "Original Stack" << endl;
    while (!st2.empty())
    {
        cout << st2.top() << " "; // Print the top element of 'st2'
        st2.pop();                // Remove the top element from 'st2'
    }
    cout << endl;

    reverse(st); // Reverse the original stack 'st'

    cout << "Reversed Stack" << endl;
    while (!st.empty())
    {
        cout << st.top() << " "; // Print the reversed elements of 'st'
        st.pop();                // Remove the top element from 'st'
    }
    return 0;
}
