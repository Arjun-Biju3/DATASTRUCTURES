#include<stdio.h>
int sorted(int a[],int b)
{
    int i;
    for(i=0;i<b-1;i++)
    {
        if(a[i]>a[i+1])
        {
           return 0;
        }

    }
    return 1;
}

int main()
{
    int n,i,c;
    int arr[20];
    printf("enter the size of array:");
    scanf("%d",&n);
    printf("enter elements:");
    for(i=0;i<n;i++)
    {

        scanf("%d",&arr[i]);
    }
     for(i=0;i<n;i++)
    {

        printf("%d",arr[i]);
    }
 if(sorted(arr,n))
 {
     printf("sorted");

 }
 else{
         printf("unsorted");

 }


}
