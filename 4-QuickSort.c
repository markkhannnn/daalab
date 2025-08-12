#include<stdio.h>

int arr[100];
int partition(int low,int high )
{
    int pivot = arr[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}

void quickSort(int low,int high)
{
    if(low<high)
    {
        int p = partition(low,high);
        quickSort(low,p-1);
        quickSort(p+1,high);
    }
}


int main()
{
    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter elements : ");
    for(int i=0 ;i<n;i++)
        scanf("%d",&arr[i]);
    quickSort(0, n - 1);
    for(int i=0 ;i<n;i++)
        printf("%d ",arr[i]);

}