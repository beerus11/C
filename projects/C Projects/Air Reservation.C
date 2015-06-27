#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>

struct record {                
	char name[30];
	char type[15];        
	char dday[10];
	char dtime[10];
	char aday[10];
	char atime[10];
	char des[30];
	int capa;
} flight;

struct record1 {              
	    char name[20];
	    char addr[40];
	    char pnum[15];
	    char dob[15];
	    char nic[15];
	    char pass[15];
	    char nation[20];      
	    char dest[30];
	    char flight[20];
	    char dod[10];
	    char time[10];
} customer;

void firstscreen(void);
void printTitle(void);
void showMenu(void);               
void customerf(void);
void flightf(void);
void start(void);
void menu(void);                  
void add_flight(void);
void edit_flight();
void delete_flight(void);
void add_customer(void);         
void edit_customer(void);
void delete_customer(void);
void end(void);
void view_flight(void);
void view_customer(void);
void option(void);
void option1(void);
void end2(void);
void option2(void);
int Password(void);
void invalidinput1(void);
int c=0,d=0;

void main(void)
{
	int abcd;

	int driver=VGA,mode=VGAHI;   	


	initgraph(&driver,&mode,"c:\\tc\\bgi"); 	

	randomize();
        setbkcolor(3);

	firstscreen();
	cleardevice();
	start();                         
	menu();
	getch();                        
	closegraph();
}
void start(void)
{                                          
	setcolor(RED);
	setlinestyle(SOLID_LINE,1,3);
	rectangle(0,0,639,479);            
	
}

void showMenu(void)
{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
		setcolor(WHITE);					
		outtextxy(60,150,"1) FLIGHT INFORMATION");	
		outtextxy(60,210,"2) RECORD");
                outtextxy(60,270,"3) TICKET BOOKING");		
		outtextxy(60,330,"4) EXIT");			
}

void menu(void)
{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
		setcolor(WHITE);					
		outtextxy(60,150,"1) FLIGHT INFORMATION");	
		outtextxy(60,210,"2) RECORD");
		outtextxy(60,270,"3) TICKET BOOKING");
		outtextxy(60,330,"4) EXIT");			


	while (1)
   {
	
		printTitle();
	

	switch(getch())                					
	{
		case '1':

			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,150,"1) FLIGHT INFORMATION");	
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,150,"1) FLIGHT INFORMATION");	
			delay(500);

			flightf();
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

			customerf();
			cleardevice();
			start();
			showMenu();
			break;
		
                case '3':
                        settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,270,"3) TICKET BOOKING");			
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,270,"3) TICKET BOOKING");			
			delay(500);
			add_customer();
               case '4':
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,330,"4) EXIT");			
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,330,"4) EXIT");			
			delay(500);

			end();
			cleardevice();
			start();
			showMenu();
			break;
		default:
			invalidinput1();
	}
    }
 }
void printTitle(void)
{
		
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);		
		setcolor(6);
		outtextxy(16,40,"WELCOME TO THE AIRTICKET RESERVATION");	

								

}

void flightf(void)
{
	d=0,c=0;
	cleardevice();
	start();

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
	setcolor(LIGHTGREEN);
	outtextxy(25,40," FLIGHT INFORMATION");
	setcolor(RED);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);

	outtextxy(60,150,"1)ADD FLIGHT INFORMATION");
	outtextxy(60,210,"2)DELETE FLIGHT INFORMATION");
	outtextxy(60,270,"3)VIEW FLIGHT INFORMATION");
	outtextxy(60,330,"4)EDIT FLIGHT INFORMATION");
	outtextxy(60,390,"5)GO BACK TO THE MAIN MENU");
	switch(getch())
	{
		case '1':

			add_flight();
			cleardevice();
			flightf();
			break;

		case '2':
			delete_flight();
			cleardevice();
			flightf();
			break;
		case '3':
			view_flight();
			cleardevice();
			flightf();
			break;

		case '4':
			edit_flight();
			cleardevice();
			flightf();
			break;

		case '5':
			cleardevice();
			start();
			menu();
			break;

		default :
			invalidinput1();
			flightf();
	 }


}
void customerf(void)
{
	d=0,c=0;
	cleardevice();
	start();
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
	setcolor(LIGHTGREEN);
	outtextxy(13,40,"CUSTOMER INFORMATION");
	setcolor(RED);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);

	
	outtextxy(60,210,"1)DELETE CUSTOMER INFORMATION");
	outtextxy(60,270,"2)VIEW CUSTOMER INFORMATION");
	outtextxy(60,330,"3)EDIT CUSTOMER INFORMATION");
	outtextxy(60,390,"4)GO BACK TO THE MAIN MENU");

	switch(getch())
	{
		
		case '1':
			delete_customer();
			cleardevice();
			customerf();
			break;
		case '2':
			view_customer();
			cleardevice();
			customerf();
			break;
		case '3':
			edit_customer();
			cleardevice();
			customerf();
			break;
		case '4':
			cleardevice();
			start();
			menu();
			break;
		default :
			invalidinput1();
			customerf();
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
				invalidinput1();
				getch();
				end();
	}
}

