#include<stdio.h>
#include<stdlib.h>



               struct node
             {
	        int data;
		struct node*left,*right;
	      };
struct node*start=NULL;


void main()
{
 void insert(int);
 void delete(int);
 struct node* search(int);
 struct node*t;
 int a,b,opt;
 do
   {
      printf("******************* doubly linked list operations ******************** \n");
      printf("1.insert \n");
      printf("2.delete \n");
      printf("3.search \n");
      printf("4.exit \n");
      printf("your option :\t");
	scanf("%d",&opt);
   
    if(opt==1)	
           {
 		printf("enter the item to inserted:\n");
		scanf("%d",&a);
		insert(a);
           }
    else if(opt==2)	
           {
		

 		printf("item to deleted : \n");
                scanf("%d",&a);
                 delete(a);
           }
    else if(opt==3)	
           {
 		printf("enter value to be searched :\n");
                scanf("%d",&b);
                t=search(b);
                if(t==(struct node*)0)
                printf("item not found \n");
             else
                printf("item found\n");
           }
    else

        exit(1);
   }
 while(1);
}

//insertion function
 void insert(int item)
{

 struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node)); 
newnode->data=item;
 if (start==NULL)
{
 newnode->left=newnode->right=NULL;
 start=newnode;
}
else
  {
newnode->left=(struct node*)0;
newnode->right=start;
start->left=newnode;
start=newnode;
 }
}
struct node* search(int d)
{
   
   struct node *ptr;
   ptr=start;
   while(ptr!=(struct node*)0 && ptr->data!=d)
   {
ptr=ptr->right;
}
return ptr;
}
//function for deletion
void delete(int x)
{

struct node *t;
t=search(x);
if(t==NULL)
{
  printf("not found\n");
}
else
 {
   if (t==start)
    if(t->right==NULL)
   {
 start=NULL;
}
   else
{
  t->right->left=NULL;
  start=t->right;
}
 else if (t->right==NULL)
  {
  t->left->right=NULL;
 }
else
{
    t->left->right=t->right;
    t->right->left=t->left;
}
}
   free(t);
}

