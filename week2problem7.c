#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *reverseList(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *current = head;

    while (current != NULL) {
        struct Node *nextNode = current->next; // Save next node
        current->next = prev;                  // Reverse link
        prev = current;                        // Move prev forward
        current = nextNode;                    // Move current forward
    }

    return prev; // New head
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
    struct Node *first = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printf("Original list: ");
    displayList(first);

    first = reverseList(first);

    printf("Reversed list: ");
    displayList(first);

    freeList(first);
    return 0;
}