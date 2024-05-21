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
void insertion(struct node *r,int key)
{
    struct node *prev=NULL;
    while(r!=NULL)
    {
        prev=r;
        if(r->data==key)
        {
            printf("%d is present in tree",key);
        }
        else if(r->data>key)
        {
            r=r->left;
        }
        else
        {
            r=r->right;
        }
    }
    struct node *new=create(key);
    if(prev->data>key)
    {
        prev->left=new;
    }
    else
    {
        prev->right=new;
    }
}
int main()
{
    struct node *r=create(8);

    insertion(r,9);
    insertion(r,5);
    insertion(r,6);
    insertion(r,7);
    in(r);
    return 0;
}