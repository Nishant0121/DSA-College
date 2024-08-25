#include <stdio.h>

struct Stack
{
    int top;
    int arr[100];
};
struct Stack s;
int isEmpty()
{
    return s.top == -1;
}

int isFull()
{
    return s.top == 99;
}

void push(int num)
{
    if (isFull())
    {
        printf("Stack is full\n");
    }
    else
    {
        s.top++;
        s.arr[s.top] = num;
        printf("%d pushed to stack\n", num);
    }
}

// Function to pop an element from the stack
void pop()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Popped element: %d\n", s.arr[s.top]);
        s.top--;
    }
}

void display()
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = s.top; i >= 0; i--)
        {
            printf("%d\n", s.arr[i]);
        }
    }
}

// Main function to demonstrate stack operations with a menu-driven approach
int main()
{

    s.top = -1;
    int choice, value;

    do
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display(s);
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
