//for best case{O(n)}
#include<stdio.h>
void fninsertionsort(int arr[])
{
    int i,j,temp;
    for(i=0;i<=5;i++)
    {
        temp=arr[i];
        for(j=i-1;j>=0&&temp<arr[j];j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
    for(i=0;i<5;i++)
    {
        printf("%d",arr[i]);
    }


//alternative code
    // int i,key,j;
    // for(i=1;i<=size-1;i++)
    // {
    //     key=arr[i];
    //     j=i-1;
    //     while(j>=0 && arr[j]>key)
    //     {
    //         arr[j+1]=arr[j];
    //         j--;
    //     }
    //     arr[j+1]=key;
    // }
    // for(i=0;i<size;i++)
    // {
    //     printf("%d ",arr[i]); 
    // }
}
int main()
{
    int arr[5]={3,7,8,2,5};
    fninsertionsort(arr);
    return 0;
}