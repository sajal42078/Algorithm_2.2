
#include<stdio.h>

void insertion_sort(int a[],int n)
{
    int j;
    for(int i=1;i<n;i++)
    {
        int temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int b[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    insertion_sort(b,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    return 0;
}






