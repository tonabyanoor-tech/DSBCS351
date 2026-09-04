#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* Returns the 1-based position, or -1 if not found */
int searchElement(struct Node *head, int key) {
    int position = 1;

    while (head != NULL) {
        if (head->data == key) {
            return position;
        }

        head = head->next;
        position++;
    }

    return -1;
}

int main() {
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    int key = 20;
    int position = searchElement(head, key);

    if (position == -1) {
        printf("%d not found\n", key);
    } else {
        printf("%d found at position %d\n", key, position);
    }

    free(head);
    free(second);
    free(third);

    return 0;
}