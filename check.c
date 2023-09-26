#include<stdio.h>
int check(int a[],int n)
{
    if(n==1)
    {
     return 1;
    }
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            return 0;
        }
    }
    return 1;
}

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

void merge(int a[],int b[],int n1,int n2,int r[])
{
  int i=0,j=0,k=0;
 while(i<n1&&j<n2)
 {
  if(a[i]<b[j])
  {
    r[k++]=a[i++];
  }
  else
  {
    r[k++]=b[j++];
  }
 }
 while(i<n1)
 {
  r[k++]=a[i++];
 }
 while(j<n2)
 {
  r[k++]=b[j++];
 }
}
int main()
{
    int n,n1;

    printf("enter size of first aray:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the size of second array:");
    scanf("%d",&n1);
    int two[n1];
    int res[n+n1];
    printf("enter first array:");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    printf("enter second array:");

    for(int i=0;i<n1;i++)
    {
        scanf("%d",&two[i]);

    }



    //checking

    if(check(arr,n) && check(two,n))
    {

        merge(arr,two,n,n1,res);
    }
    else
    {
      sort(arr,n);
      sort(two,n1);
      merge(arr,two,n,n1,res);


    }

    printf("merged array:\n");

     for(int i=0;i<n+n1;i++)
    {
        printf("%d\n",res[i]);

    }


}
