#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>

struct record {                
	char name[30];
	char type[15];        
	int qty;
} item;

struct record1 {              
	    char name[20];
	    char addr[40];char pnum[15];
	    char dob[15];
	    char pm[15];
	    char item[20];
	    
} customer;
void day();
void firstscreen(void);
void somoy();
void pass(void);
int Password (void);
void printTitle(void);
void help(void);
void showMenu(void);               
void customerf(void);
void itemf(void);
void start(void);
void menu(void);                  
void add_item(void);
void edit_item();
void delete_item(void);
void add_customer(void);         
void edit_customer(void);
void delete_customer(void);
void end(void);
void view_item(void);
void view_customer(void);
void option1(void);
void end2(void);
int Password(void);
void inv(void);
int c=0,d=0;
int Proceed;


	int driver=VGA,mode=VGAHI;
void pass()
{
do
	{
	   Proceed = Password();
	} while ( Proceed!=1);
}

void main(void)
{

		   	
         clrscr();
         help();

         
	initgraph(&driver,&mode,"c:\\tc\\bgi"); 	
        
	randomize();

         pass();
	 firstscreen();
	
	cleardevice();
	start();                         
	menu();
	getch();                        
	closegraph();
}
void start(void)
{        day();
        somoy();                                  
	setcolor(RED);
	setlinestyle(SOLID_LINE,1,3);
	rectangle(0,0,639,479);            
	setcolor(BLUE);
	setlinestyle(SOLID_LINE,1,2);     
	rectangle(10,10,629,469);
}

void showMenu(void)
{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
		setcolor(WHITE);					
		outtextxy(60,150,"1) ADD ITEMS");	
		outtextxy(60,210,"2) RECORD");
                outtextxy(60,270,"3) BOOK ORDER");
                outtextxy(60,330,"4) CANCEL ORDER");		
		outtextxy(60,390,"5) EXIT");			
}

void menu(void)
{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
		setcolor(WHITE);					
		outtextxy(60,150,"1) ADD ITEMS");	
		outtextxy(60,210,"2) RECORD");
                outtextxy(60,270,"3) BOOK ORDER");
                outtextxy(60,330,"4) CANCEL ORDER");		
		outtextxy(60,390,"5) EXIT");	

	while (1)          						
   {
	while(!(kbhit()))
	{
		printTitle();
	}

	switch(getch())                					
	{
		case '1':

			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,150,"1) ADD ITEMS");	
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,150,"1) ADD ITEMS");	
			delay(500);

			itemf();
			cleardevice();
			start();
			showMenu();
			break;
		case '2':
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,210,"2) RECORD");	
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,210,"2) RECORD");	
			delay(500);

			view_customer();
			cleardevice();
			start();
			showMenu();
			break;
		
                case '3':
                        settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,270,"3) BOOK ORDER");			
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,270,"3) BOOK ORDER");			
			delay(500);
			add_customer();
	       case '4':
                        settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,330,"4) CANCEL ORDER");			
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,330,"4) CANCEL ORDER");			
			delay(500);
			delete_item();
               case '5':
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,390,"5) EXIT");			
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,390,"5) EXIT");			
			delay(500);

			end();
			cleardevice();
			start();
			showMenu();                                
			break;
		default:
			inv();
	}
    }
}
void printTitle(void)
{
		int temp, temp2;

		temp=(rand()% 15)+1;
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);		
		setcolor(temp);						
		outtextxy(16,40,"WELCOME TO HOME SHOP 18");	

		temp2=(rand()%15)+1;
		setcolor(temp2);						
		line(20,80,621,80);       				

		delay(400);						

}

void itemf(void)
{
	d=0,c=0;
	cleardevice();
	start();

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
	setcolor(LIGHTBLUE);
	outtextxy(25,40," item INFORMATION");
	setcolor(YELLOW);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);

	outtextxy(60,150,"1)ADD item INFORMATION");
	outtextxy(60,210,"2)DELETE item INFORMATION");
	outtextxy(60,270,"3)VIEW item INFORMATION");
	outtextxy(60,330,"4)EDIT item INFORMATION");
	outtextxy(60,390,"5)GO BACK TO THE MAIN MENU");
	switch(getch())
	{
		case '1':

			add_item();
			cleardevice();
			itemf();
			break;

		case '2':
			delete_item();
			cleardevice();
			itemf();
			break;
		case '3':
			view_item();
			cleardevice();
			itemf();
			break;

		case '4':
			edit_item();
			cleardevice();
			itemf();
			break;

		case '5':
			cleardevice();
			start();
			menu();
			break;

		default :
			inv();
			itemf();
	 }


}


