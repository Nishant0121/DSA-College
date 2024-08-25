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
    return (q.rear + 1) % MAXSIZE == q.front;
}

int isEmpty()
{
    return q.front == -1;
}

void enqueue(int num)
{
    if (isFull())
    {
        printf("The Queue is Full\n");
        return;
    }
    q.rear = (q.rear + 1) % MAXSIZE;
    if (q.front == -1)
    {
        q.front = 0;
    }
    q.arr[q.rear] = num;
    printf("Element %d added at position %d\n", num, q.rear);
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Element %d at position %d is removed\n", q.arr[q.front], q.front);
        if (q.front == q.rear)
        {
            q.front = -1;
            q.rear = -1;
        }
        else
        {
            q.front = (q.front + 1) % MAXSIZE;
        }
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue elements are:\n");
        int i = q.front;
        while (i != q.rear)
        {
            printf("%d at position %d\n", q.arr[i], i);
            i = (i + 1) % MAXSIZE;
        }
        printf("%d at position %d\n", q.arr[i], i);
    }
}

int main()
{
    q.front = -1;
    q.rear = -1;
    int choice, value;

    do
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
