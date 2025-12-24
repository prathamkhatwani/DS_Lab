#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if(top == MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d is pushed to the stack\n", value);
    }
}

void pop() {
    if(top == -1) {
        printf("Stack underflow!\n");
    } else {
        int temp = stack[top];
        printf("%d is popped\n", temp);
        top--;
    }
}

void peek() {
    if(top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("The top element is: %d\n", stack[top]);
    }
}

void display() {
    if(top == -1) {
        printf("The stack is empty!\n");
    } else {
        printf("The elements of the stack are:\n");
        for(int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;
    while(1) {
        printf("\n--STACK MENU--\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to push: ");
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
                display();
                break;
            case 5:
                printf("Exiting the program!\n");
                return 0;
            default:
                printf("Invalid input! Please try again.\n");
                break;
        }
    }
}
