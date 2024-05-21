#include<stdio.h>
void fnselectionsort(int arr[],int size)
{
    int i,j,temp,key;
    for(i=0;i<size-1;i++)
    {
        temp=i;
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<arr[temp])
            {
                temp=j;
            }
        }
        key=arr[i];
        arr[i]=arr[temp];
        arr[temp]=key;
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int arr[100]={1,9,3,6,5},size=5;
    fnselectionsort(arr,size);
    return 0;
}