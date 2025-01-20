

 1) Write a C program to implement Single Linked List with the following set of operations:

       1. Insert At Front
       2. Insert At End
       3. Insert At Any
       4. Delete At Front
       5. Delete At End
       6. Delete At Any
       7. Search
       8. Display/Traversal

PROGRAM CODE:

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtFront(int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtAny(int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertAtFront(data);
    } else {
        struct Node *prev = head;
        for (int i = 1; i < position - 1 && prev != NULL; i++) {
            prev = prev->next;
        }
        if (prev == NULL) {
            printf("Position out of bounds\n");
        } else {
            struct Node *newNode = createNode(data);
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }
}

void deleteAtFront() {
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        struct Node *temp = head, *prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            head = NULL;
        } else {
            prev->next = NULL;
        }
        free(temp);
    }
}

void deleteAtAny(int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        deleteAtFront();
    } else {
        struct Node *prev = head, *temp = NULL;
        for (int i = 1; i < position && prev != NULL; i++) {
            temp = prev;
            prev = prev->next;
        }
        if (prev == NULL) {
            printf("Position out of bounds\n");
        } else {
            temp->next = prev->next;
            free(prev);
        }
    }
}

void search(int value) {
    struct Node *temp = head;
    int position = 1;
    int found = 0;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d found at position %d\n", value, position);
            found = 1;
            break;
        }
        temp = temp->next;
        position++;
    }

    if (!found) {
        printf("Element %d not found in the list.\n", value);
    }
}

void traversal() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data, position;

    while (1) {
        printf("\n1. Insert at front\n2. Insert at end\n3. Insert at any position\n");
        printf("4. Delete at front\n5. Delete at end\n6. Delete at any position\n");
        printf("7. Search\n8. Traverse\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtFront(data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtAny(data, position);
                break;
            case 4:
                deleteAtFront();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtAny(position);
                break;
            case 7:
                printf("Enter data to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 8:
                traversal();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
