#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sort(struct Node* head) {
    struct Node *i, *j;
    int tempVal;
    if (head == NULL) return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                tempVal = i->data;
                i->data = j->data;
                j->data = tempVal;
            }
        }
    }
    printf("List sorted successfully.\n");
}

void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("List reversed successfully.\n");
}

void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
    } else {
        struct Node* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    }
    printf("Lists concatenated successfully.\n");
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    struct Node *newNode, *temp;
    int choice, n, i;

    while(1) {
        printf("\n--- MENU ---\n");
        printf("1. Create/Overwrite List 1\n");
        printf("2. Display List 1\n");
        printf("3. Sort List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Create List 2 and Concatenate\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                list1 = NULL;
                printf("Enter number of nodes for List1: ");
                scanf("%d", &n);

                for(i = 0; i < n; i++) {
                    newNode = (struct Node*)malloc(sizeof(struct Node));
                    printf("Enter data for node %d: ", i+1);
                    scanf("%d", &newNode->data);
                    newNode->next = NULL;

                    if (list1 == NULL) {
                        list1 = newNode;
                        temp = list1;
                    } else {
                        temp->next = newNode;
                        temp = temp->next;
                    }
                }
                break;

            case 2:
                display(list1);
                break;

            case 3:
                sort(list1);
                break;

            case 4:
                reverse(&list1);
                break;

            case 5:
                list2 = NULL;
                printf("Enter number of nodes for List 2: ");
                scanf("%d", &n);

                for(i = 0; i < n; i++) {
                    newNode = (struct Node*)malloc(sizeof(struct Node));
                    printf("Enter data for List 2 node %d: ", i+1);
                    scanf("%d", &newNode->data);
                    newNode->next = NULL;

                    if (list2 == NULL) {
                        list2 = newNode;
                        temp = list2;
                    } else {
                        temp->next = newNode;
                        temp = temp->next;
                    }
                }
                concatenate(&list1, list2);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
