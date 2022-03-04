#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
struct node*sp=(struct node *)0;
int flag;
void main()
{
void push(int);
int pop();
struct node*search(int),*t;
int data,opt;
do
{
printf("******************* singly linked stack operations ******************** \n");
printf("1. push\n");
printf("2. pop\n");
printf("3. search\n");
printf("4. exit\n");
printf("option\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
printf("data:\n");
scanf("%d",&data);
push(data);
break;
case 2:
data=pop();
if (flag==1)
printf("%d\n",data);

break;
case 3:
printf("item:\n");
scanf("%d",&data);
t=search(data);
if(t==(struct node*)0)
printf("not found\n");
else
printf("found\n");
break;
case 4:
exit(1);
}
}
while(1);
}
//function is push a data in linked stack
void push(int x)
{
struct node*t;
t=(struct node*)malloc(sizeof(struct node));
t->data=x;
t->next=sp;
sp=t;
}
//function to pop an item from linked stack
int pop()
{
int data;
struct node*t;
//flag=0;
if(sp==(struct node*)0)

printf("empty stack\n");

else
{
data=sp->data;
t=sp;
sp=sp->next;
free(t);
return data;
}
}
//function to search an item
//int linked stack
struct node*search(int data)
{
struct node*t=sp;
while(t!=(struct node*)0 &&t->data!=data)
t=t->next;
return t;
}