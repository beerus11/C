#include<stdio.h>
#include<conio.h>
int is(int[],int);
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
  is(a,n);
  for(i=0;i<n;i++)
  {
  printf("\n%d",a[i]);
  }
  getch();
  return 0;

}

int is(int a[],int n)
{
    int k,j,temp;
    for(k=1;k<n;k++)
    {
        temp=a[k];
        j=k-1;
        while((temp<a[j])&&(j>=0))
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }


    }
