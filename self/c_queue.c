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
    if ((q.rear + 1) % MAXSIZE == q.front)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (q.front == -1 || q.rear == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int num)
{
    if (isFull() == 1)
    {
        printf("The Queue is Full\n");
        return;
    }
    q.rear = (q.rear + 1) % MAXSIZE;
    if (q.front == -1)
    {
        q.front++;
    }
    q.arr[q.rear] = num;
    printf("Element %d Added at %d\n", num, q.rear);
}

void dequeue()
{
    if (isEmpty() == 1)
    {
        printf("Queue Is Empty\n");
    }
    else
    {
        if (q.front == q.rear)
        {
            printf("Element %d at %d is removed\n", q.arr[q.front], q.front);
            q.arr[q.front] = 0;
            q.front = -1;
            q.rear = -1;
            return;
        }

        printf("Element %d at %d is removed\n", q.arr[q.front], q.front);
        q.arr[q.front] = 0;
        q.front = (q.front + 1) % MAXSIZE;
    }
}

int main()
{
    q.front = -1;
    q.rear = -1;
    enqueue(3);
    enqueue(2);
    enqueue(1);
    enqueue(10);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}