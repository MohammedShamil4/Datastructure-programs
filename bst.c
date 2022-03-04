#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *lchild;
  struct node *rchild;
};
void main()                                   //beginning of the main function 
{
  struct node *tinsert(struct node *,int);
  struct node *tdelete(struct node *,int);
  void inorder(struct node *);
  int opt,data;
  struct node *root=0;
  do
  {
    printf("\n...........options............\n");
    printf("\n 1.Insert\n 2.Delete\n 3.Traverse\n 4.Exit\n");
    printf("Option : ");
    scanf("%d",&opt);
    switch(opt)
    {
      case 1:printf("Data : ");
             scanf("%d",&data);
             root=tinsert(root,data);
             break;
      case 2:printf("Data to delete : ");
             scanf("%d",&data);
             root=tdelete(root,data);
             break;
      case 3:printf("Binary Search Tree content : \n");
             inorder(root);				//searching a node
             break;
      case 4:exit(1);
   }
  }while(1);
}                                                    	//end of main function

//function to insert a data in Binary Search Tree
struct node *tinsert(struct node *root,int data)
{
    struct node *t,*t1,*t2;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;                                     	//data is stored in 't'
    t->lchild=t->rchild=(struct node *)0;
    t1=root;                                       	//copy root to t1
                          				// find position to insert
    while(t1!=(struct node *)0 && t1->data!=data)   	//loop works until t1 points to null or t1 found duplicate data
    {
      t2=t1;
      if(data<t1->data)
        t1=t1->lchild;
      else
        t1=t1->rchild;
    }
    if(root==(struct node *)0)   			//case of null tree
      root=t;
    else{
    if(t1==(struct node *)0)
    {
      if(data<t2->data)
        t2->lchild=t;
      else t2->rchild=t;
    }
    else printf("Duplicate \n");
    }
    return root;
}


//function to inorder traverse the binary tree
void inorder(struct node *root)
{
    if(root!=(struct node *)0)
    {
    inorder(root->lchild);
    printf("%d ",root->data);
    inorder(root->rchild);
    }
    return;
}


//function to delete data from binary tree
struct node * tdelete(struct node *root,int data)
{
    struct node *par,*t1,*sucpar,*t2;
                                       		//searching
    par=(struct node *)0;
    t1=root;
    while(t1!=(struct node *)0 && t1->data!=data)
    {
       par=t1;                           	//to get the parent node
       if(data<t1->data)
         t1=t1->lchild;
       else t1=t1->rchild;
    }
    if(t1==(struct node *)0)
       printf("Not Found");
    else
    {
    
    //delete root
    if(t1==root)
    {
    //if root have no child
    if(root->lchild == 0 && root->rchild == 0 && root->data == data)
    root=(struct node *)0;

    //if root have only one child
    else if(root->lchild == 0)
    {
      root=root->rchild;
      root->rchild=(struct node *)0;
    }
    else if(root->rchild == 0)
    {
      root=root->lchild;
      root->lchild=(struct node *)0;
    }

    //if root have two child
    else
    {
    sucpar=root;
    t2=root->rchild;
    while(t2->lchild != 0)    		//to find extreme left
    {
      sucpar=t2;
      t2=t2->lchild;
    }
    root->data=t2->data;
    //copy the inorder successor data to the data to be deleted
    //then remove inorder successor
    if(t2->data < sucpar->data)     	//the inorder successor is a left child
      sucpar->lchild=t2->rchild;
    else
      sucpar->rchild=t2->rchild;
    free(t2);
    } 
    }
    else if(t1->lchild==0 && t1->rchild==0)     //case of leaf node
    {
    if(t1->data < par->data)       		//to check if t1 is left child of par
    par->lchild=0;
    else par->rchild=0;
    free(t1);
    }
    else if(t1->lchild==0)         		//case of one right child
    {
    if(t1->data < par->data)
    par->lchild=t1->rchild;
    else par->rchild=t1->rchild;
    free(t1);
    }
    else if(t1->rchild==0)        		//case of one left child
    {
    if(t1->data < par->data)
       par->lchild=t1->lchild;
    else par->rchild=t1->lchild;
       free(t1);
     }
     else                         		//case of two children
     {
       sucpar=t1;
       t2=t1->rchild;
       while(t2->lchild!=0)        		//to find extreme left
       {
         sucpar=t2;
         t2=t2->lchild;
       }
       t1->data=t2->data;
       //copy the inorder successor data to the data to be deleted
       //then remove inorder successor
       if(t2->data < sucpar->data)   //the inorder successor is a left child
          sucpar->lchild=t2->rchild;
       else
          sucpar->rchild=t2->rchild;
          free(t2);
     }

}
return root;
}





/*

...........options............

 1.Insert
 2.Delete
 3.Traverse
 4.Exit
Option : 1
Data : 8

...........options............

 1.Insert
 2.Delete
 3.Traverse
 4.Exit
Option : 1
Data : 3

...........options............

 1.Insert
 2.Delete
 3.Traverse
 4.Exit
Option : 1
Data : 9

...........options............

 1.Insert
 2.Delete
 3.Traverse
 4.Exit
Option : 1
Data : 4

...........options............

 1.Insert
 2.Delete
 3.Traverse
 4.Exit
Option : 3
Binary Search Tree content : 
3 4 8 9 
...........options............

 1.Insert
 2.Delete
 3.Traverse
 4.Exit
Option : 2
Data to delete : 8

...........options............

 1.Insert
 2.Delete
 3.Traverse
 4.Exit
Option : 3
Binary Search Tree content : 
3 4 9 
...........options............

 1.Insert
 2.Delete
 3.Traverse
 4.Exit
Option : 2
Data to delete : 3

...........options............

 1.Insert
 2.Delete
 3.Traverse
 4.Exit
Option : 2
Data to delete : 4

...........options............

 1.Insert
 2.Delete
 3.Traverse
 4.Exit
Option : 3
Binary Search Tree content : 
9 
...........options............

 1.Insert
 2.Delete
 3.Traverse
 4.Exit
Option : 2
Data to delete : 9

...........options............

 1.Insert
 2.Delete
 3.Traverse
 4.Exit
Option : 3
Binary Search Tree content : 

...........options............

 1.Insert
 2.Delete
 3.Traverse
 4.Exit
Option : 4
*/



 
