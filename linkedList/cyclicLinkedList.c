#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = newNode; // Initially points to itself (circular)
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;

        // Go to last node
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Insert at end
void insertAtEnd(int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

// Insert after a given key
void insertAfter(int key, int value) {
    if (head == NULL) return;

    Node* temp = head;

    do {
        if (temp->data == key) {
            Node* newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    
    printf("Key %d not found.\n", key);
}

// Delete a node by value
void deleteNode(int value) {
    if (head == NULL) return;

    Node *current = head, *prev = NULL;

    // If head is to be deleted
    if (head->data == value) {
        if (head->next == head) {
            free(head);
            head = NULL;
            return;
        }

        Node* last = head;
        while (last->next != head)
            last = last->next;

        last->next = head->next;
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    // For non-head node
    do {
        prev = current;
        current = current->next;

        if (current->data == value) {
            prev->next = current->next;
            free(current);
            return;
        }

    } while (current != head);

    printf("Value %d not found.\n", value);
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Circular List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}

// Count number of nodes
int countNodes() {
    if (head == NULL)
        return 0;

    int count = 0;
    Node* temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

// Example usage
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtBeginning(5);
    insertAfter(10, 15);
    display(); // Should print: 5 -> 10 -> 15 -> 20 -> (head)

    printf("Total nodes: %d\n", countNodes());

    deleteNode(10);
    display(); // Should print updated list

    return 0;
}
