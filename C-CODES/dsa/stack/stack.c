#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int size;
    int *arr;
};
void push(struct stack* s)
{
    int a;
    if(s->top==s->size-1)
    {
        printf("\nstack overflow");
    }
    else
    {   
        printf("enter the data");
        scanf("%d",&a);
        s->top++;
        s->arr[s->top]=a;
        printf("element pushed successfully\n");
    }
}
void pop(struct stack* s)
{
    if(s->top==-1)
    {
        printf("stack underflow");
    }
    else
    {
        s->top--;
        printf("element poped successfully");
    }
}
void traverse(struct stack* s)
{
    for(int i=0;i<=s->top;i++)
    {
        printf("%d",s->arr[i]);
    }
}
int main()
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=3;
    s->arr=(int*)malloc(sizeof(int));
    push(s);
    push(s);
    pop(s);
    traverse(s);
}