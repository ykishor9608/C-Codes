#include<stdio.h>
int fnbinarysearch(int arr[],int size)
{
    int num,mid,beg=0,end=size-1;
    printf("enter the number to search");
    scanf("%d",&num);
    while(end>=beg)
    {
        mid=(beg+end)/2;
        if(arr[mid]==num)
        {
            return mid;
        }
        else if(arr[mid]>num)
        {
            end=mid-1;
        }
        else
        {
            beg=mid+1;
        }
    }
    return -1;
}
int main()
{
    //array must be ordered.
    int arr[5]={1,2,3,4,5},size=5,res;
    res=fnbinarysearch(arr,size);
    if(res==-1)
    {
        printf("invalid output");
    }
    else
    {
        printf("number found at %d index",res);
    }
    return 0;
}