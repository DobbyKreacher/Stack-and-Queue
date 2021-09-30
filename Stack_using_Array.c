#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr; // to dynamically allocate memory for array
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0; // when the if condition fails the fuction will return 0. When the if condition passes, the function will not execute this statement
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void Push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("Pushed: %d\n", ptr->arr[ptr->top]);
    }
}

int Pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int Peek(struct stack *ptr, int index)
{
    int value = ptr->top - index + 1;
    if (value < 0)
    {
        printf("Not a valid Position");
        return -1;
    }
    else
    {
        return ptr->arr[value];
    }
}

int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr){
    return ptr->arr[0];
}

int main()
{
    // here we are using pointer instead of struct object because it is easy to call by reference
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    ;
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc((s->size) * sizeof(int));
    Push(s, 14);
    Push(s, 90);
    Push(s, 100);
    Push(s, 1);
    Pop(s);

    for (int j = 1; j <= s->top+1; j++)
    {
        printf("Element at postion %d is %d\n", j, Peek(s, j));
    }

    printf("Top Element of Stack: %d\n", stackTop(s));
    printf("Bottom Element of Stack: %d\n", stackBottom(s));
    return 0;
}