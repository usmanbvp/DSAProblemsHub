# Question:- Given the head of a singly linked list, reverse the list, and return the reversed list.
# Problem link:- https://leetcode.com/problems/reverse-linked-list/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverseList(head: ListNode) -> ListNode:
    prev, curr = None, head

    while curr:
        temp = curr.next
        curr.next = prev
        prev = curr
        curr = temp
    return prev

def createList(values):
    if not values:
        return None
    head = ListNode(values[0])
    curr = head
    for val in values[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head

def printList(head):
    curr = head
    while curr:
        print(curr.val, end = " -> ")
        curr = curr.next
    print("None")

# Example

ip = [1,2,3,4,5]
head = createList(ip)

print("Previous:\n")
printList(head)

print("\nReversed:\n")
ans = reverseList(head)
printList(ans)
