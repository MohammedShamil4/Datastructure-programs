//Red Black Tree

#include<stdio.h>
#include<stdlib.h>
struct node
{
int key;
char color;
struct node *par;
struct node *left;
struct node *right;
};
void main()
{
struct node * left_rotate(struct node *,struct node *);
struct node * right_rotate(struct node *,struct node *);
struct node * rb_insert_fixup(struct node *,struct node *);
struct node * rb_insert(struct node *,struct node *);
void inorder(struct node *);
struct node *T=0,*z,*k1,*k2;
int i,n,key;
printf("Enter no. of keys to insert:");
scanf("%d",&n);
printf("Enter values:\n");
for(i=0;i<n;i++)
{
scanf("%d",&key);
z=(struct node*)malloc(sizeof(struct node));
z->key=key;
T=rb_insert(T,z);
}
printf("\nRedBlack tree:\n");
inorder(T);
}
struct node * left_rotate(struct node *T,struct node *x) //Function to left rotate
{
struct node *y=x->right;
x->right=y->left; //y's left tree is atttched as x's
if(y->left!=0)
{
y->left->par=x;
}
y->par=x->par; //store x's parent as y's prent
if(x->par==0) //if x is root then set y as root
T=y;
else if (x==x->par->right) //if x is left child of the parent
x->par->right=y;
else
x->par->left=y;
y->left=x;
x->par=y;
return T;
}
struct node * right_rotate(struct node *T,struct node *x) //Function to right rotate
{
struct node *y=x->left;
x->left=y->right; //y's right tree is atttched as x's
if(y->right!=0)
y->right->par=x;
y->par=x->par; //store x's parent as y's prent
if(x->par==0) //if x is root then set y as root
T=y;
else if (x==x->par->left) //if x is left child of the parent
x->par->left=y;
else
x->par->right=y;
y->right=x;
x->par=y;
return T;
}
struct node * rb_insert_fixup(struct node *T,struct node *z)
{
struct node *y;
while(z->par!=0 && z->par->color=='R')
{
if(z->par==z->par->par->left)
{
y=z->par->par->right; //y is uncle
if(y!=0 && y->color=='R')
{
z->par->color='B';
y->color='B';
z->par->par->color='R';
z=z->par->par;
}
else
{
if(z==z->par->right)
{
z=z->par;
T=left_rotate(T,z);
}
z->par->color='B';
z->par->par->color='R';
T=right_rotate(T,z->par->par);
}
}
else
{
y=z->par->par->left;
if(y!=0 && y->color=='R')
{
z->par->color='B';
y->color='B';
z->par->par->color='R';
z=z->par->par;
}
else
{
if(z==z->par->left)
{
z=z->par;
T=right_rotate(T,z);
}
z->par->color='B';
z->par->par->color='R';
T=left_rotate(T,z->par->par);
}
}
}
T->color='B';
return T;
}
struct node * rb_insert(struct node *T,struct node *z)
{
struct node *y=0,*x;
x=T;
while(x!=0)
{
y=x;
if(z->key<x->key)
x=x->left; //move to left child
else
x=x->right; //move to right child
}
z->par=y;
if(y==0) //If tree is null
T=z; //First node insertion
else if(z->key<y->key)
y->left=z; //z is left child of its parent
else
y->right=z; //z is right child of its parent
z->left=0;
z->right=0;
z->color='R';

T=rb_insert_fixup(T,z); //Fixing nodes and its colors
return T;
}
void inorder(struct node *x)
{
if(x!=NULL)
{
inorder(x->left);
printf("%d(%c)\n",x->key,x->color);
inorder(x->right);
}
}