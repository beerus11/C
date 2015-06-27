#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
int pop();
int push();
int traversal();
struct stack
{

    int no;
    struct stack *prev;
};
typedef struct stack st;
st *temp,*head,*top;
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
       head=NULL;
       temp=(st*)malloc(sizeof(st));
       temp->prev=NULL;
       head->prev=NULL;
       printf("enter no");
       scanf("%d",&head->no);
       head->prev=temp;
       head->prev=top;
       head=temp;

    return 0;
  }

  int pop()
  {
        st *p;
    if(head==NULL)
    {
        printf("\nstack is empty");
    }
    else
    {     p=top;
        top=top->prev;
        free(p);

    }
    return(p->no);
  }
int traversal()
{
    temp=top;
    while(temp->prev=NULL)
    {
        printf("\n%d",&temp->no);
        temp=temp->prev;
    }
    return 0;
}
