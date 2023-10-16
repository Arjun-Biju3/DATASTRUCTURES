
#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node *next;
};
struct node *new_node,*current,*top=NULL;
void push()
{
new_node=(struct node *)malloc(sizeof(struct node));
printf("enter value to push\n");
scanf("%d",&new_node->data);
new_node->next=top;
top=new_node;
printf("stack is\n");
for(current=top;current!=NULL;current=current->next)
{
printf("[%d]\n",current->data);
}
}
void pop()
{
 if(top==NULL)
{
printf("stack is empty\n");
}
 else
{
 current=top;
 top=top->next;
 free(current);
 printf("value deleted\n");
 for(current=top;current!=NULL;current=current->next)
{
printf("[%d]\n",current->data);
}
}
}
void search()
{
 current=top;
 int i=1;
 int flag=0;
int val;
 printf("enter value to search:");
 scanf("%d",&val);
 while(current!=NULL)
{
 if(val==current->data)
 {
   flag=1;
   break;

 }

 current=current->next;
 i++;
}
if(flag)
{

 printf("element is found at %d node\n",i);

}
else
{
 printf("element not found\n");
}
}
int main()
{
int aa=1;
while(aa==1)
{
int opt;
printf("opertions are\n");
printf("1.push\n");
printf("2.pop\n");
printf("3.search\n");
printf("4.exit\n");
printf("select option:\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
{
push();
break;
}
case 2:
{
pop();
break;
}
case 3:
{
search();
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
printf("enter valid option\n");
}
}
}
}



