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



void printList(Node* head){
    Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Reverse the linked list
Node* reverseList(Node* head) {
    Node* temp1 = head;
    Node* temp2 = head->next;
    Node* temp3 = NULL;
    
    while (temp2 != NULL) {
        temp1->next = temp3;
        temp3 = temp1;
        temp1 = temp2;
        temp2 = temp2->next;
    }
    head = temp1;
    head->next = temp3;
    return head;
}

/**
 * Sorts a singly linked list using bubble sort.
 *
 * @param head Pointer to the head of the linked list.
 * @return Pointer to the head of the sorted linked list.
 */
Node* bubbleSortLinkedList(Node* head) {
    // Handle empty list or single node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Get list length
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    // Bubble sort
    for (int i = 0; i < length - 1; i++) {
        Node* temp1 = head;
        Node* temp2 = head->next;
        for (int j = 0; j < length - i - 1 && temp2 != NULL; j++) {
            if (temp1->data > temp2->data) {
                // Swap data
                int temp3 = temp1->data;
                temp1->data = temp2->data;
                temp2->data = temp3;
            }
            temp1 = temp2;
            temp2 = temp2->next;
        }
    }
    return head;
}

/**
 * Merges two sorted singly linked lists into a single sorted linked list.
 *
 * @param head1 Pointer to the head of the first sorted linked list.
 * @param head2 Pointer to the head of the second sorted linked list.
 * @return Pointer to the head of the merged sorted linked list.
 */
Node* mergeLists(Node* head1, Node* head2) {
    // Handle empty list cases
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* mergedHead = NULL;
    // Choose smaller head as starting point
    if (head1->data <= head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } else {
        mergedHead = head2;
        head2 = head2->next;
    }

    Node* current = mergedHead;
    // Merge lists by comparing node values
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    // Append remaining nodes
    if (head1 != NULL) {
        current->next = head1;
    } else {
        current->next = head2;
    }

    return mergedHead;
}

int main() {
    Node* head = NULL;
    Node* head1 = NULL;
    Node* head2 = NULL;

    // Initial list creation
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    
    head1 = insertAtEnd(head, 10);
    head1 = insertAtEnd(head, 20);
    head1 = insertAtEnd(head, 30);
    head1 = insertAtEnd(head, 40);
    head1 = insertAtEnd(head, 50);
    
    head2 = insertAtEnd(head, 10);
    head2 = insertAtEnd(head, 40);
    head2 = insertAtEnd(head, 70);
    head2 = insertAtEnd(head, 90);
    head2 = insertAtEnd(head, 100);
    
    printf("Initial list:\n");
    printList(head);
    head = reverseList(head);
    printf("Reversed list:\n");
    printList(head);
    head = bubbleSortLinkedList(head);
    printf("Sorted list:\n");
    printList(head);

    Node* mergedHead = mergeLists(head1, head2);
    printf("Merged list:\n");
    printList(mergedHead);
    
    

    return 0;
}