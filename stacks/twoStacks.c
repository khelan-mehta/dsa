#include <stdio.h>
#include <limits.h>

#define MAX 100

int mainStack[MAX];
int minStack[MAX];
int topMain = -1;
int topMin = -1;

// Push operation
void push(int x) {
    if (topMain == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    mainStack[++topMain] = x;

    if (topMin == -1 || x <= minStack[topMin]) {
        minStack[++topMin] = x;
    }

    printf("Pushed %d\n", x);
}

// Pop operation
int pop() {
    if (topMain == -1) {
        printf("Stack Underflow\n");
        return -1;
    }

    int popped = mainStack[topMain--];

    if (popped == minStack[topMin]) {
        topMin--;
    }

    printf("Popped %d\n", popped);
    return popped;
}

// Peek (top) operation
int peek() {
    if (topMain == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return mainStack[topMain];
}

// Get minimum in O(1)
int getMin() {
    if (topMin == -1) {
        printf("Stack is empty\n");
        return INT_MAX;
    }
    return minStack[topMin];
}

// Main function to test
int main() {
    push(10);
    push(20);
    printf("Current Min: %d\n", getMin()); // 10

    push(5);
    printf("Current Min: %d\n", getMin()); // 5

    pop(); // removes 5
    printf("Current Min: %d\n", getMin()); // 10

    return 0;
}
