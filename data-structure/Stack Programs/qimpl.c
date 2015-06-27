#include<stdio.h>
#include<conio.h>
int queue[5];
int front=-1,rear=-1;
int insert();
int del();
int disp();
void main()
{


    int ch,l=1;
  while(l!=0)
  {
  printf("\n--------------QUEUE OPERATIONS-------------");
  printf("\n1.insert element");
  printf("\n2.delete ement");
  printf("\n3.display element");
  printf("\n4.exit element");
 ch=getch();
  switch(ch)
  {
         case'1':insert();
         break;
         case'2':
         printf("\nthe no deleted is %d",del());
         break;
         case'3':disp();
         break;
         case '4':
               exit(0);
               break;
               default:  printf("invlid input");
               }
               l=getch();

               }
               }

               int insert()
               {
               int item;
               if(rear>4)
               {
          printf("queue is full");
        getch();
        return 0;;
               }

               else
               {

                              if(front==-1)
               {
                 front=front+1;
               }
               printf("enter item to insert");
               scanf("%d",&item);
               front=front+1;
               rear=rear+1;
               queue[rear]=item;

               }



               }
               int del()
               {
                  int item;
               if(front==-1)
               {

               printf("stack is empty");
               }

               else
               {

                  item=queue[rear];
                  rear--;

               }
               return(item);
               }
               int disp()
               {   int i;
                   if(front==-1)
                   {
                   printf("qeue is empty");
                   }
                   else
                   {
                   for(i=0;i<=rear;i++)
                   {
                   printf("\n %d",queue[i]);

                   }

                   }

                   return 0;
                   }