void end (void)
{
	cleardevice();

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	setcolor(WHITE);
	outtextxy(60,150,"ARE YOU SURE YOU WANT TO EXIT (Y/N)");

	switch(getch())
	{
		case 'Y':
		case 'y':
				end2();
				exit(0);
				break;
		case 'N':
		case 'n':
				break;
		default :
				inv();
				getch();
				end();
	}
}

void add_item(void)
{
	FILE *fpoin;
	char temp[30];

	int a=35;
	fpoin=fopen("c:\\item.txt","a");
	cleardevice();
	start();

	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	outtextxy(35,40,"ADD ITEM INFORMATION");

	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(60,100,"ENTER AN ITEM NAME");
	gotoxy(a,7);
	gets(temp);
	strcpy(item.name,strupr(temp));

	outtextxy(60,130,"ENTER ITEM TYPE");
	gotoxy(a,9);
	gets(temp);
	strcpy(item.type,strupr(temp));

	outtextxy(60,160,"QUANTITY");
	gotoxy(a,11);
	scanf("%d",&item.qty);

	fwrite(&item, sizeof(item),1, fpoin);


	if((c!=1)&&(d!=1))
	{
	cleardevice();
	start();
	outtextxy(90,290,"RECORD ADDED");
	outtextxy(90,310,"PRESS ANY KEY TO CONTINUE");
	getch();
	}

	fclose(fpoin);
	fflush(stdin);
}

void delete_item(void)
{
	char *searchname,temp1[30],temp[30];
	int count=0,count1=0,success=0,i,j,success2=0,k=0;

	FILE *fpoin,*fpoin1;
	cleardevice();
	start();

	cleardevice();
	start();
	gotoxy(10,5);
	printf("ENTER THE NAME OF THE ITEM:");
	gets(temp1);
	searchname=strupr(temp1);
	gotoxy(10,7);
	
	fpoin=fopen("c:\\item.txt","r");
	while((fread(&item,sizeof(item),1,fpoin))!=NULL)
	{

		count1++;
		if((strcmp(searchname,item.name)==0))
		{
			success2=1;
			cleardevice();
			start();

			gotoxy(9,10);
			printf("item NAME");
			gotoxy(26,10);
			puts(item.name);
			gotoxy(20,11);
                         printf("\n\tTYPE\t\t\t %s \
			 \n\tQUANTITY\t\t %d       \
			        \
				  ",item.type,item.qty);


			printf("\n\n\n\n\n");
			start();
			count++;
			gotoxy(20,20);
			printf("(D)ELETE OR MOVE (F)URTHER");
			switch(getch())
			{
				case 'D':
				case 'd':
					  k=1;
					  success=1;
					  break;
				case 'F':
				case 'f':
					  break;

					 default  :
					 success=2;
					 inv();
			}

			  if(success==1)
			  break;
		}


	}

       if((success2==1)&&(success==1))
	  {
		rewind(fpoin);
		fpoin1=fopen("c:\\temp.txt","w");

		for(i=1;i<count1;i++)
		{
			fread(&item,sizeof(item),1,fpoin);
			fwrite(&item, sizeof(item),1,fpoin1);
		}

				  for(j=0;j<=3;j++)
				{
					cleardevice();
					start();
					settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
					setcolor(WHITE);
					outtextxy(100,150,"RECORD DELETING");
					delay(700);
					setcolor(BLACK);
					outtextxy(100,150,"RECORD DELETING");
					delay(700);
					setcolor(WHITE);

				 }
				cleardevice();
				start();
				setcolor(RED);
				outtextxy(100,170,"RECORD DELETED");
				delay(1500);

			fread(&item,sizeof(item),1,fpoin);

			while((fread(&item,sizeof(item),1,fpoin))!=NULL)
			fwrite(&item, sizeof(item),1,fpoin1);

			start();



			fclose(fpoin1);
			fclose(fpoin);

			remove("c:\\item.txt");
			rename("c:\\temp.txt","c:\\item.txt");
			fpoin=fopen("c:\\item.txt","r");

	  }

		if(success2==0)
	  {
		gotoxy(28,20);
		printf("RECORD NOT FOUND");
		getch();
	  }

	 if((count!=0)&&(k==0))
		{
		  gotoxy(10,22);
		  printf("THERE ARE %d RECORD(S) LEFT",count);
		  getch();
		}

}
void view_item(void)
{
	cleardevice();
	setcolor(4);
	settextstyle(3,0,5);
	outtextxy(40,100,"PRESS");
	setcolor(11);
	settextstyle(3,0,3);
	outtextxy(70,200,"1 - TO SEARCH BY NAME");
	outtextxy(70,340,"2 - TO GO BACK");


	start();
	switch(getch())
	{
		case '1':
			 option1();
			 view_item();
			 break;
		
		case '2':
			 itemf();
			 break;
		default :
			 inv();
			 view_item();

	}
	fflush(stdin);
}



