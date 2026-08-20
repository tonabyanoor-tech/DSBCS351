#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void deleteFromBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;   // Move head to next node
    free(temp);              // Delete old first node
}

void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(struct Node *head) {
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

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Before deletion: ");
    display(head);

    deleteFromBeginning(&head);

    printf("After deletion:  ");
    display(head);

    freeList(head);
    return 0;
}