#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
	struct node *prev;

};
void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
void revtraverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->prev;
    }
}
struct node *insertatbeg(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
	ptr->prev=NULL;
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
	ptr->prev=head;
    return head;
}
struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
	ptr->prev=p;
    ptr->next = NULL;
    return head;
}
struct node *insertatnode(struct node *head,struct node *prevnode,int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
	ptr->prev=prevnode;
    return head;
}
struct node *delatbeg(struct node *head)
{
    struct node *p=head;
    head=head->next;
	head->prev=NULL;
    free(p);
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
    q->next->prev=p;
    free(q);
    return head;
}
struct node *delatend(struct node *head)
{
    struct node *p=head;
    struct node *q=head->next;
    struct node *r=q->next;
    while (r->next!=NULL)
    {
        q=q->next;
        p=p->next;
        r=r->next;
    }
    q->next=NULL;
    q->prev=p;
    free(r);
    return head;
}
struct node *delatgivenvalue(struct node *head,int data)
{
    struct node *p=head;
    struct node *q=head->next;
    struct node *r=q->next;
    while(q->data!=data && q->next!=NULL)
    {
        q=q->next;
        p=p->next;
        r=r->next;
    }
    if(q->data==data)
    {
        p->next=q->next;
        r->prev=p;
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
	a->prev=NULL;

    b->data = 9;
    b->next = c;
	b->prev=a;

    c->data = 3;
    c->next = NULL;
	c->prev=b;
    printf("Traverse operation\n");
    traverse(a);
    printf("Reverse traverse operation\n");
    revtraverse(c);

    printf("Traverse before any operation\n");
    traverse(a);
    a=insertatbeg(a,4);
    a=insertatindex(a,7,2);
    a=insertatend(a,1);
    a=insertatnode(a,a,6);
    printf("\nTraverse after insert operation\n");
    traverse(a);

    a=delatindex(a,2);
    a=delatend(a);
    a=delatgivenvalue(a,5);
    a=delatbeg(a);
    printf("\nTraverse after delete operation\n");
    traverse(a);
    return 0;
}