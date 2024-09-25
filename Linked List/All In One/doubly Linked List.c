#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete a node from the front of the doubly linked list
void deleteFromFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    printf("Node deleted from the front.\n");
}

// Function to delete a node from the end of the doubly linked list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL; // List had only one node
    }
    free(temp);
    printf("Node deleted from the end.\n");
}

// Function to print the doubly linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to push a node to the front of the doubly linked list
void push(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head);
    if ((*head) != NULL) {
        (*head)->prev = new_node;
    }
    (*head) = new_node;
}

int main() {
    struct Node* head = NULL;

    // Create a doubly linked list: 10 <-> 20 <-> 30
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);

    printf("Original list: ");
    printList(head);

    deleteFromFront(&head);
    printf("After deleting from front: ");
    printList(head);

    deleteFromEnd(&head);
    printf("After deleting from end: ");
    printList(head);

    return 0;
}
