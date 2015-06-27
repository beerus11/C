#include<stdio.h>
#include<conio.h>
int ss(int[],int);
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
  ss(a,n);
  for(i=0;i<n;i++)
  {
  printf("\n%d",a[i]);
  }
  getch();
  return 0;

}

int ss(int a[],int n)
{
int min,i,j,temp;
for(i=0;i<n;i++)
{
    min=a[i];
    for(j=i+1;j<n;j++)
    {
 if(min>a[j])
 {
 temp=a[j];
 a[j]=min;
 min=temp;
 }
 a[i]=min;
    }
}
}
