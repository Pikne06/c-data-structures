#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void init(Stack *stack)
{
    stack->top = -1;
}

bool isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;

}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push (Stack *stack, int value)
{
    if (isFull(stack)) {
        printf("Stack is full.\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
}

void pop (Stack *stack)
{
    if (isEmpty(stack)) {
        printf ("Stack is empty.\n");
        return;
    }
    stack->top--;
}

void peek (Stack *stack)
{
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", stack->arr[stack->top]);
}

int main(void)
{
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    peek(&s);   // Top element: 30

    pop(&s);
    peek(&s);   // Top element: 20

    return 0;
}