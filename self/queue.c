#include <stdio.h>
#define MAXSIZE 4

struct queue
{
    int front, rear;
    int arr[MAXSIZE];
};
struct queue q;

int isFull()
{
    if (q.rear == MAXSIZE - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (q.front == -1 && q.rear == -1)
    {
        return 1;
    }
    return 0;
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Removing %d from the queue\n", q.arr[q.front]);
    for (int i = 0; i < q.rear; i++)
    {
        q.arr[i] = q.arr[i + 1];
    }

    q.rear--;

    // If the queue becomes empty after dequeue, reset front and rear
    if (q.rear < q.front)
    {
        q.front = -1;
        q.rear = -1;
    }
}

void enqueue(int num)
{
    if (isFull() == 1)
    {
        printf("Queue Is full\n");
        return;
    }
    q.rear++;
    if (q.front == -1)
    {
        q.front++;
    }

    q.arr[q.rear] = num;
    printf("%d is added at %d\n", num, q.rear);
}

void display()
{
    for (int i = 0; i <= q.rear; i++)
    {
        printf("| %d ", q.arr[i]);
    }
}

void main()
{
    q.front = -1;
    q.rear = -1;

    enqueue(4);
    // printf("%d", q.rear);
    // display();
    printf("\n");
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();
    printf("\n");
    dequeue();
    // printf("%d", q.rear);
    display();
    enqueue(8);
    enqueue(8);
    display();
}