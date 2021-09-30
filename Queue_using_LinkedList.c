#include <stdio.h>
#include <stdlib.h>
// global Variables
struct Node *front = NULL;
struct Node *rear = NULL;

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

int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
        return 1;
    return 0;
}

int isFull(struct Node *ptr)
{
    if (ptr == NULL)
        return 1;
    return 0;
}

void Enqueue(int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (isFull(n))
        printf("Queue is Full\n");
    else
    {
        n->data = value;
        n->next = NULL;

        // checking if the list is empty and this is the first node in the list
        if (front == NULL)
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }
}

int Dequeue()
{
    int value = -1;
    struct Node *n = front;
    if (isEmpty(front))
        printf("List is Empty\n");
    else
    {
        front = front->next;
        value = n->data;
        free(n);
    }
    return value;
}

int main()
{
    printf("Dequeue: %d\n", Dequeue());
    Enqueue(8);
    Enqueue(14);
    Enqueue(55);
    traversal(front);
    printf("Dequeue: %d\n", Dequeue());
    printf("Dequeue: %d\n", Dequeue());
    printf("Dequeue: %d\n", Dequeue());
    printf("Dequeue: %d\n", Dequeue());
    printf("Dequeue: %d\n", Dequeue());
    

    return 0;
}