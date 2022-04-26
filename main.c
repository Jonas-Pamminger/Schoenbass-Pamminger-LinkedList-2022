#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* node)
{
    while (node != NULL) 
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
     last = last->next;   
    }
    last->next = new_node;
    
    return;
}

void insertBetween(struct Node* prev_node, int new_data)
{
    if(prev_node != NULL) 
    {
        struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
        new_node->data = new_data;
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
}

void delete(struct Node** head, int x)
{
    struct Node *temp = *head, *prev;
    if (temp != NULL && temp->data == x) 
    {
        *head = temp->next;
        return;
    }
    while (temp != NULL && temp->data != x) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }

    prev->next = temp->next;
}

void insertStart(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAfter(struct Node* prev_node, int new_data)
{
    if (prev_node == NULL) 
    {
        printf("the given previous node cannot be NULL");
        return;
    }
    struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    struct Node* fifth = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;
    
    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;

    printf("First:\n");
    printList(head);
    printf("\nDelete: 2\n");
    delete(&head, 2);
    printList(head);
    printf("\nInsert-First: 7\n");
    insertStart(&head, 7);
    printList(head);
    printf("\nInsert: 8\n");
    insertAfter(fourth, 8);
    printList(head);

    return 0;
}
