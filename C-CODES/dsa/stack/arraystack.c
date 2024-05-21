#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
void push(struct stack* s,int val)
{
    if(s->top==s->size-1)
    {
        printf("\nstack overflow");
    }
    else
    {
        s->top++;
        s->arr[s->top]=val;
        printf("\nelement pushed successfully");
    }
}
void pop(struct stack* s)
{
    if(s->top==-1)
    {
        printf("\nstack underflow");
    }
    else
    {
        int val=s->arr[s->top];
        s->top--;
        printf("\npoped element is %d",val);
    }
}
void display(struct stack* s)
{
    int i;
    if(s->top==-1)
    {
        printf("\nstack underflow");
    }
    else
    {
        for(i=s->top;i>=0;i--)
        {
            printf("%d",s->arr[i]);
        }
    }
}
int main()
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=5;
    s->top=-1;
    s->arr=(int*)malloc(sizeof(int));
    int choice,val;
    while(1)
    {
        printf("\nenter\n1 for push\n2 for pop\n3 for display\n4 for exit");
        printf("\nenter the choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nenter the element to push");
                scanf("%d",&val);
                push(s,val);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                printf("\nElements in stack are/is ");
                display(s);
                break;
            case 4:
                exit(0);
            default:
                printf("\nwrong input");
        }
    }
    return 0;
}