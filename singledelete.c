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

void deleteAtFront() {
    if (header == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = header;
    header = header->link;
    free(temp);
}

void deleteAtLast() {
    if (header == NULL) {
        printf("List is empty\n");
        return;
    }
    if (header->link == NULL) {
        free(header);
        header = NULL;
        return;
    }
    struct node* temp = header;
    while (temp->link->link != NULL) {
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
}

void deleteAtAny(int position) {
    if (header == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        deleteAtFront();
        return;
    }
    struct node* temp = header;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->link;
    }
    if (temp == NULL || temp->link == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    struct node* to_delete = temp->link;
    temp->link = to_delete->link;
    free(to_delete);
}

void traversal() {
    struct node* ptr = header;
    while (ptr != NULL) {
        printf("%d ", ptr->link->data);
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
        printf("4. Delete at Front\n");
        printf("5. Delete at Last\n");
        printf("6. Delete at Any Position\n");
        printf("7. Traverse the List\n");
        printf("8. Exit\n");
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
                deleteAtFront();
                break;
            case 5:
                deleteAtLast();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtAny(position);
                break;
            case 7:
                traversal();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}
