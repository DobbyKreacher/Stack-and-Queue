#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node *push(struct Node *top, int x)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

struct Node *pop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = top;
        top = top->next;
        int x = n->data;
        free(n);
        printf("Popped: %d\n", x);
        return top;
    }
}

int peek(struct Node *top, int position)
{
    struct Node *ptr = top;
    for (int i = 0; (i < position - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    return -1;
}

int main()
{
    struct Node *top = NULL;
    top = push(top, 11);
    top = push(top, 12);
    top = push(top, 15);
    // top = pop(top);
    traversal(top);

    printf("Value at position 3 is %d\n", peek(top, 3));

    return 0;
}