//for best case{O(n)}.
#include<stdio.h>
void fnbubblesort(int arr[],int size)
{
    int search=1;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                search=0;
            }
        }
        if(search)
        {
            break;
        }
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]); 
    }
}
int main()
{
    int arr[100],size;
    printf("Enter the size of array:");
    scanf("%d",&size);
    printf("Enter the elements in array:\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Array before sorting is:");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nArray after sorting is:");
    fnbubblesort(arr,size);
    return 0;
}