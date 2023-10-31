#include <bits/stdc++.h>
using namespace std;

// Function to find the next greater element for each element of the array.
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long int> st;               // Stack to store the indexes of 'arr' rather than the elements themselves
    vector<long long int> vec(arr.size()); // Final vector to be returned

    // Loop through the array to find the next greater element for each element
    for (int i = 0; i < n; i++)
    {
        // If the stack is not empty and 'arr[i]' is greater than the element in 'arr' at the index
        // present at the top of the stack, then set 'arr[i]' as the next greater element for that index.
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            vec[st.top()] = arr[i]; // Store 'arr[i]' as the next greater element for the top of the stack
            st.pop();               // Remove the index from the stack
        }
        st.push(i); // Push the current index onto the stack
    }

    // If the stack is not empty at this point, it means there's no next greater element, so set -1 for those indexes.
    while (!st.empty())
    {
        vec[st.top()] = -1; // Set -1 as the next greater element for the indexes in the stack
        st.pop();           // Remove the index from the stack
    }

    return vec; // Return the vector containing the next greater elements.
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<long long> arr(n);

    // Input elements into the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Call the function to find the next greater elements for each element in the array
    vector<long long> res = nextLargerElement(arr, n);

    // Print the result
    cout << "Next greater elements for each element: ";
    for (long long i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
