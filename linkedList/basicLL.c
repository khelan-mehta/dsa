/*
 * Singly Linked List Implementation in C
 *
 * This program demonstrates all fundamental operations on a singly linked list:
 * creation, insertion (at beginning, end, position, and after value), deletion
 * (first, last, by value), search, and display.
 *
 * Double pointers are avoided by returning the updated head node from each function.
 *
 * ---------------------------------------------------------------
 * ✅ Implemented Functions:
 *
 * - Node* createNode(int data)
 *     Creates and returns a new node with the given data.
 *
 * - Node* insertAtEnd(Node* head, int data)
 *     Inserts a node at the end of the list.
 *
 * - Node* insertAtBeginning(Node* head, int data)
 *     Inserts a node at the beginning of the list.
 *
 * - Node* insertAfter(Node* head, int targetValue, int newValue)
 *     Inserts a node after a node containing a specific value.
 *
 * - Node* insertAt(Node* head, int position, int data)
 *     Inserts a node at a specific 1-based position.
 *
 * - Node* deleteFirst(Node* head)
 *     Deletes the first node in the list.
 *
 * - Node* deleteLast(Node* head)
 *     Deletes the last node in the list.
 *
 * - Node* deleteNode(Node* head, int key)
 *     Deletes the first node containing the given value.
 *
 * - void search(Node* head, int data)
 *     Searches for a value and prints its 1-based position.
 *
 * - void printList(Node* head)
 *     Prints the entire list in order.
 *
 * ---------------------------------------------------------------
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Dynamically allocates memory for a new node and initializes its data and next pointer
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Inserts a node at the end of the linked list
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Inserts a node at the beginning of the linked list
Node* insertAtBeginning(Node* head, int data){
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Inserts a node after a node with a given value (first occurrence)
Node* insertAfter(Node* head, int inpdata, int value){
    Node* newNode = createNode(value);
    Node* temp = head;

    while (temp != NULL && temp->data != inpdata){
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("No such value in list to insert after.\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Inserts a node at a specific position (1-based index)
Node* insertAt(Node* head, int key, int value){
    Node* newNode = createNode(value);

    if (key == 1) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    int count = 1;

    while (temp != NULL && count != key - 1){
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position for insertion.\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Deletes the first node from the list
Node* deleteFirst(Node* head) {
    if (head == NULL) return NULL;

    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Deletes the last node in the list
Node* deleteLast(Node* head) {
    if (head == NULL) return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node* temp = head;
    while (temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}

// Deletes the first node with a given value
Node* deleteNode(Node* head, int key) {
    if (head == NULL) return NULL;

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->data != key) {
        curr = curr->next;
    }

    if (curr->next != NULL) {
        Node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
    } else {
        printf("Value %d not found in the list.\n", key);
    }

    return head;
}

// Prints the entire linked list
void printList(Node* head){
    Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Searches for a value in the list and prints its position (1-based)
void search(Node* head, int data){
    Node* temp = head;
    int position = 1;

    while (temp != NULL && temp->data != data){
        temp = temp->next;
        position++;
    }

    if (temp == NULL) {
        printf("Data %d not found in the list.\n", data);
    } else {
        printf("Data %d found at position %d.\n", data, position);
    }
}

// Driver function to test all operations
int main() {
    Node* head = NULL;

    // Initial list creation
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    printf("Initial list:\n");
    printList(head);

    // Deletion operations
    head = deleteFirst(head);
    head = deleteNode(head, 40);

    printf("\nAfter deleting first node and value 40:\n");
    printList(head);

    // Insertion operations
    head = insertAfter(head, 50, 100);
    printf("\nInserting 100 after 50:\n");
    printList(head);

    head = insertAtBeginning(head, 300);
    printf("\nInserting 300 at beginning:\n");
    printList(head);

    head = insertAt(head, 3, 69);
    printf("\nInserting 69 at position 3:\n");
    printList(head);

    head = deleteLast(head);
    printf("\nAfter deleting last node:\n");
    printList(head);

    // Search operation
    printf("\nSearching for value 69:\n");
    search(head, 69);

    return 0;
}
