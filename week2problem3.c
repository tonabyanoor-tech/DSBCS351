#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Insert a node at the beginning */
struct Node *insertAtBeginning(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;   // New head
}

/* Insert a node at the end */
struct Node *insertAtEnd(struct Node *head, int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    struct Node *current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

void displayList(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct Node *head) {
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;

    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    displayList(head);  // 10 -> 20 -> 30 -> 40 -> NULL

    freeList(head);
    return 0;
}