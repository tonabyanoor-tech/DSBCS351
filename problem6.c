#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* Position starts from 1 */
void insertAtKthPosition(struct Node **head, int value, int k) {
    if (k < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;

    /* Insert at beginning */
    if (k == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    /* Reach the (k-1)th node */
    struct Node *temp = *head;
    for (int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is invalid.\n", k);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
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

    insertAtKthPosition(&head, 10, 1);
    insertAtKthPosition(&head, 30, 2);
    insertAtKthPosition(&head, 20, 2);  // Insert 20 at position 2

    printf("Linked List: ");
    display(head);

    freeList(head);
    return 0;
}