void option1(void)
{
	FILE *fpoin;

	char *searchname,temp[30];
	int count=0;
	cleardevice();
	start();
	gotoxy(10,5);
	printf("Enter the name of item to search:");
	gets(temp);
	searchname=strupr(temp);
	fpoin=fopen("c:\\item.txt","r");

	while((fread(&item,sizeof(item),1,fpoin))!=NULL)
	{


		if(strcmp(searchname,item.name)==0)
		{
			cleardevice();
			start();

			gotoxy(9,10);
			printf("item NAME");
			gotoxy(26,10);
			puts(item.name);
			gotoxy(20,11);
                        printf("\n\tTYPE\t\t\t %s \
			 \n\tQUANTITY\t\t %d       \
			        \
				  ",item.type,item.qty);

			printf("\n\n\n\n\n");
			start();
			count++;
			getch();

		}
	 }
	printf("\n\n\t\t\tTHERE ARE %d RECORD(S)",count);
	start();
	getch();
}


void edit_item()
{
	char *searchname,temp1[30],temp[30];
	int count=0,count1=0,success=0,i,j,k=0,success2=0;

	FILE *fpoin,*fpoin1;
	cleardevice();
	start();

	cleardevice();
	start();
	gotoxy(10,5);
	printf("ENTER THE NAME OF THE item:");
	gets(temp1);
	searchname=strupr(temp1);
	
	fpoin=fopen("c:\\item.txt","r");
	while((fread(&item,sizeof(item),1,fpoin))!=NULL)
	{

		count1++;
		if((strcmp(searchname,item.name)==0))
		{
			success2=1;
			cleardevice();
			start();

			gotoxy(9,10);
			printf("item NAME");
			gotoxy(26,10);
			puts(item.name);
			gotoxy(20,11);

			printf("\n\n\n\n\n");
			start();
			count++;
			gotoxy(20,20);
			printf(" (E)DIT OR (N)EXT RECORD");
			switch(getch())
			{
				case 'e':
				case 'E':
					  k=1;
					  success=1;
					  break;
				case 'N':
				case 'n':
					  break;
				default :
					 success=2;
					 inv();
			}

			  if(success==1)
			  break;
		}

	}



		 if((success2==1)&&(success==1))
	  {
		rewind(fpoin);
		fpoin1=fopen("c:\\temp.txt","w");

		for(i=1;i<count1;i++)
		{
			fread(&item,sizeof(item),1,fpoin);
			fwrite(&item, sizeof(item),1,fpoin1);
		}

			fread(&item,sizeof(item),1,fpoin);

			d=1;
			c=1;
			add_item();

			for(j=0;j<=5;j++)
			{
				cleardevice();
				start();
				settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
				setcolor(WHITE);
				outtextxy(100,150,"RECORD MODIFYING");
				delay(700);
				setcolor(BLACK);
				outtextxy(100,150,"RECORD MODIFYING");
				delay(700);
				setcolor(WHITE);

			}
				cleardevice();
				start();
				setcolor(RED);
				outtextxy(100,170,"RECORD MODIFIED");
				delay(1500);

			while((fread(&item,sizeof(item),1,fpoin))!=NULL)
			fwrite(&item, sizeof(item),1,fpoin1);

			start();



			fclose(fpoin1);
			fclose(fpoin);

			remove("c:\\item.txt");
			rename("c:\\temp.txt","d:\\item.txt");
			fpoin=fopen("d:\\item.txt","r");

	  }


		if(success2==0)
	  {
		gotoxy(28,20);
		printf("RECORD NOT FOUND");
		getch();
	  }

	 if((count!=0)&&(k==0))
	 {
		gotoxy(10,22);
		printf("THERE ARE %d RECORD(S) LEFT",count);
		getch();
	 }

}

