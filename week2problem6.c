#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int countNodes(struct Node *head) {
    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
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

    printf("Number of nodes: %d\n", countNodes(first));

    free(first);
    free(second);
    free(third);

    return 0;
}