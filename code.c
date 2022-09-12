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
    for (int i = 0; i <= 5; i++)
    {
        insert(&head, i);
    }
    printList(head);
    reverse(&head);
    puts("");
    printList(reversed);
    return 0;
}