void add_customer(void)
{
	FILE *fpoin1;
	char temp[30];

	int a=35;
	fpoin1=fopen("d:\\itembooking.txt","a");
	cleardevice();
	start();

	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	outtextxy(35,40,"ORDER BOOKING");

	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(60,100,"ENTER CUSTOMER NAME");
	gotoxy(a,7);
	gets(temp);
	strcpy(customer.name,strupr(temp));

	outtextxy(60,115,"ENTER ADDRESS");
	gotoxy(a,8);
	gets(temp);
	strcpy(customer.addr,strupr(temp));

	outtextxy(60,130,"ENTER PHONE NUMBER");
	gotoxy(a,9);
	gets(temp);
	strcpy(customer.pnum,strupr(temp));

	outtextxy(60,145 ,"DATE OF BIRTH");
	gotoxy(a,10);
	gets(temp);
	strcpy(customer.dob,strupr(temp));

	outtextxy(60,160,"ENTER PAYMENT MODE");
	gotoxy(a,11);
	gets(temp);
	strcpy(customer.pm,strupr(temp));

	

	outtextxy(60,175,"ENTER item");
	gotoxy(a,12);
	gets(temp);
	strcpy(customer.item,strupr(temp));

	

	  if((c!=1)&&(d!=1))
	  {
	cleardevice();
	start();
	outtextxy(90,290,"RECORD ADDED");
	outtextxy(90,310,"PRESS ANY KEY TO CONTINUE");
	getch();
	  }

	fwrite(&customer, sizeof(customer),1, fpoin1);
	fclose(fpoin1);
	fflush(stdin);
}


