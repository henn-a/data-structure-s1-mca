#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* header = NULL;

struct node* createnode(int data) {
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;
    return newnode;
}

void insertAtFront(int data) {
    struct node* newnode = createnode(data);
    if (header == NULL) {
        header = newnode;
    } else {
        newnode->link = header;
        header = newnode;
    }
}

void insertAtLast(int data) {
    struct node* newnode = createnode(data);
    if (header == NULL) {
        header = newnode;
    } else {
        struct node* temp = header;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newnode;
    }
}

void insertAtAny(int data, int position) {
    struct node* newnode = createnode(data);
    if (position == 0) {
        newnode->link = header;
        header = newnode;
        return;
    }
    struct node* temp = header;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->link;
    }
    if (temp != NULL) {
        newnode->link = temp->link;
        temp->link = newnode;
    } else {
        printf("Position out of bounds\n");
    }
}

void traversal() {
    struct node* ptr = header;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

int main() {
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at Any Position\n");
        printf("4. Traverse the List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(data);
                break;
            case 2:
                printf("Enter data to insert at last: ");
                scanf("%d", &data);
                insertAtLast(data);
                break;
            case 3:
                printf("Enter data to insert and position: ");
                scanf("%d %d", &data, &position);
                insertAtAny(data, position);
                break;
            case 4:
                traversal();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
