#include<stdio.h>
#include<stdlib.h>
#define size 100
typedef struct{
    char name[100];
    int time1;
}Teller;
typedef struct{
    Teller items[size];
    int front;
    int rear;
}Queue;
int sum=0;
Queue *createqueue()
{
    Queue *q=(Queue *)malloc(sizeof(Queue ));
    q->front=-1;
    q->rear=-1;
    return q;
}

int isFull(Queue *q)
{
    if(q->front==q->rear+1%size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int isEmpty(Queue *q)
{
    if(q->front==-1 && q->rear==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(Queue *q,Teller t)
{
    if(isFull(q))
    {
        printf("Queue is Full \n");
        exit(1);
    }
    if(isEmpty(q))
    {
        q->front=q->rear=0;
    }
    else
    {
        q->rear=(q->rear+1)%size;
    }
    q->items[q->rear]=t;
    printf("Teller %s has been added to queue  \n",t.name);
}

Teller dequeue(Queue *q)
{
    Teller t;
    if(isEmpty(q))
    {
        printf("Queue is Empty \n");
        return t;
    }
    if(q->front==q->rear)
    {
        t=q->items[q->front];
        q->front=q->rear=-1;
    }
    else
    {
        t=q->items[q->front];
        q->front=(q->front+1)%size;
    }
    printf("Teller  %s has been removed from queue \n",t.name);
    //int sum=0;
    sum=sum+t.time1;
    printf("The time he/she took was %d \n",t.time1);
    printf("The amount taken for the Queue/to wait is %d \n",sum);
    return t;
}
int main()
{
    Queue *q=createqueue();
    int numtellers;
    Teller t;
    printf("Enter the no of tellers: ");
    scanf("%d",&numtellers);
    for(int i=0;i<numtellers;i++)
    {
        printf("\nEnter the name of the teller: ");
        scanf("%s",t.name);
        printf("\n Enter the time taken:  ");
        scanf("%d",&t.time1);
        enqueue(q,t);
    }
    printf("Tellers are waiting in the queue \n");
    while(!isEmpty(q))
    {
        t=dequeue(q);
        printf("Teller has been assigned to banker \n");
    }
    printf("All tellers tasks have been checked by Banker \n");
    
    return 0;
}