void delete_customer(void)
{
	char *searchname,temp[30];
	int count=0,count1=0,success=0,i,j,success2=0,k=0;

	FILE *fpoin1,*fpoin2;
	cleardevice();
	start();

	cleardevice();
	start();
	gotoxy(10,5);
	printf("ENTER THE NAME OF CUSTOMER:");
	gets(temp);
	searchname=strupr(temp);
	gotoxy(10,7);
	fpoin1=fopen("c:\\itembooking.txt","r");
	while((fread(&customer,sizeof(customer),1,fpoin1))!=NULL)
	{

		count1++;
		if((strcmp(searchname,customer.name)==0))
		{
			success2=1;
			cleardevice();
			start();

			gotoxy(9,10);
			printf("CUSTOMER NAME");
			gotoxy(34,10);
			puts(customer.name);
			gotoxy(20,11);
			printf("\n\tADDRESS\t\t\t %s \
			 \n\tPHONE NUMBER\t\t %s       \
			  \n\tDATE OF BIRTH\t\t %s       \
				\n\tPAYMENT MODE\t\t %s     \
				 \n\ITEM NAME\t\t %s        \
				  ",customer.addr,customer.pnum,customer.dob,customer.pm,customer.item);

			start();
			count++;

			gotoxy(10,23);
			printf("(D)ELETE OR MOVE (F)URTHER");
			switch(getch())
			{
				case 'D':
				case 'd':
					  k=1;
					  success=1;
					  break;
				case 'F':
				case 'f':
					  break;

					 default  :
					 success=2;
					 inv();
			}

			  if(success==1)
			  break;
		}


	}

       if((success2==1)&&(success==1))
	  {
		i=1;
		rewind(fpoin1);
		fpoin2=fopen("c:\\temp.txt","w");

		for(i=1;i<count1;i++)
		{
			fread(&customer,sizeof(customer),1,fpoin1);
			fwrite(&customer,sizeof(customer),1,fpoin2);
		}



			fread(&customer,sizeof(customer),1,fpoin1);

			while((fread(&customer,sizeof(customer),1,fpoin1))!=NULL)
			fwrite(&customer, sizeof(customer),1,fpoin2);



			    for(j=0;j<=3;j++)
				{
					cleardevice();
					start();
					settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
					setcolor(WHITE);
					outtextxy(100,150,"RECORD DELETING");
					delay(700);
					setcolor(BLACK);
					outtextxy(100,150,"RECORD DELETING");
					delay(700);
					setcolor(WHITE);

				 }


			start();
				cleardevice();
				start();
				setcolor(RED);
				outtextxy(100,170,"RECORD DELETED");
				delay(1500);



			fclose(fpoin2);
			fclose(fpoin1);

			remove("c:\\itembooking.txt");
			rename("c:\\temp.txt","c:\\itembooking.txt");
			fpoin1=fopen("d:\\itembooking.txt","r");

	  }

		if(success2==0)
	  {
		gotoxy(28,20);
		printf("RECORD NOT FOUND");
		getch();
	  }

		if((count!=0)&&(k==0))
		{
		  gotoxy(10,24);
		  printf("THERE ARE %d RECORD(S) LEFT",count);
		  getch();
		}

}
void view_customer(void)
{
	FILE *fpoin1;

	char *searchname,temp[30];
	int count=0;
	cleardevice();
	start();
	gotoxy(10,5);
	printf("Enter the name of customer to search:");
	gets(temp);
	searchname=strupr(temp);
	fpoin1=fopen("c:\\itembooking.txt","r");

	while((fread(&customer,sizeof(customer),1,fpoin1))!=NULL)
	{


		if(strcmp(searchname,customer.name)==0)
		{
			cleardevice();
			start();

			gotoxy(9,10);
			printf("CUSTOMER NAME");
			gotoxy(34,10);
			puts(customer.name);
			gotoxy(20,11);
			printf("\n\tADDRESS\t\t\t %s \
			 \n\tPHONE NUMBER\t\t %s       \
			  \n\tDATE OF BIRTH\t\t %s       \
				\n\tPAYMENT MODE\t\t %s     \
				 \n\ITEM NAME\t\t %s        \
				  ",customer.addr,customer.pnum,customer.dob,customer.pm,customer.item);

			printf("\n\n\n\n");
			start();
			count++;
			getch();

		}
	 }
	printf("\n\t\t\tTHERE ARE %d RECORD(S)",count);
	start();
	getch();

}
void end2(void)
{
	int driver=DETECT,mode;   	//detect best driver and mode
	int i,j=520;

	initgraph(&driver,&mode,"c:\\tc\\bgi"); 	//initialize graphics mode

	for(i=480;i>=0;i--)
	{

		setcolor(WHITE);
		outtextxy(230,i,"DESIGNED BY");
		outtextxy(195,j,"ANURAG GOEL");
   /*		outtextxy(219,j+15,"ANURAG GOEL");
		outtextxy(192,j+30,"ANURAG GOEL");
		outtextxy(216,j+45,"ANURAG GOEL");
		outtextxy(225,j+60,"ANURAG GOEL");
		outtextxy(230,j+75,"ANURAG GOEL"); */
		outtextxy(243,j+120,"ANURAG GOEL");
		outtextxy(243,j+140,"ANURAG GOEL");
		outtextxy(243,j+160,"ANURAG GOEL");

		delay(20);
		j--;

		 cleardevice();
	}
	closegraph();
}


void inv(void)
{
			sound(700);
			outtextxy(300,430,"INVALID INPUT");
			delay(500);
                        nosound();'
			setcolor(0);
			outtextxy(300,430,"INVALID INPUT");
                        
}
void help( )
{        
	
        
	 int i;
	textcolor(RED+BLINK);
	gotoxy(18,2);
	cprintf("  P R O J E C T  HOME SHOP 18 ") ;
	textcolor(YELLOW+BLINK);
	gotoxy(18,4); 
	cprintf(" By- ANURAG GOEL ");
	delay(10) ;
	gotoxy(10,6);  printf("In  this  Project  you  can keep  records  of  daily  booking ORDER") ;
	delay(10) ;
	gotoxy(10,7);  printf(" It can book productS THAT have  to purchase             ") ;
	delay(10) ;
	gotoxy(10,9);  printf(" This  program is capable of holding reord of booking " );
	delay(10) ;
	gotoxy(10,11); printf("- In the third option you can modify or cancel orderr" );
	delay(10) ;
	gotoxy(10,12); printf(" In fourth option you can display dilvey status;") ;
	delay(10) ;
	gotoxy(10,14); printf("- you can check you delivey is done by whom & upto when." );
	delay(10) ;
	gotoxy(10,16); printf("- Through fifth  option you can see receipt" );
	delay(10) ;
	gotoxy(10,18); printf("- In sixth you can take help from help menu" );
	delay(10) ;
	gotoxy(10,20); printf("- And the last option is to Quit the PROJECT (Exit to Dos).  ") ;
	delay(10) ;
	textcolor(1+BLINK) ; textbackground(LIGHTGREEN) ;
	gotoxy(26,30) ; cprintf(" Press any key to continue ") ;
	textcolor(YELLOW) ; textbackground(BLACK) ;
	gotoxy(25,2) ;
	getch() ;
	for ( i=25;i>=1;i--)
	{
		delay(50) ;
		gotoxy(1,i);
	}

}
int Password ()
 
