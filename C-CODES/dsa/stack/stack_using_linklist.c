#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *push(struct node *top,int data)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    if(n==NULL)
    {
        printf("\noverflow");
    }
    else
    {
        n->data=data;
        n->next=top;
        top=n;
        return top;
    }
}
int pop(struct node *top)
{
    // struct node *n=top;
    if(top==NULL)
    {
        printf("\nunderflow");
    }
    else
    {
        struct node *n=top;
        int x=top->data;
        top=top->next;
        free(n);
        return x;
    }
}
struct node *traverse(struct node *top)
{
    while(top!=NULL)
    {
        printf("\n%d",top->data);
        top=top->next;
    }
}
int main()
{
    struct node *top=NULL;
    top=push(top,4);
    top=push(top,4);
    top=push(top,4);
    top=push(top,4);
    top=push(top,4);
    top=push(top,4);
    traverse(top);
    // int a=pop(top);
    // printf("element poped is %d",a);
    // traverse(top);
    return 0;
}  

