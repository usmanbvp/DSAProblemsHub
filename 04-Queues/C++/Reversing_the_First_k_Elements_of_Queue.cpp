#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseKElements(queue<int>& q, int k) {
    if (k <= 0 || k > q.size()) {
        cerr << "Invalid value of k" << endl;
        return;
    }
    
    stack<int> s;
    

    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }
    
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    
    for (int i = 0; i < q.size() - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int k;
    
    int n;
    cout << "Enter the number of elements in the queue: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        q.push(element);
    }
    
    cout << "Enter the value of k: ";
    cin >> k;
    
    reverseKElements(q, k);
    
    cout << "Reversed queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}
