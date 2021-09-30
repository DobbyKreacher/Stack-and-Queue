#include <stdio.h>
#include <stdlib.h>

// Array as an Abstract Data Type
struct Queue
{
    int size;
    int front;
    int rear;
    int *arr; // For dynamic allocation according to the size
};

int isFull(struct Queue *ptr)
{
    if (ptr->rear == ptr->size - 1)
        return 1;
    return 0;
}

int isEmpty(struct Queue *ptr)
{
    if (ptr->front == ptr->rear)
        return 1;
    return 0;
}

void Enqueue(struct Queue *ptr, int value)
{
    if (isFull(ptr))
        printf("Cannot Insert\n");
    else
    {
        ptr->rear++;
        ptr->arr[ptr->rear] = value;
        printf("Inserted %d at %d\n", value, ptr->rear);
    }
}

int Dequeue(struct Queue *ptr)
{
    int a = -1;
    if (isEmpty(ptr))
        printf("Cannot Remove\n");
    else
    {
        ptr->front++;
        a = ptr->arr[ptr->front];
    }
    return a;
}

int main()
{
    struct Queue q;
    q.size = 100;
    q.front = q.rear = -1;
    q.arr = (int *)malloc((q.size) * sizeof(int));
    Enqueue(&q, 8); // passing &q because we have to pass the whole structure
    Enqueue(&q, 2);
    printf("Dequeue: %d\n", Dequeue(&q));
    printf("Dequeue: %d\n", Dequeue(&q));
    printf("Dequeue: %d\n", Dequeue(&q));
    return 0;
}