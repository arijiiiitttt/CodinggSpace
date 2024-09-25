#include <stdio.h>
#define SIZE 5

struct CircularQueue {
    int items[SIZE];
    int front, rear;
};

void enqueue(struct CircularQueue* q, int value) {
    if ((q->rear + 1) % SIZE == q->front)
        printf("Queue is full!\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear = (q->rear + 1) % SIZE;
        q->items[q->rear] = value;
        printf("Inserted %d\n", value);
    }
}

int dequeue(struct CircularQueue* q) {
    int item;
    if (q->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        item = q->items[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % SIZE;
        }
        printf("Removed %d\n", item);
        return item;
    }
}

int main() {
    struct CircularQueue q;
    q.front = q.rear = -1;
    enqueue(&q, 10);
    enqueue(&q, 20);
    dequeue(&q);
    dequeue(&q);
    return 0;
}
