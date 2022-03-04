//2 way merging
#include<stdio.h>
void main()
{
void readarr(int[],int);
void disparr(int[],int);
void merge(int[],int[],int[],int,int);
int s1[50],s2[50],s3[100],n,m;
printf("no. of elements in first array[1-50]:");
scanf("%d",&n);
printf("enter the elements in first array:");
readarr(s1,n);
printf("no. of elements in second array[1-50]:");
scanf("%d",&m);
printf("enter the elements in second array:");
readarr(s2,m);
merge(s1,s2,s3,n,m);
printf("merged array:\n");
disparr(s3,m+n);
}
//function for reading an array
void readarr(int s[],int n)
{
int i;
printf("enter nos in non decreasing order:");
for(i=0;i<n;++i)
scanf("%d",&s[i]);
return;
}
//function for displaying an array
void disparr(int s[],int n)
{
int i;
for(i=0;i<n;++i)
printf("%d\n",s[i]);
return;
}
//function for merging an array
void merge(int s1[],int s2[],int s3[], int m,int n)
{
int i,j,k;
i=j=k=0;
//compare and copy elements
while(i<m&&j<n)
{
if(s1[i]<s2[j])
{
s3[k]=s1[i];
i=i+1;
k=k+1;
}
else
{
s3[k]=s2[j];
j=j+1;
k=k+1;
}
}
//copy remaining elements from s1
if(i<m)
while(i<m)
s3[k++]=s1[i++];
//from s2
else
while(j<n)
s3[k++]=s2[j++];
return;
}