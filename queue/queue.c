
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void init(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

bool isFull(Queue *q)
{
    return (q->rear + 1) % MAX_SIZE == q->front;
}

bool isEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q)) {
        printf(\"Queue is full.\n\");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;
    printf(\"Element enqueued successfully: %d\\n\", value);
}

void dequeue(Queue *q)
{
    if (isEmpty(q)) {
        printf(\"Queue is empty.\n\");
        return;
    }
    int dequeued_value = q->items[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    if (q->front == (q->rear + 1) % MAX_SIZE) {
        q->front = -1;
        q->rear = -1;
    }
    printf(\"Element dequeued successfully: %d\\n\", dequeued_value);
}

void peek(Queue *q)
{
    if (isEmpty(q)) {
        printf(\"Queue is empty.\n\");
        return;
    }
    printf(\"Front element: %d\\n\", q->items[q->front]);
}

int size(Queue *q) {
    if (isEmpty(q)) return 0;
    return (q->rear - q->front + MAX_SIZE) % MAX_SIZE + 1;
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf(\"Queue is empty.\n\");
        return;
    }
    int i = q->front;
    do {
        printf(\"%d \", q->items[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (q->rear + 1) % MAX_SIZE);
    printf(\"\\n\");
}

void clearQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
    printf(\"Queue cleared.\n\");
}

int main(void)
{
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    displayQueue(&q);   // Display elements: 10 20 30

    peek(&q);   // Front element: 10

    dequeue(&q);
    displayQueue(&q);   // Display elements: 20 30

    printf(\"Size of queue: %d\\n\", size(&q));   // Size: 2

    clearQueue(&q);
    displayQueue(&q);   // Queue is empty.

    return 0;
}

