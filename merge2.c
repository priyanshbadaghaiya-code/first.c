#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create new node
Node* newNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

// Merge two sorted lists
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->data < b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

// Print list
void print(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    // List 1
    Node* l1 = newNode(10);
    l1->next = newNode(20);
    l1->next->next = newNode(30);

    // List 2
    Node* l2 = newNode(15);
    l2->next = newNode(25);
    l2->next->next = newNode(35);

    Node* merged = merge(l1, l2);

    print(merged);

    return 0;
}
