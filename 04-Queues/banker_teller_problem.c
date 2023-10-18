#include <stdio.h>
#include <stdlib.h>

// Define a constant for the maximum size of the queue
#define size 100

// Define a structure for a Teller
typedef struct {
    char name[100];
    int time1;
} Teller;

// Define a structure for a Queue
typedef struct {
    Teller items[size]; // Array to store Teller objects
    int front;          // Front of the queue
    int rear;           // Rear of the queue
} Queue;

int sum = 0; // A global variable to keep track of the total time

// Function to create and initialize a queue
Queue *createqueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is full
int isFull(Queue *q) {
    if (q->front == (q->rear + 1) % size) {
        return 1; // Queue is full
    } else {
        return 0; // Queue is not full
    }
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    if (q->front == -1 && q->rear == -1) {
        return 1; // Queue is empty
    } else {
        return 0; // Queue is not empty
    }
}

// Function to enqueue a Teller into the queue
void enqueue(Queue *q, Teller t) {
    if (isFull(q)) {
        printf("Queue is Full \n");
        exit(1); // Exit the program if the queue is full
    }
    if (isEmpty(q)) {//If queue is empty initialize a new queue 
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % size;//Add tellers to the queue
    }
    q->items[q->rear] = t;
    printf("Teller %s has been added to queue  \n", t.name);
}

// Function to dequeue a Teller from the queue
Teller dequeue(Queue *q) {
    Teller t;
    if (isEmpty(q)) {
        printf("Queue is Empty \n");
        return t; // Return an empty Teller if the queue is empty
    }
    if (q->front == q->rear) {//Check if queue is full
        t = q->items[q->front];
        q->front = q->rear = -1;
    } else {
        t = q->items[q->front];
        q->front = (q->front + 1) % size;//If Queue is not empty remove tellers from front of the queue
    }
    printf("Teller  %s has been removed from queue \n", t.name);
    sum = sum + t.time1; // Update the total time
    printf("The time he/she took was %d \n", t.time1);
    printf("The amount taken for the Queue/to wait is %d \n", sum);
    return t;
}

int main() {
    Queue *q = createqueue();
    int numtellers;
    Teller t;

    // Get the number of tellers from the user
    printf("Enter the no of tellers: ");
    scanf("%d", &numtellers);

    // Input details for each teller and enqueue them
    for (int i = 0; i < numtellers; i++) {
        printf("\nEnter the name of the teller: ");
        scanf("%s", t.name);
        printf("\n Enter the time taken:  ");
        scanf("%d", &t.time1);
        enqueue(q, t);
    }

    printf("Tellers are waiting in the queue \n");

    // Dequeue and process tellers until the queue is empty
    while (!isEmpty(q)) {//Check if Queue is not empty
        t = dequeue(q);
        printf("Teller has been assigned to banker \n");
    }

    printf("All tellers tasks have been checked by Banker \n");

    return 0;
}
