#include<stdio.h>
#include<stdlib.h>

int arr[20];

void merge(int low, int mid, int high)
{
    int aux[20];
    int left = low, right = mid+1, index = low;
    while(left<=mid && right <= high)
    {
        if(arr[left]<arr[right])
            {
                aux[index]=arr[left];
                left++;
            }
        else{
            aux[index]=arr[right];
            right++;
        }
        index++;
    }
    while(left<=mid)
    {
        aux[index++]=arr[left++];

    }
    while(right<=high)
        aux[index++]=arr[right++];
    for(int i=low;i<=high;i++)
        arr[i]=aux[i];
}

void Mergesort(int low,int high){
    if(low<high)
    {
        int mid = (low+high)/2;
        Mergesort(low,mid);
        Mergesort(mid+1,high);
        merge(low,mid,high);
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
    Mergesort(0, n - 1);
    for(int i=0 ;i<n;i++)
        printf("%d ",arr[i]);

}