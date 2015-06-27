#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct list
{
 int data;
 struct list *link;
};

typedef struct list node;
node *start=NULL,*end,*temp;

void create()
{
 temp=(node*)malloc(sizeof(node));
  printf("\nENTER DATA : ");
  scanf("%d",&temp->data);
  temp->link=NULL;
  if(start==NULL)
  {
   start=temp;
   end=temp;
  }
  else
  {
   end->link=temp;
   end=temp;
  }
  printf("\nDATA ADDED SUCCESSFULLY");
 getch();
}

void display()
{
 if(start==NULL)
  printf("LIST EMPTY");
 else
 {
  temp=start;
  for(;temp!=NULL;temp=temp->link)
  {
   printf("%d\n",temp->data);
  }
 }
 getch();
}

void main()
{
 int c,m;
 do
 {
  clrscr();
  printf("MENU\n");
  printf("1.ADD\n");
  printf("2.DISPLAY\n");
  printf("3.EXIT");
  printf("\n\nENTER YOUR CHOICE : ");
  scanf("%d",&c);
  switch(c)
  {
   case 1 : create();	break;
   case 2 : display();	break;
   case 3 : exit(0);
   default: printf("\n\nFOLLOW THE INSTRUCTIONS!!!"); getch(); break;
  }
 }while(c!=3);
}