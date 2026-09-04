#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *deleteFromBeginning(struct Node *head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

struct Node *deleteFromEnd(struct Node *head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *current = head;

    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;

    return head;
}

/* position starts from 1 */
struct Node *deleteAtPosition(struct Node *head, int position) {
    if (head == NULL || position <= 0) {
        return head;
    }

    if (position == 1) {
        return deleteFromBeginning(head);
    }

    struct Node *current = head;

    for (int i = 1; i < position - 1 && current->next != NULL; i++) {
        current = current->next;
    }

    if (current->next != NULL) {
        struct Node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    return head;
}