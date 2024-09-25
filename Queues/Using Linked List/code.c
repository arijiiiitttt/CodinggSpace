#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void insert() {
    int value;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow \n");
        return;
    }
    printf("Insert the element in queue : ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    if (front == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void delete() {
    struct Node* temp;
    if (front == NULL) {
        printf("Queue Underflow \n");
        return;
    } else {
        temp = front;
        front = front->next;
        printf("Element deleted from queue is : %d\n", temp->data);
        free(temp);
    }
}

void display() {
    struct Node* temp;
    if (front == NULL)
        printf("Queue is empty \n");
    else {
        temp = front;
        printf("Queue elements are : \n");
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice \n");
        }
    }
    return 0;
}
