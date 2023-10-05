#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);  // Create a dummy node to simplify handling edge cases
        ListNode* current = &dummy;  // Initialize current pointer to the dummy node

        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        // Append the remaining elements (if any) from l1 or l2
        current->next = (l1 != nullptr) ? l1 : l2;

        return dummy.next;  // Return the merged sorted list (skip the dummy node)
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create two sorted linked lists
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // Merge the two sorted linked lists
    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(l1, l2);

    // Print the merged list
    std::cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
