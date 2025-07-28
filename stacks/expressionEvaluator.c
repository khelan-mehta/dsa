#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX]; // Stack for operators, like how my heart stacks love for you, babe! 😘
int top = -1;   // Top of the stack, but you're always at the top of my heart! 💖

// Push character to stack
void push(char value) {
    stack[++top] = value; // Adds value to stack, like adding smiles to your day! 😊
}

// Pop character from stack
char pop() {
    return stack[top--]; // Returns top value, like how you return joy to my life! 🌟
}

// Get operator precedence
int precedence(char op) {
    // Returns precedence: 1 for +,-; 2 for *,/, just like you're my #1 priority! 💕
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Reverse string, swapping parentheses
void reverse(char* exp, char* rev) {
    // Reverses string, swaps '(', ')', like how you turn my world upside down! 😍
    int len = strlen(exp), j = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (exp[i] == '(') rev[j++] = ')';
        else if (exp[i] == ')') rev[j++] = '(';
        else rev[j++] = exp[i];
    }
    rev[j] = '\0';
}

// Convert infix to postfix
// Example: A+B*C → ABC*+
// Steps: A (output: A), + (push +), B (output: AB), * (push *), C (output: ABC), 
// pop * (output: ABC*), pop + (output: ABC*+)
void infixToPostfix(char* infix, char* postfix) {
    // Converts infix to postfix, like how you convert my frowns to smiles! 😘
    int j = 0;
    for (int i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i]; // Append operands directly
        } else if (infix[i] == '(') {
            push(infix[i]); // Push '('
        } else if (infix[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = pop(); // Pop until '('
            }
            pop(); // Discard '('
        } else {
            while (top >= 0 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop(); // Pop higher/equal precedence
            }
            push(infix[i]); // Push current operator
        }
    }
    while (top >= 0) {
        postfix[j++] = pop(); // Pop remaining operators
    }
    postfix[j] = '\0';
}

// Convert infix to prefix
// Example: (A+B)*C → *+ABC
// Steps: Reverse: C*(B+A), to postfix: CBA+*, reverse: *+ABC
void infixToPrefix(char* infix, char* prefix) {
    // Creates prefix, like how you create happiness in my life! 🌸
    char revInfix[MAX], postfix[MAX];
    reverse(infix, revInfix);
    infixToPostfix(revInfix, postfix);
    reverse(postfix, prefix);
}

// Evaluate postfix expression
// Example: 231*+ → 5
// Steps: 2 (push), 3 (push), 1 (push), * (pop 3,1, push 3*1=3), + (pop 2,3, push 2+3=5)
int evaluatePostfix(char* exp) {
    // Evaluates postfix, like how you evaluate my heart to be yours! 💞
    int numStack[MAX], numTop = -1;
    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            numStack[++numTop] = exp[i] - '0'; // Convert char to int
        } else {
            int val2 = numStack[numTop--];
            int val1 = numStack[numTop--];
            switch (exp[i]) {
                case '+': numStack[++numTop] = val1 + val2; break;
                case '-': numStack[++numTop] = val1 - val2; break;
                case '*': numStack[++numTop] = val1 * val2; break;
                case '/': numStack[++numTop] = val1 / val2; break;
            }
        }
    }
    return numStack[numTop];
}

// Evaluate prefix expression
// Example: *+23 1 → 5
// Steps: Scan right to left: 1 (push), 3 (push), 2 (push), + (pop 2,3, push 2+3=5),
// * (pop 5,1, push 5*1=5)
int evaluatePrefix(char* exp) {
    // Evaluates prefix, like how you make every moment count! 😍
    int numStack[MAX], numTop = -1;
    int len = strlen(exp);
    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            numStack[++numTop] = exp[i] - '0'; // Convert char to int
        } else {
            int val1 = numStack[numTop--];
            int val2 = numStack[numTop--];
            switch (exp[i]) {
                case '+': numStack[++numTop] = val1 + val2; break;
                case '-': numStack[++numTop] = val1 - val2; break;
                case '*': numStack[++numTop] = val1 * val2; break;
                case '/': numStack[++numTop] = val1 / val2; break;
            }
        }
    }
    return numStack[numTop];
}

int main() {
    // Hey babe, this code's for you, just like my heart! 💖
    char infix[] = "(2+3)*1";
    char postfix[MAX], prefix[MAX];

    // Infix to Postfix: (2+3)*1 → 23+1*
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    // Infix to Prefix: (2+3)*1 → *+231
    infixToPrefix(infix, prefix);
    printf("Prefix: %s\n", prefix);

    // Evaluate Postfix: 23+1* → 5
    printf("Postfix Evaluation: %d\n", evaluatePostfix(postfix));

    // Evaluate Prefix: *+231 → 5
    printf("Prefix Evaluation: %d\n", evaluatePrefix(prefix));

    // You're my favorite algorithm, always solving my heart's equations! 😘
    return 0;
}