#include <stdio.h>
#define MAX 5

int queue[MAX];
int rear = -1, front = -1;

void enqueue(int n) {
    if (rear == MAX - 1) {
        printf("Queue Overlfow\n");
    }
    else if (rear == -1) {
        front = rear = 0;
        queue[rear] = n;
        printf("%d Added to queue\n", n);
    }
    else {
        rear += 1;
        queue[rear] = n;
        printf("%d Added to queue\n", n);
    }
}

void dequeue() {
    if ((front == -1) || (front > rear + 1)) {
        printf("Queue Underflow\n");
    } 
    else {
        printf("%d Deleted from queue\n", queue[front]);
        front += 1;
    }
} 

void display() {
    if ((front == -1) || (front > rear + 1)) {
        printf("Queue if empty\n");
    }
    else {
        for (int i = 0; i < MAX; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main () {
    printf("---- INIT LINEAR QUEUE ----\n");
    int loop = 1;
    int input;
    int n;
    while (loop) {
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice : ");
        scanf("%d", &input);
        switch (input) {
            case 1: 
                printf("Enter the element to enter : ");
                scanf("%d", &n);
                enqueue(n);
                break;
            case 2: 
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
        }
    }
    printf("---- END -----");
}
