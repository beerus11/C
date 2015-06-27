#include<stdio.h>
#include<conio.h>
#include<malloc.h>

int i,j,c=0;

//	Structure for stack

struct node
{
	int x;
	int y;
	struct node *next;
	struct node *prev;
};

//	Structures for Multi List
struct node1
{
	int sol;
	struct node1 *dp;
	struct node2 *rp;
}*temp11=NULL,*temp12,*temp13;

struct node2
{
	int x;
	int y;
	struct node2 *rp;
}*temp21=NULL,*temp22,*temp23;

int rec(struct node *k, int **p, int x, int y);
struct node * push(int x, int y, struct node *k);
struct node * pop(struct node *k);

int main()
{
	int a[4][4],max=100,count;
	struct node *temp;

	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
			a[i][j]=1;
	}
	a[0][0]=2;
	a[1][2]=0;
//	a[1][1]=0;
	a[2][1]=0;
//	a[2][3]=0;
	a[2][2]=0;
	a[3][3]=3;
	printf("\nMatrix is\n\n\n");
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{       printf("\t\t%d",a[i][j]);
		}
		printf("\n\n\n");
	}
	temp=(struct node*)malloc(sizeof(struct node));
	temp->x=0;
	temp->y=0;
	temp->next=NULL;
	temp->prev=NULL;
	rec(temp,a,temp->x,temp->y);
	printf("\n\nPossible paths are:");
	temp12=temp11;
	getch();
	while(temp12!=NULL)
	{
		temp21=temp12->rp;
		printf("\n\n\nSol %d is: ",temp12->sol);
		while(temp21!=NULL)
		{
			printf(" %d %d|",temp21->x,temp21->y);
			temp21=temp21->rp;
		}
		temp12=temp12->dp;
	}
	printf("\n\n\n\nShortest path is:");
	temp12=temp11;
	while(temp12!=NULL)
	{
		count=0;
		temp21=temp12->rp;
		while(temp21!=NULL)
		{
			count++;
			temp21=temp21->rp;
		}
		if(count<max)
		{
			max=count;
			temp13=temp12;
		}

		temp12=temp12->dp;
	}
	temp21=temp13->rp;
	while(temp21!=NULL)
	{
		printf(" %d %d|",temp21->x,temp21->y);
		temp21=temp21->rp;
	}
	getch();
}

int rec(struct node *temp1,int **k,int x, int y)
{
	struct node *temp2=NULL,*top,*temp4;
	int b[4][4];
	for(i=0;i<=3;i++)
		for(j=0;j<=3;j++)
			b[i][j]=*(k+4*i+j);
	/*
	for(i=0;i<=3;i++)
		for(j=0;j<=3;j++)
			printf("\n%d",b[i][j]);
	*/

	while(temp1!=NULL)
	{
		temp4=(struct node*)malloc(sizeof(struct node));
		temp4->x=temp1->x;
		temp4->y=temp1->y;
		temp4->prev=NULL;
		temp4->next=NULL;
		if(temp2==NULL)
		{
			top=temp4;
			temp2=temp4;
			//top=temp4;
		}
		else
		{
			top->next=temp4;
			temp4->prev=top;
			top=temp4;
		}
		temp1=temp1->next;
	}

	if(b[x][y]==3)
	{
		++c;
		temp12=(struct node1 *)malloc(sizeof(struct node1));
		temp12->sol=c;
		temp12->dp=NULL;
		temp12->rp=NULL;
		if(temp11==NULL)
		{
			temp11=temp12;
			temp13=temp12;
		}
		else
		{
			temp13->dp=temp12;
			temp13=temp12;
		}
		temp4=temp2;
		while(temp4!=NULL)
		{
			temp21=(struct node2 *)malloc(sizeof(struct node2));
			temp21->x=temp4->x;
			temp21->y=temp4->y;
			temp21->rp=NULL;
			if(temp12->rp==NULL)
			{
				temp12->rp=temp21;
				temp22=temp21;
			}
			else
			{
				temp22->rp=temp21;
				temp22=temp21;
			}
			temp4=temp4->next;
		}
		temp4=top;
	}
	else
	{
		b[x][y]=0;
		if(b[x+1][y]>=1&&(x+1)<=3)
		{
			top=push(x+1,y,top);
			rec(temp2, b,x+1, y);
			top=pop(top);
			top->next=NULL;
		}
		if(b[x-1][y]>=1&&(x-1)>=0)
		{
			top=push(x-1,y,top);
			rec(temp2, b,x-1, y);
			top=pop(top);
			top->next=NULL;
		}
		if(b[x][y+1]>=1&&(y+1)<=3)
		{
			top=push(x,y+1,top);
			rec(temp2, b,x, y+1);
			top=pop(top);
			top->next=NULL;
		}
		if(b[x][y-1]>=1&&(y-1)>=0)
		{
			top=push(x,y-1,top);
			rec(temp2, b,x, y-1);
			top=pop(top);
			top->next=NULL;
		}
	}
}

struct node * push(int x, int y, struct node *temp9)
{
	struct node *temp2;
	temp2=(struct node*)malloc(sizeof(struct node));
	temp2->next=NULL;
	temp2->prev=temp9;
	temp2->x=x;
	temp2->y=y;
	temp9->next=temp2;
	return temp2;
}
struct node * pop(struct node *temp9)
{
	temp9=temp9->prev;
	return temp9;
}
