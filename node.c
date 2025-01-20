#include<stdio.h>
#include<stdlib.h>

// Node structure
struct node 
{
    int data;
    struct node *link;
};

struct node *header = NULL;

struct node *CreateNode(int data) 
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}


void insertAtFront(int data) 
{
    struct node *newNode = CreateNode(data);
    newNode->link = header;
    header = newNode;
}


int main() 
{
    struct node *node;
    node = CreateNode(10);

    // Print the data of the node
    printf("Node data: %d\n", node->data);

    return 0;
}

