#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
void sll(struct node*ptr)
{
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct node*a;
    struct node*b;
    struct node*c;
    a=(struct node*)malloc(sizeof(struct node));
    b=(struct node*)malloc(sizeof(struct node));
    c=(struct node*)malloc(sizeof(struct node));


    a->data=3;
    a->next=b;

    b->data=4;
    b->next=c;

    c->data=7;
    c->next=NULL;
    sll(a);
}