#include<stdio.h>
#include<malloc.h>
int main()
{   int option;
    int pos,i=1;
    struct node
    {


    int data;
    struct node * next;
     };

    struct node *new_node,*current,*start=NULL;
    int n;
    printf("enter the number of nodes needed:");
    scanf("%d",&n);
    printf("enter %d values ",n);
    for(int i=0;i<n;i++)
    {
     new_node=(struct node *)malloc(sizeof(struct node));
     scanf("%d",&new_node->data);
     new_node->next=NULL;
     if(start==NULL)
     {
         start=new_node;
         current=new_node;
     }
     else{
        current->next=new_node;
        current=new_node;
     }
    }
    printf("linked list is:\n");
    for(current=start;current!=NULL;current=current->next)
    {
        printf("%d ->",current->data);
    }


    printf("null\n");
    int aa=1;
    while(aa==1)
    {

    printf("select option:\n");
    printf("1.insert at begining\n");
    printf("2.insert at end\n");
    printf("3.insert at any position\n");
    printf("4.exit\n");
    printf("what do you want to perform:\n");

    scanf("%d",&option);



    switch(option)
    {

case 1:
    {

    printf("\nenter the node to insert at begining \n");
    new_node=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    if(start==NULL)
    {
        start=new_node;

    }
    else{
       new_node->next=start;
       start=new_node;
    }
     printf("linked list after insertion is:\n");
    for(current=start;current!=NULL;current=current->next)
    {
        printf("%d ->",current->data);
    }
     printf("null");
     break;
    }
case 2:
    {



     printf("\nenter the node to insert at end\n");
     new_node=(struct node *)malloc(sizeof(struct node));
     scanf("%d",&new_node->data);
     new_node->next=NULL;
     current=start;
     while(current->next!=NULL)
     {
         current=current->next;
     }
     current->next=new_node;
     printf("linked list after insertion at end is:\n");
    for(current=start;current!=NULL;current=current->next)
    {
        printf("%d ->",current->data);
    }
     printf("null\n");
     break;
    }
     /*====================*/
case 3:
    {


     int count=0;
      for(current=start;current!=NULL;current=current->next)
    {
        count++;
    }
     //printf("%d",count);

     printf("enter the position to insert:\n");
     scanf("%d",&pos);
     if (pos> count)
     {

         printf("invalid position\n");
     }
     else{

        current=start;
        while(i<pos)
        {
            current=current->next;
            i++;
        }
     printf("enter data\n");
     new_node=(struct node *)malloc(sizeof(struct node));
     scanf("%d",&new_node->data);
     new_node->next=current->next;
     current->next=new_node;

     }
      for(current=start;current!=NULL;current=current->next)
    {
        printf("%d ->",current->data);
    }
     printf("null\n");
     break;
    }
case 4:
    {

        printf("exited\n");
       aa=0;
       break;



    }
default:
    {
        printf("select valid option\n");

    }
    }
    }
}
