#include <stdio.h>  // This lets us use printf to show things on screen
#include <stdlib.h> // This lets us use malloc to get memory space

// Think of this like a train car that can connect to other cars
// Each car (Node) holds a number and knows about the car in front and behind it
typedef struct Node{
    int data;               // The number stored in this train car
    struct Node* next;      // Points to the next train car (like holding hands with the car behind)
    struct Node* prev;      // Points to the previous train car (like holding hands with the car in front)
} Node;

// FUNCTION: createNode - Makes a brand new train car
// Think of this like building a new LEGO piece that can connect to others
Node* createNode(int data){
    // Ask the computer for space to build our train car
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    // Set up our new train car
    newNode->next = NULL;   // Not connected to any car behind yet
    newNode->prev = NULL;   // Not connected to any car in front yet  
    newNode->data = data;   // Put our number in the train car
    
    return newNode;         // Give back our shiny new train car
}

// FUNCTION: insertAtEnd - Adds a new train car at the very end of our train
// Like adding a caboose to the back of a train
Node* insertAtEnd(Node* head, int data){
    Node* temp = head;              // Start at the front of the train
    Node* newNode = createNode(data); // Build our new train car
    
    // If we don't have a train yet, this car becomes the whole train!
    if (head == NULL) return newNode;
    
    // Walk to the very last car of our train (like walking through train cars)
    while(temp->next != NULL){
        temp = temp->next;  // Keep walking until we reach the last car
    }
    
    // Connect our new car to the end
    temp->next = newNode;           // Last car now points to our new car
    temp->next->prev = temp;        // Our new car points back to the old last car
    
    return head;  // Give back the front of our train
}

// FUNCTION: insertAtbeginning - Adds a new train car at the very front
// Like adding a new engine to the front of a train
Node* insertAtbeginning(Node* head, int data){
    Node* newNode = createNode(data);  // Build our new train car
    
    newNode->next = head;              // Our new car points to the old first car
    newNode->next->prev = newNode;     // The old first car now points back to our new car
    head = newNode;                    // Our new car is now the first car!
    
    return head;  // Give back the front of our train
}

// FUNCTION: insertAtPosition - Adds a new train car at a specific spot in the middle
// Like squeezing a new car between two existing cars in a train
Node* insertAtPosition(Node* head, int position, int data){
    Node* newNode = createNode(data);  // Build our new train car
    Node* temp = head;                 // Start at the front
    int count = 0;                     // Keep track of which car we're at
    
    // Walk to the spot just before where we want to insert (like counting cars)
    while(count < position - 2){
        temp = temp -> next;  // Move to the next car
    }
    
    // Now we need to squeeze our new car between temp and temp->next
    // It's like carefully connecting LEGO pieces in the middle of a chain
    temp->next->prev = newNode;  // The car after temp now points back to our new car
    newNode->next = temp->next;  // Our new car points forward to the car after temp
    newNode->prev = temp;        // Our new car points back to temp
    temp->next = newNode;        // temp now points forward to our new car
    
    return head;
}

// FUNCTION: deletefirst - Removes the first train car (like removing the engine)
Node* deletefirst (Node* head) {
    Node* temp = head;        // Remember which car we're removing
    head = head->next;        // The second car becomes the new first car
    head->prev = NULL;        // The new first car doesn't point back to anything
    free(temp);               // Throw away the old first car (give memory back)
    return head;              // Give back the new front of our train
}

// FUNCTION: deleteLast - Removes the last train car (like removing the caboose)
Node* deleteLast (Node* head) {
    Node* temp = head;  // Start at the front
    
    // Walk to the second-to-last car (we stop one before the end)
    while(temp->next->next != NULL){
        temp = temp -> next;  // Keep walking
    }
    
    Node* temp2 = temp->next;   // Remember the last car so we can throw it away
    temp->next = NULL;          // The second-to-last car is now the last car
    free(temp2);                // Throw away the old last car
    return head;
}

// FUNCTION: deleteAtPosition - Removes a train car from a specific spot
// Like carefully removing one car from the middle of a train
Node* deleteAtPosition (Node* head, int position ) {
    Node* temp = head;  // Start at the front
    int count = 0;      // Keep track of which car we're at
    
    // Walk to the car just before the one we want to remove
    while(count < position - 2){
        temp = temp->next;  // Move to the next car
        count = count + 1;  // Count which car we're at
    }
    
    // Now temp points to the car before the one we want to delete
    Node* temp2 = temp->next;              // Remember the car we're deleting
    temp->next->next->prev = temp;         // The car after the deleted one points back to temp
    temp->next = temp->next->next;         // temp now points to the car after the deleted one
    free(temp2);                           // Throw away the car we deleted
    return head;
}

// FUNCTION: reverseList - Turns the whole train around!
// Like making the caboose become the engine and the engine become the caboose
Node* reverseList(Node* head){
    Node* current = head;       // The car we're currently flipping
    Node* prev = NULL;          // The car behind us (starts as nothing)
    Node* next = head->next;    // The car in front of us
    
    // Go through each car and flip its connections
    while(next != NULL){
        current->next = prev;    // This car now points backward instead of forward
        current->prev = next;    // This car now points forward instead of backward
        
        // Move to the next car
        prev = current;          // The car we just flipped becomes the "previous" one
        current = next;          // Move to the next car
        next = next->next;       // Look ahead to the car after that
    }
    
    // Fix up the last car (which becomes our new first car)
    head = current;              // The last car is now our new first car
    head->next = prev;           // Connect it to what used to be the second-to-last car
    return head;
}

// FUNCTION: printLinkedList - Shows all the train cars and their numbers
// Like walking through the train and calling out what's in each car
void printLinkedList(Node* head){
    Node* temp = head;  // Start at the front car
    
    // Walk through each car and show its number
    while(temp != NULL){
        printf("%d <->", temp->data);  // Show the number in this car with arrows
        temp = temp->next;             // Move to the next car
    }
    return;
}

// MAIN FUNCTION - This is where our program starts running
// Think of this as the conductor organizing the whole train
int main(){
    Node* head = NULL;  // Start with no train at all
    
    // Build our train step by step and watch what happens:
    head = insertAtEnd(head, 10);        // Add car with 10 at the end
    head = insertAtEnd(head, 20);        // Add car with 20 at the end  
    head = insertAtEnd(head, 30);        // Add car with 30 at the end
    head = insertAtEnd(head, 40);        // Add car with 40 at the end
    head = insertAtbeginning(head, 50);  // Add car with 50 at the front
    head = insertAtPosition(head, 2, 69); // Add car with 69 at position 2
    head = deletefirst(head);            // Remove the first car
    head = deleteLast(head);             // Remove the last car  
    head = deleteAtPosition(head, 3);    // Remove the car at position 3
    head = reverseList(head);            // Turn the whole train around!
    
    printLinkedList(head);  // Show us what our final train looks like
    return 0;               // Tell the computer we're done
}