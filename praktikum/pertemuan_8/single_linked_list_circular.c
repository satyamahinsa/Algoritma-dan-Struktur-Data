#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *createNode()
{
    Node *newNode = malloc(sizeof(Node));
    printf("add value : ");
    scanf("%d", &(newNode->value));
    return newNode;
}

Node *addNode(Node *node)
{
    Node *newNode = createNode();
    if (node == NULL)
    {
        newNode->next = newNode;
        node = newNode;
    }
    else
    {
        Node *tail = node;
        while (tail->next != node)
        {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = node;
    }
    return node;
}

Node *DeleteLast(Node *node)
{
    Node *tail = node;
    while (tail->next->next != node)
    {
        tail = tail->next;
    }
    Node *tmp = tail->next;
    tail->next = node;
    free(tmp);
    return node;
}

void TraversalNode(Node *node)
{
    if (node == NULL)
    {
        printf("[ ]\n");
    }
    else
    {
        Node *tail = node;
        while (tail->next != node)
        {
            printf("[%d] ", tail->value);
            tail = tail->next;
        }
        printf("[%d]\n", tail->value);
    }
}

Node *InsertFirst(Node *node)
{
    Node *newNode = createNode();
    Node *tail = node;
    while (tail->next != node)
    {
        printf("[%d] ", tail->value);
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->next = node;
    return newNode;
}

Node *DeleteFirst(Node *node)
{
    Node *tail = node;
    while (tail->next != node)
    {
        printf("[%d] ", tail->value);
        tail = tail->next;
    }
    tail->next = node->next;
    free(node);
    return tail->next;
}

int main()
{
    Node *head = NULL;
    int choice;
    do
    {
        TraversalNode(head);
        printf("Menu : \n");
        printf("1. Insert Node\n");
        printf("2. Insert First\n");
        printf("3. Delete First\n");
        printf("4. Delete Last\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            system("cls");
            head = addNode(head);
        }
        else if (choice == 2)
        {
            system("cls");
            head = InsertFirst(head);
        }
        else if (choice == 3)
        {
            system("cls");
            head = DeleteFirst(head);
        }
        else if (choice == 4)
        {
            system("cls");
            head = DeleteLast(head);
        }
        system("cls");
    } while (choice != 0);
}