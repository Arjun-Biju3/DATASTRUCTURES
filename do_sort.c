#include<stdio.h>

int sort(int a[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

}
int main()
{
    int n;

    printf("enter size of aray:");
    scanf("%d",&n);
    int arr[n];
    int r[n];
    printf("enter array elements:");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    printf("array\n");
     for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);

    }
    sort(arr,n);
    printf("sorted array");
     for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);

    }

}
