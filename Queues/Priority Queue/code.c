#include <stdio.h>
#define SIZE 5

struct PriorityQueue {
    int items[SIZE];
    int priorities[SIZE];
    int front, rear;
};

void enqueue(struct PriorityQueue* q, int value, int priority) {
    if (q->rear == SIZE - 1)
        printf("Queue is full!\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        q->priorities[q->rear] = priority;
        printf("Inserted %d with priority %d\n", value, priority);
    }
}

int dequeue(struct PriorityQueue* q) {
    int item, highestPriorityIndex = q->front;
    if (q->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        for (int i = q->front; i <= q->rear; i++) {
            if (q->priorities[i] > q->priorities[highestPriorityIndex]) {
                highestPriorityIndex = i;
            }
        }
        item = q->items[highestPriorityIndex];
        for (int i = highestPriorityIndex; i < q->rear; i++) {
            q->items[i] = q->items[i + 1];
            q->priorities[i] = q->priorities[i + 1];
        }
        q->rear--;
        if (q->rear < q->front) {
            q->front = q->rear = -1;
        }
        printf("Removed %d\n", item);
        return item;
    }
}

int main() {
    struct PriorityQueue q;
    q.front = q.rear = -1;
    enqueue(&q, 10, 2);
    enqueue(&q, 20, 1);
    dequeue(&q);
    dequeue(&q);
    return 0;
}
