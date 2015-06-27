#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
int pop();
int push();
int traversal();
#define MAX 10
int top=-1;
int stack[MAX];
int main()
{

      int l;
      int ch;

          while(l!=0)
          {

           printf("\n---------STACK OPERATIONS--------");
       printf("\n1.PUSH");
        printf("\n2.POP");
         printf("\n3.TRAVERSAL");
          printf("\n4.EXIT");
          ch=getch();

      switch(ch)
      {




        case'1':push();
                break;
        case'2':
          printf("item  deleted is :%d ",pop());
                break;
       case'3': traversal();
                break;
        case'4':exit(0);
                break;

                default:
                printf(" \n WRONG INPUT");

    }

    printf("\ncontinue");
       l=getch();

       fflush(stdin);
          }

  return 0;
  }


  int push()
  {
       int item;
      if(top==MAX-1)
      {
         printf(" \nSTACK  FULL");
      }
    else
    {
       printf("\nenter element to be inserted");
       scanf("\n%d",&item);
       stack[top+1]=item;
       top=top+1;


    }
    return 0;
  }

  int pop()
  {
    int item;

  if(top==-1)
  {
  printf("stack is empty");

  }
  else
  {
      item=stack[top];
     top=top-1;

     }

   return(item);
  }
int traversal()
{   int i;
   for(i=top;i>=0;i--)
   {
   printf("\n  %d  ",stack[i]);


   }
return 0;

}
