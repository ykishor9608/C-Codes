#include<stdio.h>
void fndisplay(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d",arr[i]);
    }
}
int fninsert(int arr[],int isize,int iNum,int index,int size)
{
    if(size>=isize)
    {
        return -1;
    }
    for(int i=size-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=iNum;
    return 1;
}
int main()
{
    int arr[100]={1,2,4,5,6},iNum,index,isize=100,size=5;
    printf("enter the data to insert in array");
    scanf("%d",&iNum);
    printf("enter the index where we want to insert data");
    scanf("%d",&index);
    fninsert(arr,isize,iNum,index,size);
    size=size+1;
    if(fninsert==-1)
    {
        printf("insertion failed");
    }
    else
    {
        printf("insertion successful\n");
    }
    fndisplay(arr,size);
    return 0;
}