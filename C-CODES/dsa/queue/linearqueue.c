#include <stdio.h>
#define MAX 5
struct queue
{
    int aiData[MAX];
    int iFront;
    int iRear;
};
void fnInsert(struct queue *q, int iData)
{
    if (q->iRear == MAX - 1)
    {
        printf("Queue is overflow");
        return;
    }
    else
    {
        q->aiData[++q->iRear] = iData;
    }
}
void fnDelete(struct queue *q)
{
    int iDelData;
    if (q->iFront == q->iRear)
    {
        printf("Queue is underflow");
        return;
    }
    else
    {
        iDelData = q->aiData[++q->iFront];
        printf("\nThe deleted data is %d", iDelData);
    }
}
void fnDisplay(struct queue *q)
{
    if (q->iFront == q->iRear)
    {
        printf("\nQueue is underflow");
        return;
    }
    else
    {
        int iIndex;
        printf("\nThe queue elements are: ");
        for (iIndex = q->iFront + 1; iIndex <= q->iRear; iIndex++)
        {
            printf("%d ", q->aiData[iIndex]);
        }
    }
}
int main()
{
    struct queue q;
    q.iFront = -1;
    q.iRear = -1;
    int iData, c = 1, iChoice;
    while (c)
    {
        printf("\nPress 1 for Insertion");
        printf("\nPress 2 for Deletion");
        printf("\nPress 3 for display");
        printf("\nPress 4 for exit");
        printf("\nEnter the operation: ");
        scanf("%d", &iChoice);
        switch (iChoice)
        {
        case 1:
            printf("\nEnter the data: ");
            scanf("%d", &iData);
            fnInsert(&q, iData);
            fnDisplay(&q);
            break;
        case 2:
            fnDelete(&q);
            fnDisplay(&q);
            break;
        case 3:
            fnDisplay(&q);
            break;
        case 4:
            c = 0;
            break;
        default:
            printf("\nWrong Input");
        }
    }
    return 0;
}