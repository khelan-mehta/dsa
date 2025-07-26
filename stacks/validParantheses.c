#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for stack
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Stack using linked list
typedef struct {
    Node* top;
} stack;

// Initialize stack
void init(stack* s) {
    s->top = NULL;
}

// Check if stack is empty
bool isEmpty(stack* s) {
    return s->top == NULL;
}

// Push a character
void push(stack* s, char c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = c;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop a character
char pop(stack* s) {
    if (isEmpty(s)) return '\0';

    Node* temp = s->top;
    char popped = temp->data;
    s->top = temp->next;
    free(temp);
    return popped;
}

// Check if brackets match
bool isMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Leetcode solution using linked list stack
bool isValid(char* str) {
    stack st;
    init(&st);

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&st, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&st) || !isMatch(pop(&st), c)) {
                return false;
            }
        }
    }

    return isEmpty(&st);  // Should be empty if valid
}

// Testing
int main() {
    char s[100];
    printf("Enter string: ");
    scanf("%s", s);

    if (isValid(s))
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}
