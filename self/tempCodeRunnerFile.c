#include <stdio.h>

struct Stack
{
    int top;
    int arr[100];
};

int isEmpty(struct Stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack *s)
{
    if (s->top == 100 - 1)
        return 1;
    else
        return 0;
}

void push(int num, struct Stack *s)
{
    if (isFull(s))
    {
        printf("Stack is full\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = num;
    }
}

void pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
    }
    else
    {

        printf("Popped element: %d\n", s->arr[s->top]);
        s->top--;
    }
}

void display(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->arr[i]);
        }
    }
}

void main()
{
    struct Stack s;
    s.top = -1;

    if (isEmpty(&s))
    {
        printf("Stack is empty\n");
    }

    push(1, &s);
    push(2, &s);
    push(3, &s);
    display(&s);
    if (isEmpty(&s))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
    pop(&s);
    display(&s);
}
