#include <stdio.h>
#define MAX 5

int queue[MAX];
int rear = -1, front = -1;

void enqueue(int n) {
    if (((rear + 1) % MAX) == front) {
        printf("Queue Overflow\n");
    }
    else if (front == -1) {
        front = rear = 0;
        queue[rear] = n;
        printf("%d Added to queue\n", n);
    }
    else {
        rear = (rear + 1) % MAX;
        queue[rear] = n;
        printf("%d Added to queue\n", n);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
    } 
    else if (front == rear) {
        printf("Deleted %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("%d Deleted from queue\n", queue[front]);
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    }
    else {
        int i = front;
        while (i != rear) {
            printf("%d\n", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}

int main () {
    printf("---- INIT CIRCULAR QUEUE ----\n");
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
                loop = 0;
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    printf("---- END -----\n");
}
