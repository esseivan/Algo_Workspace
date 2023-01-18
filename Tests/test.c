#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s
{
    int data;
    struct Node_s *link;
} Node_t;

typedef Node_t *HEAD_t;

Node_t *createLifo(void)
{
    return NULL;
}

void push(Node_t **pHead, Node_t newElement)
{
    Node_t *pNew = (Node_t *)malloc(sizeof(Node_t));

    if (NULL == pNew)
        exit(1);

    pNew->data = newElement.data;
    pNew->link = NULL;

    if (NULL == *pHead)
    {
        *pHead = pNew;
    }
    else
    {
        Node_t *pFlow = *pHead;
        while (NULL != pFlow->link)
        {
            pFlow = pFlow->link;
        }
        pFlow->link = pNew;
    }
}

void pop(Node_t *head, Node_t *pGet)
{
    Node_t *pTemp = head;
    while (NULL != pTemp->link)
    {
        pTemp = pTemp->link;
    }
    pGet->data = pTemp->data;
}

int main(void)
{
    Node_t *pHead = createLifo();

    // Test push
    Node_t newElement;
    newElement.data = 2;
    push(&pHead, newElement);
    newElement.data = 3;
    push(&pHead, newElement);

    char x = -129;
    char y = x;

    return 0;
}
