#include <stdio.h>


struct bit
{
unsigned char x:1;
};

int uset[]={1,2,3,4,5,6,7,8,9},size=9;

 void main()
{
 void readset(struct bit[],int n);
 void printset(struct bit[]);
 void unionset(struct bit[],struct bit[],struct bit[]);
 void intersect(struct bit[],struct bit[],struct bit[]);
 void difference(struct bit[],struct bit[],struct bit[]);

 struct bit a[10]={0},b[10]={0},c[10]={0};
 int n,m;
 
 printf("no of elements in set a " );
 scanf("%d",&n);
 readset(a,n);

 printf("no of elements in set b " );
 scanf("%d",&m);
 readset(b,m);

//clrscr();
 
 printf("set a :");
 printset(a);
 printf("set b :");
 printset(b);
 
 unionset(a,b,c);
 printf("AUB =");
 printset(c);
 
 intersect(a,b,c);
 printf("A intersect B =");
 printset(c);

 difference(a,b,c);
 printf("A-B =");
 printset(c);

}

// to read a set and store as bit string

void readset(struct bit a[],int n)
  {
       int i,x,k,d;
       printf("enter %d elements :",n);
       for(i=0;i<n;i++)
            {
              scanf("%d",&d);
              for(k=0;k<size;k++)
              
              if (uset[k]==d)  //if it is a member of universal set
             
              {
                   a[k].x=1;
                   break;
              }
            }
  return;
  }
// to print a set from bit string representation

void printset(struct bit a[])

{
       int k;
       printf("{ ");
       for(k=0;k<size;k++)
              
              if (a[k].x==1)
              printf("%d ",uset[k]);
              printf(" } \n");
  return;
  }
// to find union of two set using bit string

void unionset(struct bit a[],struct bit b[],struct bit c[])
{
  int k;
  for(k=0;k<size;k++)
  c[k].x=a[k].x | b[k].x;
  return;
}

// to find intersection of two set using bit string

void intersect(struct bit a[],struct bit b[],struct bit c[])
{
  int k;
  for(k=0;k<size;k++)
  c[k].x=a[k].x & b[k].x;
  return;
}

// to find difference of two set using bit string

void difference(struct bit a[],struct bit b[],struct bit c[])
{
  int k;
  for(k=0;k<size;k++)
  c[k].x=a[k].x ^ b[k].x;
  return;
}






















