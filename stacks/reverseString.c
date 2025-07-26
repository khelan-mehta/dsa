#include <stdio.h>
#include <string.h>
#define MAX 100

// Stack structure
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Initialize the stack
void init(Stack* s) {
    s->top = -1;
}

// Check if stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Check if stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push a character onto the stack
void push(Stack* s, char c) {
    if (!isFull(s)) {
        s->items[++(s->top)] = c;
    }
}

// Pop a character from the stack
char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0'; // return null character if stack is empty
}

// Reverse the string using stack
void reverseString(char* str) {
    Stack s;
    init(&s);

    // Push all characters to the stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }

    // Pop all characters from the stack back into the string
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = pop(&s);
    }
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Remove newline character from fgets
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
