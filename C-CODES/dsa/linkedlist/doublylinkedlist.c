#include <stdio.h>
#include <stdlib.h>
struct DLL
{
    struct DLL *Left;
    int iData;
    struct DLL *Right;
};
struct DLL *Start = NULL, *Last = NULL, *New, *Prev, *Ptr, *Temp;
void fnCreate()
{
    New = (struct DLL *)malloc(sizeof(struct DLL));
    New->Left = NULL;
    printf("\nEnter the data: ");
    scanf("%d", &New->iData);
    New->Right = NULL;
}
void fnAddNode()
{
    // insert node at the beginning
    if (New->iData < Start->iData)
    {
        New->Right = Start;
        Start->Left = New;
        Start = New;
        return;
    }
    // insert node  in between two nodes
    for (Prev = Start, Ptr = Start->Right; Ptr; Prev = Ptr, Ptr = Ptr->Right)
    {
        if (New->iData < Ptr->iData)
        {
            Prev->Right = New;
            New->Left = Prev;
            New->Right = Ptr;
            Ptr->Left = New;
            return;
        }
    }
    // insert node  at the end
    if (Ptr == NULL)
    {
        Prev->Right = New;
        New->Left = Prev;
        Last = New;
    }
}

void fnInsert()
{
    fnCreate();
    if (Start == NULL)
    {
        Start = New;
        Last = New;
    }
    else
    {
        fnAddNode();
    }
}
void fnDelete()
{
    int iDel;
    printf("\nEnter the data to be deleted: ");
    scanf("%d", &iDel);
    // Delete First Node
    if (Start->iData == iDel)
    {
        Temp = Start;
        Start = Start->Right;
        if (Start == NULL)
        {
            Last = NULL;
        }
        else
        {
            Start->Left = NULL;
            free(Temp);
        }
    }
    for (Prev = Start, Ptr = Start->Right; Ptr; Prev = Ptr, Ptr = Ptr->Right)
    {
        if (Ptr->iData == iDel)
        {
            Prev->Right = Ptr->Right;
            if (Prev->Right == NULL)
                Last = Prev;
            else
                Ptr->Right->Left = Prev;
            free(Ptr);
            break;
        }
    }
    // Data Not Found
    if (Ptr == NULL)
    {
        printf("\nData Not Found…");
    }
}
void fnDisplay()
{
    if (Start == NULL)
    {
        printf("Link List is Empty");
        return;
    }
    printf("\nList elements are: ");
    for (Ptr = Start; Ptr; Ptr = Ptr->Right)
    {
        printf("%d ", Ptr->iData);
    }
}
int main()
{
    int c = 1, iChoice;
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
            fnInsert();
            fnDisplay();
            break;
        case 2:
            fnDelete();
            fnDisplay();
            break;
        case 3:
            fnDisplay();
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