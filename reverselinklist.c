#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert node at the beginning
void insert(struct Node** ptr, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *ptr;
    *ptr = newNode;
}

// Function to reverse the linked list
struct Node* reverse(struct Node* ptr) {
    struct Node *prev = NULL, *curr = ptr, *next = NULL;

    while (curr != NULL) {
        next = curr->next;     // Store next node
        curr->next = prev;     // Reverse pointer
        prev = curr;           // Move prev ahead
        curr = next;           // Move curr ahead
    }

    return prev; // New head
}

// Function to print linked list
void printList(struct Node* ptr) {
    while (ptr != NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct Node* ptr = NULL;

    insert(&ptr, 10);
    insert(&ptr, 20);
    insert(&ptr, 30);
    insert(&ptr, 40);

    printf("Original List: ");
    printList(ptr);

    ptr = reverse(ptr);

    printf("Reversed List: ");
    printList(ptr);

    return 0;
}
