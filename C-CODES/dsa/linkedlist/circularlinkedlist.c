#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *head)
{
    struct node *ptr=head;
    do
    {
        printf("%d\n", ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
struct node *insertatbeg(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next = head;
    head=ptr;
    return ptr;
}
struct node *insertatindex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}
struct node *insertatnode(struct node *head,struct node *prevnode,int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;
}
struct node *delatbeg(struct node *head)
{
    struct node *p=head->next;
    struct node *ptr=head->next;
    while(p->next!=head)
    {
        p=p->next;
        ptr=ptr->next;
    }
    p=p->next;
    ptr->next=p->next;
    free(p);
    head=ptr->next;
    return head;
}
struct node *delatindex(struct node *head,int index)
{
    struct node *p=head;
    struct node *q=head->next;
    for(int i=0;i<index-1;i++)
    {
        q=q->next;
        p=p->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct node *delatend(struct node *head)
{
    struct node *p=head;
    struct node *q=head->next;
    while (q->next!=head)
    {
        q=q->next;
        p=p->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct node *delatgivenvalue(struct node *head,int data)
{
    struct node *p=head;
    struct node *q=head->next;
    while(q->data!=data && q->next!=NULL)
    {
        q=q->next;
        p=p->next;
    }
    if(q->data==data)
    {
        p->next=q->next;
        free(q);
    }
    return head;
}
int main()
{
    struct node *a = (struct node *)malloc(sizeof(struct node));
    struct node *b = (struct node *)malloc(sizeof(struct node));
    struct node *c = (struct node *)malloc(sizeof(struct node));

    a->data = 5;
    a->next = b;

    b->data = 9;
    b->next = c;

    c->data = 3;
    c->next = a;
    printf("Traverse before any operation\n");
    traverse(a);

    a=insertatbeg(a,4);
    a=insertatindex(a,7,2);
    a=insertatend(a,1);
    a=insertatnode(a,a,6);
    printf("\nTraverse after insert operation\n");
    traverse(a);

    a=delatbeg(a);
    a=delatindex(a,2);
    a=delatend(a);
    a=delatgivenvalue(a,5);
    printf("\nTraverse after delete operation\n");
    traverse(a);
    return 0;
}