{         


	 char Password[12]=""; 
	 char pass[20];
	 char UserName[15];
	 char user[15]="";
	 int sucess=0;                    
	 int x=26,i;
	 cleardevice();
	 setcolor(3);

	 line ( 130, 180, 500, 180 );             
	 rectangle ( 130, 150, 500, 300 );
	 setfillstyle ( SOLID_FILL, 7 );      
	 bar ( 130, 150, 500, 180 );
	 setfillstyle ( SOLID_FILL, 8 );     
	 bar ( 130, 180, 500, 300 );
	 setcolor ( 2 );                   
	 outtextxy ( 140, 165, " P A S S W O R D   V E R I F I C A T I O N  " );
	 setfillstyle ( SOLID_FILL, 0 );
	 bar ( 200, 200, 450, 230 );
	 bar ( 200, 247, 450, 277 );

	 outtextxy ( 130, 210, "   NAME " );
	 outtextxy ( 126, 258, " PASSWORD " );

	 gotoxy(26,14);
	 gets(UserName);

	for(i=0;i<20;i++ )       
  {
	  pass[i]=getch();              
	  if(pass[i]=='\r')
		{
	pass[i]='\0';                
	break;
		 }

	  else
		{
	 gotoxy(x,17);printf("*");    
	 x++;
		 }
	}

	if ((strcmp(Password,pass)==0)&&(strcmp(UserName,user)==0))    
		sucess=1;

	else                    
	 {
		 sucess=0;
		 gotoxy (22, 21);
		 printf ( " INVALID PASSWORD! TRY AGAIN " );
		 getche ();
	  }

	return ( sucess );
}
void day()
{
 struct date d;
 int i,j;

 getdate(&d);
 i=d.da_day;
 j=d.da_mon;
 gotoxy(12,2);
printf("\nDATE :%d",i);
 printf(":%d",j);
 printf(":%d",d.da_year);
 }
void somoy(){
   int i,j,k;
   struct  time t;

   gettime(&t);
   i=t.ti_hour;
   j=t.ti_min;
   k=t.ti_sec;
    gotoxy(84,2);
   printf("\t\t\t\t\t\t   TIME:%d:%d:%d",i,j,k);
   }
har wel[50]="welcome";
  char cdge[50]="JIIT";
  char proj[50]="PROJECT";
  char h18[50]="HOME-SHOP18";
  char madb[50]="MADE BY-";
  char mdby[50]="ANURAG GOEL";
void firstscreen()
{
cleardevice();
         clrscr();
	
	setcolor(4);
	 setbkcolor(2);
	setcolor(4);
	gotoxy(30,16);
       settextstyle(4,0,8);
       setcolor(5);
       outtextxy(180,190,wel);
       settextstyle(0,0,3);
       outtextxy(220,60,proj);
       outtextxy(180,90,h18);
       outtextxy(180,350,madb);
       outtextxy(180,380,mdby);
       settextstyle(0,1,5);
      outtextxy(50,150,cdge);
      outtextxy(620,150,cdge);
       rectangle(0,0,638,478);
       circle(50, 50, 100);
       gotoxy(160,80);
	setfillstyle(5,5);
       floodfill(10,50,5);
	  circle(600, 50, 100);
	  setfillstyle(5,5) ;
	  floodfill(600,50,5);
	  ellipse(300,250,0,360,150,80);
	  setfillstyle(1,6);
	  floodfill(300,250,5);
	  circle(50,450,100);
	  setfillstyle(5,5);
	  floodfill(50,450,5);
	  circle(600,450,100);
	 setfillstyle(5,5);
	  floodfill(600,450,5);
           setbkcolor(0);
getch();
}


