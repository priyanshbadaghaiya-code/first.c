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

// Print list
void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Delete given value
Node* deleteNode(Node* head, int val) {
    Node *temp = head, *prev = NULL;

    // If head contains value
    if (temp != NULL && temp->data == val) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search value
    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

int main() {
    // Fixed linked list
    Node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);
    head->next->next->next->next = newNode(50);

    printf("Linked List: ");
    printList(head);

    int val;
    printf("Enter value to delete: ");
    scanf("%d", &val);

    head = deleteNode(head, val);

    printf("Updated List: ");
    printList(head);

    return 0;
}
