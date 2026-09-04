#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Create a new node */
struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Insert at the end */
void insertAtEnd(int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

/* Insert at the beginning */
void insertAtBeginning(int data) {
    struct Node *newNode = createNode(data);

    newNode->next = head;
    head = newNode;
}

/* Delete first node containing data */
void deleteNode(int data) {
    if (head == NULL) {
        return;
    }

    if (head->data == data) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node *current = head;

    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }

    if (current->next != NULL) {
        struct Node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

/* Print the list */
void displayList() {
    struct Node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

/* Free all nodes */
void freeList() {
    struct Node *current = head;

    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    head = NULL;
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtBeginning(5);

    printf("Linked List: ");
    displayList();

    deleteNode(10);

    printf("After deletion: ");
    displayList();

    freeList();
    return 0;
}