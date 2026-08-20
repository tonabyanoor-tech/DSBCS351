#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* Position starts from 1 */
void deleteFromKthPosition(struct Node **head, int k) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    if (k < 1) {
        printf("Invalid position.\n");
        return;
    }

    /* Delete first node */
    if (k == 1) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    /* Reach the (k-1)th node */
    struct Node *temp = *head;
    for (int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position %d is invalid.\n", k);
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        return;
    }

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
    insertAtEnd(&head, 40);

    printf("Before deletion: ");
    display(head);

    deleteFromKthPosition(&head, 3);

    printf("After deleting position 3: ");
    display(head);

    freeList(head);
    return 0;
}