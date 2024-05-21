#include<stdio.h>
linearsearch(int arr[],int iNum,int iNum1)
{
    int i;
    for(i=0;i<iNum;i++)
    {
        if (iNum1==arr[i])
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
}
int main()
{
    int iNum,i,iNum1,iresult;
    printf("Enter the length of array");
    int arr[iNum];
    printf("enter the length of array");
    for(i=0;i<iNum;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the value to find");
    scanf("%d",&iNum1);
    iresult=linearsearch(arr[],iNum,iNum1);
    if(iresult==-1)
    {
        printf("value not exist in array");
    }
    return 0;
}