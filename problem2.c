#include <stdio.h>

#define MAX 10

struct Node {
    int data;
    int next;   // stores index of next node
};

struct Node list[MAX];
int head = -1;
int freeIndex = 0;

void initialize() {
    for (int i = 0; i < MAX - 1; i++) {
        list[i].next = i + 1;
    }
    list[MAX - 1].next = -1;
}

void insertAtEnd(int value) {
    if (freeIndex == -1) {
        printf("List is full.\n");
        return;
    }

    int newNode = freeIndex;
    freeIndex = list[freeIndex].next;

    list[newNode].data = value;
    list[newNode].next = -1;

    if (head == -1) {
        head = newNode;
        return;
    }

    int temp = head;
    while (list[temp].next != -1) {
        temp = list[temp].next;
    }
    list[temp].next = newNode;
}

void display() {
    if (head == -1) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    int temp = head;

    while (temp != -1) {
        printf("%d -> ", list[temp].data);
        temp = list[temp].next;
    }
    printf("NULL\n");
}

void deleteValue(int value) {
    if (head == -1) {
        printf("List is empty.\n");
        return;
    }

    int current = head;
    int previous = -1;

    while (current != -1 && list[current].data != value) {
        previous = current;
        current = list[current].next;
    }

    if (current == -1) {
        printf("%d not found.\n", value);
        return;
    }

    if (previous == -1) {
        head = list[current].next;
    } else {
        list[previous].next = list[current].next;
    }

    /* Return deleted node to the free list */
    list[current].next = freeIndex;
    freeIndex = current;
}

int main() {
    initialize();

    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    display();

    deleteValue(20);
    display();

    return 0;
}