void add_flight(void)
{
	FILE *fpoin;
	char temp[30];

	int a=35;
	fpoin=fopen("c:\\flight.txt","a");
	cleardevice();
	start();

	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	outtextxy(35,40,"ADD flight INFORMATION");

	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(60,100,"ENTER AN FLIGHT NAME");
	gotoxy(a,7);
	gets(temp);
	strcpy(flight.name,strupr(temp));

	outtextxy(60,115,"ENTER A DESTINATION");
	gotoxy(a,8);
	gets(temp);
	strcpy(flight.des,strupr(temp));

	outtextxy(60,130,"ENTER AN AIRCRAFT TYPE");
	gotoxy(a,9);
	gets(temp);
	strcpy(flight.type,strupr(temp));

	outtextxy(60,145 ,"DAY OF DEPARTURE");
	gotoxy(a,10);
	gets(temp);
	strcpy(flight.dday,strupr(temp));

	outtextxy(60,160,"DEPARTURE TIME");
	gotoxy(a,11);
	gets(temp);
	strcpy(flight.dtime,strupr(temp));

	outtextxy(60,175,"ARRIVAL DAY");
	gotoxy(a,12);
	gets(temp);
	strcpy(flight.aday,strupr(temp));


	outtextxy(60,190,"ARRIVAL TIME");
	gotoxy(a,13);
	gets(temp);
	strcpy(flight.atime,strupr(temp));


	outtextxy(60,205,"CAPACITY");
	gotoxy(a,14);
	scanf("%d",&flight.capa);

	fwrite(&flight, sizeof(flight),1, fpoin);


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

void delete_flight(void)
{
	char *searchname,*desname,temp1[30],temp[30];
	int count=0,count1=0,success=0,i,j,success2=0,k=0;

	FILE *fpoin,*fpoin1;
	cleardevice();
	start();

	cleardevice();
	start();
	gotoxy(10,5);
	printf("ENTER THE NAME OF THE FLIGHT:");
	gets(temp1);
	searchname=strupr(temp1);
	gotoxy(10,7);
	printf("ENTER THE NAME OF DESTINATION:");
	gets(temp);
	desname=strupr(temp);
	fpoin=fopen("c:\\flight.txt","r");
	while((fread(&flight,sizeof(flight),1,fpoin))!=NULL)
	{

		count1++;
		if((strcmp(searchname,flight.name)==0)&&(strcmp(desname,flight.des)==0))
		{
			success2=1;
			cleardevice();
			start();

			gotoxy(9,10);
			printf("FLIGHT NAME");
			gotoxy(26,10);
			puts(flight.name);
			gotoxy(20,11);
			printf("\n\tDESTINATION\t %s \
			 \n\tAIRCRAFT TYPE\t %s       \
			  \n\tDEPARTURE DAY\t %s       \
				\n\tDEPARTURE TIME\t %s     \
				\n\tARRIVAL DAY\t %s        \
				 \n\tARRIVAL TIME\t %s       \
				  \n\tCAPACITY\t %d",flight.des,flight.type,flight.dday,flight.dtime,flight.aday,flight.atime,flight.capa);

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
					 invalidinput1();
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
			fread(&flight,sizeof(flight),1,fpoin);
			fwrite(&flight, sizeof(flight),1,fpoin1);
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

			fread(&flight,sizeof(flight),1,fpoin);

			while((fread(&flight,sizeof(flight),1,fpoin))!=NULL)
			fwrite(&flight, sizeof(flight),1,fpoin1);

			start();



			fclose(fpoin1);
			fclose(fpoin);

			remove("c:\\flight.txt");
			rename("c:\\temp.txt","c:\\flight.txt");
			fpoin=fopen("c:\\flight.txt","r");

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
void view_flight(void)
{
	cleardevice();
	setcolor(4);
	settextstyle(3,0,5);
	outtextxy(40,100,"PRESS");
	setcolor(11);
	settextstyle(3,0,3);
	outtextxy(70,200,"1 - TO SEARCH BY NAME");
	outtextxy(70,240,"2 - TO SEARCH BY DESTINATION");
	outtextxy(70,280,"3 - TO SEARCH BY BOTH");
	outtextxy(70,320,"4 - TO GO BACK");


	start();
	switch(getch())
	{
		case '1':
			 option1();
			 view_flight();
			 break;
		case '2':
			 option();
			 view_flight();
			 break;
		case '3':
			 option2();
			 view_flight();
			 break;
		case '4':
			 flightf();
			 break;
		default :
			 invalidinput1();
			 view_flight();

	}
	fflush(stdin);
}

void option(void)
{
	FILE *fpoin;

	char *searchname,temp[30];
	int count=0;
	cleardevice();
	start();
	gotoxy(10,5);
	printf("Enter the name of destination to search:");
	gets(temp);
	searchname=strupr(temp);
	fpoin=fopen("c:\\flight.txt","r");

	while((fread(&flight,sizeof(flight),1,fpoin))!=NULL)
	{


		if(strcmp(searchname,flight.des)==0)
		{
			cleardevice();
			start();

			gotoxy(9,10);
			printf("flight NAME");
			gotoxy(26,10);
			puts(flight.name);
			gotoxy(20,11);
			printf("\n\tDESTINATION\t %s \
			 \n\tAIRCRAFT TYPE\t %s       \
			  \n\tDEPARTURE DAY\t %s       \
				\n\tDEPARTURE TIME\t %s     \
				\n\tARRIVAL DAY\t %s        \
				  \n\tARRIVAL TIME\t %s       \
					\n\tCAPACITY\t %d",flight.des,flight.type,flight.dday,flight.dtime,flight.aday,flight.atime,flight.capa);

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

void option1(void)
{
	FILE *fpoin;

	char *searchname,temp[30];
	int count=0;
	cleardevice();
	start();
	gotoxy(10,5);
	printf("Enter the name of flight to search:");
	gets(temp);
	searchname=strupr(temp);
	fpoin=fopen("c:\\flight.txt","r");

	while((fread(&flight,sizeof(flight),1,fpoin))!=NULL)
	{


		if(strcmp(searchname,flight.name)==0)
		{
			cleardevice();
			start();

			gotoxy(9,10);
			printf("flight NAME");
			gotoxy(26,10);
			puts(flight.name);
			gotoxy(20,11);
			printf("\n\tDESTINATION\t %s \
			 \n\tAIRCRAFT TYPE\t %s       \
			  \n\tDEPARTURE DAY\t %s       \
				\n\tDEPARTURE TIME\t %s     \
				 \n\tARRIVAL DAY\t %s        \
				  \n\tARRIVAL TIME\t %s       \
					\n\tCAPACITY\t %d",flight.des,flight.type,flight.dday,flight.dtime,flight.aday,flight.atime,flight.capa);

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
void option2(void)
{
	FILE *fpoin;

	char *searchname,*desname,temp[30],temp1[30];
	int count=0;
	cleardevice();
	start();
	gotoxy(10,5);
	printf("ENTER flight:");
	gets(temp1);
	searchname=strupr(temp1);
	gotoxy(10,10);
	printf("ENTER DESTINATION:");
	gets(temp);
	desname=strupr(temp);
	fpoin=fopen("c:\\flight.txt","r");

	while((fread(&flight,sizeof(flight),1,fpoin))!=NULL)
	{


	  if((strcmp(searchname,flight.name)==0)&&(strcmp(desname,flight.des)==0))

		{

			cleardevice();
			start();

			gotoxy(9,10);
			printf("flight NAME");
			gotoxy(26,10);
			puts(flight.name);
			gotoxy(20,11);
			printf("\n\tDESTINATION\t %s \
			 \n\tAIRCRAFT TYPE\t %s       \
			  \n\tDEPARTURE DAY\t %s       \
				\n\tDEPARTURE TIME\t %s     \
				 \n\tARRIVAL DAY\t %s        \
				  \n\tARRIVAL TIME\t %s       \
					\n\tCAPACITY\t %d",flight.des,flight.type,flight.dday,flight.dtime,flight.aday,flight.atime,flight.capa);

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

void edit_flight()
{
	char *searchname,*desname,temp1[30],temp[30];
	int count=0,count1=0,success=0,i,j,k=0,success2=0;

	FILE *fpoin,*fpoin1;
	cleardevice();
	start();

	cleardevice();
	start();
	gotoxy(10,5);
	printf("ENTER THE NAME OF THE flight:");
	gets(temp1);
	searchname=strupr(temp1);
	gotoxy(10,7);
	printf("ENTER THE NAME OF DESTINATION:");
	gets(temp);
	desname=strupr(temp);
	fpoin=fopen("c:\\flight.txt","r");
	while((fread(&flight,sizeof(flight),1,fpoin))!=NULL)
	{

		count1++;
		if((strcmp(searchname,flight.name)==0)&&(strcmp(desname,flight.des)==0))
		{
			success2=1;
			cleardevice();
			start();

			gotoxy(9,10);
			printf("flight NAME");
			gotoxy(26,10);
			puts(flight.name);
			gotoxy(20,11);
			printf("\n\tDESTINATION\t %s \
			 \n\tAIRCRAFT TYPE\t %s       \
			  \n\tDEPARTURE DAY\t %s       \
				\n\tDEPARTURE TIME\t %s     \
				\n\tARRIVAL DAY\t %s        \
				 \n\tARRIVAL TIME\t %s       \
				  \n\tCAPACITY\t %d",flight.des,flight.type,flight.dday,flight.dtime,flight.aday,flight.atime,flight.capa);

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
					 invalidinput1();
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
			fread(&flight,sizeof(flight),1,fpoin);
			fwrite(&flight, sizeof(flight),1,fpoin1);
		}

			fread(&flight,sizeof(flight),1,fpoin);

			d=1;
			c=1;
			add_flight();

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

			while((fread(&flight,sizeof(flight),1,fpoin))!=NULL)
			fwrite(&flight, sizeof(flight),1,fpoin1);

			start();



			fclose(fpoin1);
			fclose(fpoin);

			remove("c:\\flight.txt");
			rename("c:\\temp.txt","d:\\flight.txt");
			fpoin=fopen("d:\\flight.txt","r");

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
	fpoin1=fopen("d:\\customer.txt","a");
	cleardevice();
	start();

	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	outtextxy(35,40,"TICKET BOOKING");

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

	outtextxy(60,160,"EMAIL - ADDRESS");
	gotoxy(a,11);
	gets(temp);
	strcpy(customer.nic,strupr(temp));

	outtextxy(60,175,"PASSPORT NUMBER");
	gotoxy(a,12);
	gets(temp);
	strcpy(customer.pass,strupr(temp));


	outtextxy(60,190,"NATIONALITY");
	gotoxy(a,13);
	gets(temp);
	strcpy(customer.nation,strupr(temp));


	outtextxy(60,205,"DESTINATION");
	gotoxy(a,14);
	gets(temp);
	strcpy(customer.dest,strupr(temp));

	outtextxy(60,220,"ENTER flight");
	gotoxy(a,15);
	gets(temp);
	strcpy(customer.flight,strupr(temp));

	outtextxy(60,235,"DATE OF DEPARTURE");
	gotoxy(a,16);
	gets(temp);
	strcpy(customer.dod,strupr(temp));

	outtextxy(60,250,"TIME OF DEPARTURE");
	gotoxy(a,17);
	gets(temp);
	strcpy(customer.time,strupr(temp));

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

void edit_customer(void)
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
	fpoin1=fopen("c:\\customer.txt","r");
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
				\n\tNIC NUMBER\t\t %s     \
				 \n\tPASSPORT NUMBER\t\t %s        \
				  \n\tNATIONALITY\t\t %s       \
					\n\tDESTINATION\t\t %s      \
				\n\tflight\t\t\t %s \
				\n\tDAY OF DEPARTURE\t %s  \
				\n\tTIME OF DEPARTURE\t %s",customer.addr,customer.pnum,customer.dob,customer.nic,customer.pass,customer.nation,customer.dest,customer.flight,customer.dod,customer.time);

			start();
			count++;

			gotoxy(20,23);
			printf("(E)DIT OR MOVE (F)URTHER");
			switch(getch())
			{
				case 'E':
				case 'e':
					  k=1;
					  success=1;
					  break;
				case 'F':
				case 'f':
					  break;

					 default  :
					 success=2;
					 invalidinput1();
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

			c=1;
			d=1;
			add_customer();

			while((fread(&customer,sizeof(customer),1,fpoin1))!=NULL)
			fwrite(&customer, sizeof(customer),1,fpoin2);



				 for(j=0;j<=3;j++)
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


			start();
				cleardevice();
				start();
				setcolor(RED);
				outtextxy(100,170,"RECORD MODIFIED");
				delay(1500);



			fclose(fpoin2);
			fclose(fpoin1);

			remove("d:\\customer.txt");
			rename("d:\\temp.txt","d:\\customer.txt");
			fpoin1=fopen("d:\\customer.txt","r");

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
	fpoin1=fopen("c:\\customer.txt","r");
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
				\n\tNIC NUMBER\t\t %s     \
				 \n\tPASSPORT NUMBER\t\t %s        \
			     \n\tNATIONALITY\t\t %s       \
			      \n\tDESTINATION\t\t %s      \
				\n\tflight\t\t\t %s \
				\n\tDAY OF DEPARTURE\t %s  \
				\n\tTIME OF DEPARTURE\t %s",customer.addr,customer.pnum,customer.dob,customer.nic,customer.pass,customer.nation,customer.dest,customer.flight,customer.dod,customer.time);

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
					 invalidinput1();
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

			remove("c:\\customer.txt");
			rename("c:\\temp.txt","c:\\customer.txt");
			fpoin1=fopen("d:\\customer.txt","r");

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
	fpoin1=fopen("c:\\customer.txt","r");

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
				\n\tNIC NUMBER\t\t %s     \
				 \n\tPASSPORT NUMBER\t\t %s        \
				  \n\tNATIONALITY\t\t %s       \
					\n\tDESTINATION\t\t %s      \
				\n\tflight\t\t\t %s \
				\n\tDAY OF DEPARTURE\t %s  \
				\n\tTIME OF DEPARTURE\t %s",customer.addr,customer.pnum,customer.dob,customer.nic,customer.pass,customer.nation,customer.dest,customer.flight,customer.dod,customer.time);

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
	int driver=DETECT,mode;   	
	int i,j=520;

	initgraph(&driver,&mode,"c:\\tc\\bgi"); 	
	for(i=480;i>=0;i--)
	{

		setcolor(WHITE);
		outtextxy(230,i,"DESIGNED BY");
		outtextxy(195,j,"ANURAG GOEL");
		

		delay(20);
		j--;

		 cleardevice();
	}
	closegraph();
}


void invalidinput1(void)
{
			sound(700);
			outtextxy(300,430,"invalid INPUT");
			delay(500);
			nosound();
			setcolor(0);
			outtextxy(300,430,"invalid INPUT");
                        
}
void firstscreen()
{
   void start() ;
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);		
		setcolor(4);						
		outtextxy(16,40,"PROJECT ON  AIR TICKET BOOKING");
		setcolor(10);
                outtextxy(30,200," MADE BY=");
		setcolor(14);
		outtextxy(180,200,"  ANURAG GOEL ");
                
		setcolor(5);
		settextstyle(1,1,25);
while(!(kbhit()))
	{

		
		setcolor(4);
		settextstyle(1,0,25);
		outtextxy(180,350,"  JIIT");

}
                
                  getch();

}

