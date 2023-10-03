#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) {
            return false; // No cycle if there are 0 or 1 nodes
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;      // Move one step at a time
            fast = fast->next->next; // Move two steps at a time
            
            if (slow == fast) {
                return true; // If slow and fast meet, there is a cycle
            }
        }
        
        return false; // If fast reaches the end, there is no cycle
    }
};

int main() {
    // Create a sample linked list with a cycle
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1; // Create a cycle

    Solution solution;
    bool hasCycle = solution.hasCycle(head);

    if (hasCycle) {
        std::cout << "The linked list has a cycle." << std::endl;
    } else {
        std::cout << "The linked list does not have a cycle." << std::endl;
    }

    return 0;
}
