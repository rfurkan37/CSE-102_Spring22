#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

// Stack structure for character storage
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push character onto stack
void push(Stack* stack, char c) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = c;
    }
}

// Pop character from stack
char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0';
}

// Check if characters form a matching pair
bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

// Main function to check if parentheses are valid
bool isValid(char* s) {
    Stack stack;
    initStack(&stack);
    
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        char current = s[i];
        
        // If opening bracket, push to stack
        if (current == '(' || current == '[' || current == '{') {
            push(&stack, current);
        }
        // If closing bracket
        else if (current == ')' || current == ']' || current == '}') {
            // If stack is empty, no matching opening bracket
            if (isEmpty(&stack)) {
                return false;
            }
            
            // Pop from stack and check if it matches
            char opening = pop(&stack);
            if (!isMatchingPair(opening, current)) {
                return false;
            }
        }
    }
    
    // Valid if stack is empty (all brackets matched)
    return isEmpty(&stack);
}

int main() {
    // Test cases
    char test1[] = "()";
    char test2[] = "()[]{}";
    char test3[] = "(]";
    char test4[] = "([)]";
    char test5[] = "{[]}";
    char test6[] = "";
    char test7[] = "((()))";
    char test8[] = "([{}])";
    
    printf("Valid Parentheses Checker\n");
    printf("========================\n\n");
    
    printf("Test 1: \"%s\" -> %s\n", test1, isValid(test1) ? "Valid" : "Invalid");
    printf("Test 2: \"%s\" -> %s\n", test2, isValid(test2) ? "Valid" : "Invalid");
    printf("Test 3: \"%s\" -> %s\n", test3, isValid(test3) ? "Valid" : "Invalid");
    printf("Test 4: \"%s\" -> %s\n", test4, isValid(test4) ? "Valid" : "Invalid");
    printf("Test 5: \"%s\" -> %s\n", test5, isValid(test5) ? "Valid" : "Invalid");
    printf("Test 6: \"%s\" -> %s\n", test6, isValid(test6) ? "Valid" : "Invalid");
    printf("Test 7: \"%s\" -> %s\n", test7, isValid(test7) ? "Valid" : "Invalid");
    printf("Test 8: \"%s\" -> %s\n", test8, isValid(test8) ? "Valid" : "Invalid");
    
    return 0;
}