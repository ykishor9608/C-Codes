#include <stdio.h>
#include <stdlib.h>
struct SLL
{
    int iData;
    struct SLL *Next;
};
struct SLL *New, *Start = NULL, *Prev, *Ptr, *Temp;

void fnCreate()
{
    New = (struct SLL *)malloc(sizeof(struct SLL));
    printf("\nEnter the data: ");
    scanf("%d", &New->iData);
    New->Next = NULL;
}

void fnAddNode()
{
    // Insert node at the beginning
    if (New->iData < Start->iData)
    {
        New->Next = Start;
        Start = New;
        return;
    }
    // Insert node in between two nodes
    for (Prev = Start, Ptr = Start->Next; Ptr; Prev = Ptr, Ptr = Ptr->Next)
    {
        if (New->iData < Ptr->iData)
        {
            Prev->Next = New;
            New->Next = Ptr;
            return;
        }
    }
    // Insert node at the end
    if (Ptr == NULL)
    {
        Prev->Next = New;
    }
}

void fnInsert()
{
    fnCreate();
    if (Start == NULL)
    {
        Start = New;
    }
    else
    {
        fnAddNode();
    }
}

void fnDelete()
{
    int iDel;
    if (Start == NULL)
    {
        printf("\nLink List is empty");
        return;
    }
    printf("\nEnter the data to be deleted: ");
    scanf("%d", &iDel);
    // Delete First Node
    if (Start->iData == iDel)
    {
        Temp = Start;
        Start = Start->Next;
        free(Temp);
        return;
    }
    // Delete from Middle or Last
    for (Prev = Start, Ptr = Start->Next; Ptr; Prev = Ptr, Ptr = Ptr->Next)
    {
        if (Ptr->iData == iDel)
        {
            Prev->Next = Ptr->Next;
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
        printf("\nList is empty");
        return;
    }
    printf("\nThe elements are: ");
    for (Ptr = Start; Ptr != NULL; Ptr = Ptr->Next)
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