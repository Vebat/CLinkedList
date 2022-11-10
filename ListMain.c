#include <stdio.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

void push(Node **head, int data)
{
    Node *head=NULL;
    Node *tmp=(Node *)malloc(sizeof(Node));

    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;

    return;
}

int pop(Node **head){
    Node* prev = NULL;
    int val;

    if(head == NULL)
    {
        exit(-1);
    }
    prev=(*head);
    val= prev->value;
    (*head) = (*head)->next;
    return val;
}

Node* getLast(Node *head)
{
    if (head = NULL)
    {
        return NULL;
    }

    while(head->next)
    {
        head=head->next;
    }
    return head;
}

Node* getNth(Node* head, int n)
{
    int counter = 0;
    while (counter < n && head)
    {
        head=head->next;
        counter++;
    }
    return head;
}

void pushBack(Node* head, int value)
{
    Node *last=getLast(head);
    Node *tmp=(Node *)malloc(sizeof(Node));
    tmp->value=value;
    tmp->next=NULL;
    last->next=tmp;

}

Node* getLastButOne(Node* head)
{
    if(head == NULL)
    {
        exit(-2);
    }
    if(head->next)
    {
        return NULL;
    }
    while(head->next->next)
    {
        head = head->next;
    }
    return head;
}

void popBack(Node** head)
{
    Node *lastbn;
    if(!head)
    {
        exit(-1);
    }
    if(!(*head))
    {
        exit(-1);
    }
    lastbn=getLastButOne(head);
    if(lastbn == NULL)
    {
        free(*head);
        *head=NULL;
    } else
    {
        free(lastbn->next);
        lastbn->next=NULL;
    }
}

void insert (Node* head, unsigned n, int value)
{
    unsigned i = 0;
    Node *tmp= NULL;
    while(i < n && head->next)
    {
        head=head->next;
        i++;
    }
    tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    if(head->next)
    {
        tmp->next=head->next;
    } else
    {
        tmp->next=NULL;
    }
    head->next=tmp;
}

int deleteNth(Node** head, int n)
{
    if(n == 0)
    {
        return pop(head);
    } else
    {
        Node *prev=getNth(head,n-1);
        Node *elm=prev->next;
        prev->next=elm->next;
        int data=elm->value;
        free(elm);
        return data;
    }
}

void deleteList(Node** head)
{
    while((*head)->next)
    {
        pop(head);
        *head=(*head)->next;
    }
    free(*head);
}

void fromArray(Node** head, int *arr,size_t size)
{
    size_t i=size-1;
    if(arr == NULL || size==0)
    {
        return;
    }
    do
    {
        push(head,arr[i]);
    } while(i--!=0);
}

int* toArray(const Node *head)
{
    int leng=lenght(head);
    int *values=(int*)malloc(leng*sizeof(int*));
    while(head)
    {
        values[--leng]=head->value;
        head=head->next;
    }
    return values;
}

void printLinkedList(Node *head)
{
    while(head)
    {
        printf("%d",head->value);
        head=head->next;
    }
    printf('\n');
}
