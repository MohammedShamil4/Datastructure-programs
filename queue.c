#define size 10
#include<stdio.h>
#include<stdlib.h>
int stk[size];
int front=0;
int rear=0;
int stat;
void main()
{
 void insert(int);
 int del();
int search(int);
 int opt,item,k;
 do
   {
      printf("******************* queue operations ******************** \n");
      printf("1.insertion \n");
      printf("2.deletion \n");
      printf("3.search \n");
      printf("4.exit \n");
      printf("your option :\t");
	scanf("%d",&opt);
   
    if(opt==1)	
           {
 		printf("enter the item :\n");
		scanf("%d",&item);
		insert(item);
           }
    else if(opt==2)	
           {
		item=del();
 if(stat==1)
 		printf("deleted item :%d \n",item);
           }
    else if(opt==3)	
           {
 		printf("enter value to be searched :\n");
                scanf("%d",&item);
                k=search(item);
                if(k==0)
                printf("item not found \n");
           }
    else

        exit(1);
   }
 while(1);
}
 void insert(int x)
{
  int t;
  t=(rear+1)%size;
  if(front==t)
     {
        printf("queue is full \n");
return;
     }
    rear=t;
    stk[rear]=x;
}
 int del()
  {
  int r;
   if(front==rear)
{
 printf("queue is empty \n");
 stat=0;
}
else
{
front=(front+1)%size;
stat=1;
return stk[front];
}
}
int search(int item)
{
int f,r;
f=front;
r=rear;
while(f!=r)
{
 f=(f+1)%size;
 if(stk[f]==item)
{
 printf("item found \n");
  return 1;
}
}
return 0;
}
