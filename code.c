#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;          // data part
    struct node *next; // next node
} node;

node *createNode(int val)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void insert(node **head, int data)
{
    node *newnode = createNode(data);
    if ((*head) == NULL)
        (*head) = newnode;
    else
    {
        node *tmp = (*head);
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = newnode;
    }
}
void printList(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}
node *reversed = NULL;
void reverse(node **head)
{
    if ((*head) == NULL)
    {
        return;
    }
    reverse(&((*head)->next));
    insert(&reversed, (*head)->data);
}
int main()
{
    node *head = NULL;
    insert(&head, 0);
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    printList(head);
    reverse(&head);
    puts("");
    printList(reversed);
    return 0;
}
