#include<stdio.h>
void readarr(int[],int);
  void disparr(int[],int);
  void merge(int[],int[],int[],int,int);

void main()
{

  
 int a[50],b[50],c[105],n,m;

 printf("no.of elements in first array [1-50]:\n");
 scanf("%d",&m);
 printf("enter elements in non decreasing order:\n");
 readarr(a,m);
 printf("no.of elements in second array [1-50]:\n");
 scanf("%d",&n);
 printf("enter elements in  non decreasing order:\n");
 readarr(b,n);

 merge(a,b,c,m,n);
 printf("merged array: \n");
 disparr(c,(m+n));

}
                         void readarr(int a[],int m)
                      { 
                          int i;
                         
                          for(i=0;i<m;i++)
                          scanf("%d",&a[i]);
                          return;
                       }


                         void disparr(int x[],int k)
                { 
                  int i;
                
                  for(i=0;i<k;i++)
                  printf("%d \n",x[i]);
                  return;
                }
       void merge(int a[],int b[],int c[],int m,int n)
  { 
    int i,j,k;
    i=k=j=0;
    while(i<m && j<n)
   {
       if(a[i]<b[j])
            {
              c[k]=a[i];
              i=i+1;
              k=k+1;
            }
       else
           {
              c[k]=b[j];
              j=j+1;
              k=k+1;
            }
    }
         while (i<m)
{
         //s3[k++]=s1[i++];
            c[k]=a[i];
              i=i+1;
              k=k+1;
}
        while (j<n)
{
       // s3[k++]=s2[j++];
            c[k]=b[j];
              j=j+1;
              k=k+1;
}
   return;
}





