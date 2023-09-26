#include<stdio.h>
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
  int n1;
  int a[n1];
  int n2;
  int b[n2];
  int r[n1+n2];
 printf("enter size of first array:");
 scanf("%d",&n1);
  printf("enter size of second array:");
 scanf("%d",&n2);
 printf("enter first array:");
 for(int i=0;i<n1;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("enter second array:");
 for(int i=0;i<n2;i++)
 {
  scanf("%d",&b[i]);
 }
 merge(a,b,n1,n2,r);
 printf("sorted array:\n");
 for(int i=0;i<n1+n2;i++)
 {
  printf("%d",r[i]);
 }


}
