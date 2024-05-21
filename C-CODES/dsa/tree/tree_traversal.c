#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
struct node *create(int data)
{
    struct node *h =(struct node*)malloc(sizeof(struct node));
    h->data=data;
    h->left=NULL;
    h->right=NULL;
    return h; 
}
void pre(struct node *r)
{
    if(r!=NULL)
    {
        printf("%d ",r->data);
        pre(r->left);
        pre(r->right);
    }    
}
void post(struct node *r)
{
    if(r!=NULL)
    {
        post(r->left);
        post(r->right);
        printf("%d ",r->data);
    }    
}
void in(struct node *r)
{
    if(r!=NULL)
    {
        in(r->left);
        printf("%d ",r->data);
        in(r->right);
    }    
}
int main()
{
    struct node *r=create(1);
    struct node *c1=create(2);
    struct node *c2=create(3);
    struct node *c3=create(4);
    struct node *c4=create(5);
    struct node *c5=create(6);
    r->left=c1;
    r->right=c2;
    c1->left=c3;
    c1->right=c4;
    c2->left=c5;
    in(r);
    return 0;
}