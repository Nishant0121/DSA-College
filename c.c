#include <stdio.h>

struct stack
{
    int a[10];
    int top;
};

struct stack s1;

void push(int x)
{
    if (s1.top == 9)
    {
        printf("Stack Overflow\n");
        return;
    }

    s1.a[s1.top + 1] = x;
    s1.top++;
}

void pop()
{
    if (s1.top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Element %d popped\n", s1.a[s1.top]);
    s1.top--;
}

void display()
{
    int i;
    if (s1.top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (i = s1.top; i >= 0; i--)
    {
        printf("%d\n", s1.a[i]);
    }
}

int main()
{
    s1.top = -1;
    printf("Hello World!\n");
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    display();
    pop();
    display();

    return 0;
}
