#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int *arr;
    int rear;
    int front;
    int size;
};
void fninsert(struct queue*q,int val)
{
    if(q->rear==q->size-1)
    {
        printf("queue overflow");
    }
    else
    {
        q->rear++;
        q->arr[q->rear]=val;
        printf("insertion successfully");
    }
}
void fndelete(struct queue*q)
{
    int val;
    if(q->rear==q->front)
    {
        printf("queue underflow");
    }
    else
    {
        val=q->arr[q->front+1];
        q->front++;
        printf("deleted element is %d",val);
    }
}
void fndisplay(struct queue*q)
{
    if(q->rear==q->front)
    {
        printf("queue underflow");
    }
    else
    {
        for(int i=q->front+1;i<=q->rear;i++)
        {
            printf("%d",q->arr[i]);
        }
    }
}
int main()
{
    struct queue*q=(struct queue*)malloc(sizeof(struct queue));
    q->size=5;
    q->rear=-1;
    q->front=-1;
    q->arr=(int*)malloc(sizeof(int));
    int choice,val;
    while(1)
    {
        printf("\nenter\n1 for insert\n2 for delete\n3 for display\n4 for exit");
        printf("\nenter the choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nenter the element to push");
                scanf("%d",&val);
                fninsert(q,val);
                break;
            case 2:
                fndelete(q);
                break;
            case 3:
                fndisplay(q);
                break;
            case 4:
                exit(0);
            default:
                printf("\nwrong input");
        }
    }
    return 0;
}