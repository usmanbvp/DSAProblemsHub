#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    int getFront() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. No front element.\n";
            return -1;
        }
        return front->data;
    }
};

int main() {
    Queue queue;

    int n;
    std::cout << "Enter the number of elements to enqueue: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int element;
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> element;
        queue.enqueue(element);
    }

    if (!queue.isEmpty()) {
        std::cout << "Front element: " << queue.getFront() << std::endl;
        queue.dequeue();
        std::cout << "Front element after dequeue: " << queue.getFront() << std::endl;
    } else {
        std::cout << "The queue is empty." << std::endl;
    }

    return 0;
}
