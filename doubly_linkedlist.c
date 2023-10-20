#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start=NULL,*new_node,*current,*tail;
void create()
{
 int n;
 printf("enter the number of nodes needed:\n");
 scanf("%d",&n);
 printf("Enter %d data:",n);
 for(int i=0;i<n;i++)
 {
 new_node=(struct node *)malloc(sizeof(struct node));
 scanf("%d",&new_node->data);
 new_node->prev=NULL;
 new_node->next=NULL;
 if(start==NULL)
 {
     start=tail=new_node;
     current=new_node;
 }
 else{
    current->next=new_node;
    new_node->prev=current;
    current=tail=new_node;

 }
 }
}
void insrt_beginig()
{
 new_node=(struct node *)malloc(sizeof(struct node));
 printf("Enter data:");
 scanf("%d",&new_node->data);
 new_node->prev=NULL;
 new_node->next=NULL;
 if(start==NULL)
 {
     start=new_node;

 }
 else{
    start->prev=new_node;
    new_node->next=start;
    start=new_node;
 }
}
void insrt_end()
{
  new_node=(struct node *)malloc(sizeof(struct node));
 printf("Enter data:");
 scanf("%d",&new_node->data);
 new_node->prev=NULL;
 new_node->next=NULL;
 if(start==NULL)
 {
     start=new_node;

 }
 else
 {
   tail->next=new_node;
   new_node->prev=tail;
   tail=new_node;
 }
}

void insrt_at_position()
{
  int i=1;
  int pos;
  int co=count();
  printf("enter position to insert:\n");
  scanf("%d",&pos);
  if(pos<1)
  {
      printf("invalid location\n");
  }
  else if(pos>co)
  {
      printf("please check the size of list\n");
  }
  else if(pos==1)
  {
      insrt_beginig();
  }
  else if(pos==co)
  {
      insrt_end();
  }
  else
  {
     new_node=(struct node *)malloc(sizeof(struct node));
     printf("Enter data:");
     scanf("%d",&new_node->data);
     new_node->prev=NULL;
     new_node->next=NULL;
     current=start;
    while(i<pos-1)
    {
     current=current->next;
     i++;
    }
    new_node->prev=current;
    new_node->next=current->next;
    current->next=new_node;
    new_node->next->prev=new_node;
  }
}
int count()
{     int count=0;
      for(current=start;current!=NULL;current=current->next)
    {
        count++;
    }
    return count;
}
void display()
{
    printf("doubly linked list is:\n");
    current =start;

   while(current != NULL) {
      printf("[%d]-> ",current->data);
      current = current->next;
   }
   printf("NULL");

}
int main()
{
    create();
    display();
    int opt;
    int a=1;
    while(a==1)
    {

    printf("\n");
    printf("SELECT THE OPERATION:\n");
    printf("1.INSERT AT BEGINING\n");
    printf("2.INSERT AT END\n");
    printf("3.INSERT AT ANY POSITION\n");
    printf("4.EXIT\n");
    printf("SELECT AN OPTION:\n");
    scanf("%d",&opt);

    switch(opt)
    {

    case 1:
        {
            insrt_beginig();
            display();
            break;
        }
    case 2:
        {
            insrt_end();
            display();
            break;
        }
    case 3:
        {
            insrt_at_position();
            display();
            break;
        }
    case 4:
        {
            printf("exited\n");
            a=0;
            break;
        }
    default:
        {
            printf("enter valid option");
        }
    }
    }

}
