
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

void insertAtFront(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        (*head_ref) = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
}

void insertAtAny(struct Node** head_ref, int new_data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        insertAtFront(head_ref, new_data);
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    struct Node* temp = *head_ref;
    int i;
    for (i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = new_node;

    temp->next = new_node;
}

void deleteAtFront(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head_ref;
    (*head_ref) = (*head_ref)->next;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = NULL;

    free(temp);
}

void deleteAtEnd(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    if (last->prev != NULL)
        last->prev->next = NULL;
    else
        *head_ref = NULL;

    free(last);
}

void deleteAtAny(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        deleteAtFront(head_ref);
        return;
    }

    struct Node* temp = *head_ref;
    int i;
    for (i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node* next = temp->next->next;
    free(temp->next);

    temp->next = next;

    if (next != NULL)
        next->prev = temp;
}

int search(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any\n");
        printf("4. Delete at Front\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Any\n");
        printf("7. Search\n");
        printf("8. Print List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtAny(&head, data, position);
                break;
            case 4:
                deleteAtFront(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtAny(&head, position);
                break;
            case 7:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(head, data))
                    printf("Data found\n");
                else
                    printf("Data not found\n");
                break;
            case 8:
                printList(head);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 9);

    return 0;
}
