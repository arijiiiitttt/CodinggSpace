#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int front, rear;
    int *queue;
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
    q->queue = (int *)malloc(MAX * sizeof(int));
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->queue[++q->rear] = value;
        printf("Inserted %d\n", value);
    }
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Deleted %d\n", q->queue[q->front++]);
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->queue[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initialize(&q);
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
