#include<stdio.h>
#include<conio.h>
int bs(int[],int);
int main()
{
    int a[100],i,j,n,e;

  printf("\n  Enter no of elements of array   :   ");
  scanf("\n%d",&n);
  for(i=0;i<n;i++)
  {
     scanf("\n%d",&e);
     a[i]=e;
  }
  bs(a,n);
  for(i=0;i<n;i++)
  {
  printf("\n%d",a[i]);
  }
  getch();
  return 0;

}

int bs(int a[],int n)
{
int temp,i,j;
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{

if(a[j]>a[j+1])
{
temp=a[j+1];
a[j+1]=a[j];
a[j]=temp;
}
}
}
}
