#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct CircularQueue *ptr)
{
    if (((ptr->rear + 1) % ptr->size) == ptr->front)
        return 1;
    return 0;
}

int isEmpty(struct CircularQueue *ptr)
{
    if (ptr->rear == ptr->front)
        return 1;
    return 0;
}

void Enqueue(struct CircularQueue *ptr, int value)
{
    if (isFull(ptr))
        printf("Queue Overflow\n");
    else
    {
        ptr->rear = (ptr->rear + 1) % ptr->size; // circular Increment
        ptr->arr[ptr->rear] = value;
        printf("Inserted %d at %d\n", value, ptr->rear);
    }
}

int Dequeue(struct CircularQueue *ptr)
{
    int value = -1;
    if (isEmpty(ptr))
        printf("Queue UnderFlow\n");
    else
    {
        ptr->front = (ptr->front + 1) % ptr->size; // circular increment
        value = ptr->arr[ptr->front];
    }
    return value;
}

int main()
{
    struct CircularQueue c;
    c.size = 5;
    c.front = c.rear = 0;
    c.arr = (int *)malloc((c.size) * sizeof(int));
    Enqueue(&c, 19);
    Enqueue(&c, 19);
    Enqueue(&c, 19);
    Enqueue(&c, 19);
    Dequeue(&c);
    Enqueue(&c, 19);
    Dequeue(&c);
    Dequeue(&c);
    Dequeue(&c);
    Dequeue(&c);
    Dequeue(&c);
    Dequeue(&c);
    Dequeue(&c);
    
    return 0;
}