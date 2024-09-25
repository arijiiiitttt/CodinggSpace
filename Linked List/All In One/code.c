#include <stdio.h>
#include <stdlib.h>

// Node structure for Singly Linked List
struct Node {
    int data;
    struct Node* next;
};

// Node structure for Doubly Linked List
struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
};

// Node structure for Circular Linked List
struct CNode {
    int data;
    struct CNode* next;
};

// Function prototypes for Singly Linked List
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void deleteNode(struct Node** head, int key);
void searchNode(struct Node* head, int key);
void displayList(struct Node* head);

// Function prototypes for Doubly Linked List
void insertAtBeginningD(struct DNode** head, int data);
void insertAtEndD(struct DNode** head, int data);
void deleteNodeD(struct DNode** head, int key);
void searchNodeD(struct DNode* head, int key);
void displayListD(struct DNode* head);

// Function prototypes for Circular Linked List
void insertAtBeginningC(struct CNode** head, int data);
void insertAtEndC(struct CNode** head, int data);
void deleteNodeC(struct CNode** head, int key);
void searchNodeC(struct CNode* head, int key);
void displayListC(struct CNode* head);

// Main function
int main() {
    int choice, type, data, key;
    struct Node* headS = NULL;
    struct DNode* headD = NULL;
    struct CNode* headC = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Singly Linked List\n");
        printf("2. Doubly Linked List\n");
        printf("3. Circular Linked List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) break;

        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Node\n");
        printf("4. Search Node\n");
        printf("5. Display List\n");
        printf("Enter your operation: ");
        scanf("%d", &type);

        switch (choice) {
            case 1: // Singly Linked List
                switch (type) {
                    case 1:
                        printf("Enter data: ");
                        scanf("%d", &data);
                        insertAtBeginning(&headS, data);
                        break;
                    case 2:
                        printf("Enter data: ");
                        scanf("%d", &data);
                        insertAtEnd(&headS, data);
                        break;
                    case 3:
                        printf("Enter key to delete: ");
                        scanf("%d", &key);
                        deleteNode(&headS, key);
                        break;
                    case 4:
                        printf("Enter key to search: ");
                        scanf("%d", &key);
                        searchNode(headS, key);
                        break;
                    case 5:
                        displayList(headS);
                        break;
                }
                break;
            case 2: // Doubly Linked List
                switch (type) {
                    case 1:
                        printf("Enter data: ");
                        scanf("%d", &data);
                        insertAtBeginningD(&headD, data);
                        break;
                    case 2:
                        printf("Enter data: ");
                        scanf("%d", &data);
                        insertAtEndD(&headD, data);
                        break;
                    case 3:
                        printf("Enter key to delete: ");
                        scanf("%d", &key);
                        deleteNodeD(&headD, key);
                        break;
                    case 4:
                        printf("Enter key to search: ");
                        scanf("%d", &key);
                        searchNodeD(headD, key);
                        break;
                    case 5:
                        displayListD(headD);
                        break;
                }
                break;
            case 3: // Circular Linked List
                switch (type) {
                    case 1:
                        printf("Enter data: ");
                        scanf("%d", &data);
                        insertAtBeginningC(&headC, data);
                        break;
                    case 2:
                        printf("Enter data: ");
                        scanf("%d", &data);
                        insertAtEndC(&headC, data);
                        break;
                    case 3:
                        printf("Enter key to delete: ");
                        scanf("%d", &key);
                        deleteNodeC(&headC, key);
                        break;
                    case 4:
                        printf("Enter key to search: ");
                        scanf("%d", &key);
                        searchNodeC(headC, key);
                        break;
                    case 5:
                        displayListC(headC);
                        break;
                }
                break;
        }
    }

    return 0;
}

// Function definitions for Singly Linked List
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void searchNode(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Node found with data %d\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Node not found\n");
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function definitions for Doubly Linked List
void insertAtBeginningD(struct DNode** head, int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtEndD(struct DNode** head, int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    struct DNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNodeD(struct DNode** head, int key) {
    struct DNode* temp = *head;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

void searchNodeD(struct DNode* head, int key) {
    struct DNode* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Node found with data %d\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Node not found\n");
}

void displayListD(struct DNode* head) {
    struct DNode* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function definitions for Circular Linked List
void insertAtBeginningC(struct CNode** head, int data) {
    struct CNode* newNode = (struct CNode*)malloc(sizeof(struct CNode));
    newNode->data = data;
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct CNode* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEndC(struct CNode** head, int data) {
    struct CNode* newNode = (struct CNode*)malloc(sizeof(struct CNode));
    newNode->data = data;
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct CNode* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

void deleteNodeC(struct CNode** head, int key) {
    if (*head == NULL) return;

    struct CNode *temp = *head, *prev = NULL;

    if (temp->data == key && temp->next == *head) {
        *head = NULL;
        free(temp);
        return;
    }

    while (temp->data != key) {
        if (temp->next == *head) return;
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head) {
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = temp->next;
        prev->next = *head;
    } else if (temp->next == *head) {
        prev->next = *head;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void searchNodeC(struct CNode* head, int key) {
    struct CNode* temp = head;
    if (head == NULL) {
        printf("Node not found\n");
        return;
    }
    do {
        if (temp->data == key) {
            printf("Node found with data %d\n", key);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Node not found\n");
}

void displayListC(struct CNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct CNode* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}
