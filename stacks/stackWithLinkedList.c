#include <stdio.h>
#include <stdlib.h>

// Typedef for Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Stack top pointer
Node* top = NULL;

// PUSH: Add to top
void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed: %d\n", value);
}

// POP: Remove from top
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    Node* temp = top;
    printf("Popped: %d\n", top->data);
    top = top->next;
    free(temp);
}

// PEEK: Top element
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

// EDGE: Bottom element
void edge() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = top;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Bottom element (Edge): %d\n", temp->data);
}

// DISPLAY
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = top;
    printf("Stack (Top to Bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// MAIN
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Edge\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            edge();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
