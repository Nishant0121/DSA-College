#include <stdio.h>
#include <stdlib.h>

struct ll_node
{
    int data;
    struct ll_node *next;
};
struct ll_node *head = NULL;

void display()
{
    struct ll_node *hp = NULL;
    hp = head;
    while (hp != NULL)
    {
        printf("\n %d", hp->data);
        hp = hp->next;
    }
}
void insert(int x)
{
    struct ll_node *pnew, *hp;
    hp = NULL;
    pnew = (struct ll_node *)malloc(sizeof(struct ll_node));
    pnew->data = x;
    pnew->next = NULL;
    if (head == NULL || head->data > x)
    {
        pnew->next = head;
        head = pnew;
        return;
    }
    hp = head;
    while (hp->next != NULL && hp->next->data < x)
    {
        hp = hp->next;
    }

    pnew->next = hp->next;
    hp->next = pnew;
}

void delete1(int x)
{
    struct ll_node *hp, *n2d;
    hp = head;
    if (hp != NULL)
    {
        if (hp->data == x)
        {
            n2d = hp;
            head = n2d->next;
            free(n2d);
            return;
        }
        while (hp->next != NULL)
        {
            if (hp->next->data == x)
            {
                n2d = hp->next;
                hp->next = n2d->next;
                free(n2d);
                return;
            }
            hp = hp->next;
        }
        printf("Element not found");
        return;
    }
    printf("List is Empty");
    return;
}

void main()
{
    insert(10);
    insert(11);
    insert(55);
    insert(66);
    insert(111);
    insert(1);
    insert(100);
    insert(5);
    insert(2);
    delete1(44);
    display();
}
