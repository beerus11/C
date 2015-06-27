#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
void start(void);
void inv(void);
void showMenu(void);
void menu(void);
void title(void);
void addaccount(void);
void titleaddaccount(void);
void accstatus(void);
void deletecustomer(void);
void entry(void);
void question(void);
void firstscreen(void);
struct record {                          
	char name[30];
	char address[25];    
	char city[10];
	char panno[10];
        char dob[10];
	int bal;
        char accno[25];
	int mnno;
} customer;
int c=0,d=0,amt;
int temp,temp2;





void main(void)
{
	int Proceed;
        int temp, temp2;

	int driver=VGA,mode=VGAHI;   	//detect best driver and mode


	initgraph(&driver,&mode,"c:\\tc\\bgi"); 	//initialize graphics mode

	randomize();
        setbkcolor(2);
	firstscreen();
	cleardevice();
	start();                         //	AND THEM CHECK
	menu();
	getch();                         //	THE VALUE RETURNED...
	closegraph();
}

void title(void)
{
		

		temp=(rand()% 15)+1;
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);		
		setcolor(temp);						
		outtextxy(16,40,"WELCOME TO  PUNJAB NATIONAL BANK");	

		temp2=(rand()%15)+1;
		setcolor(temp2);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
                outtextxy(16,80,"MADE BY ANURAG GOEL");						
		line(20,80,621,80);       				

		delay(400);						

}
void start(void)
{                                         
	setcolor(RED);
	setlinestyle(SOLID_LINE,1,3);
	rectangle(0,0,639,479);            
        setcolor(GREEN);
	setlinestyle(SOLID_LINE,1,4);
	rectangle(5,5,634,474);            

	setcolor(BLUE);
	setlinestyle(SOLID_LINE,1,2);     
	rectangle(10,10,629,469);
}
void showMenu(void)
{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
		setcolor(WHITE);
		outtextxy(60,150,"1) OPEN ACCOUNT");	
		outtextxy(60,210,"2) ENTRY(DEBIT OR CREDIT)");		
		outtextxy(60,270,"3) ACCOUNT STATUS");
                outtextxy(60,330,"4) CLOSE ACCOUNT");
                outtextxy(60,390,"5) EXIT");			 
}

void menu(void)
{
		 
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
		setcolor(WHITE);
		outtextxy(60,150,"1) OPEN ACCOUNT");	
		outtextxy(60,210,"2) ENTRY(DEBIT OR CREDIT)");		
		outtextxy(60,270,"3) ACCOUNT STATUS");
                outtextxy(60,330,"4) CLOSE ACCOUNT");
                outtextxy(60,390,"5) EXIT");	
	while (1)          						
   {
	while(!(kbhit()))
	{
		title();
	}

	switch(getch())                					
	{
		case '1':


			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
			setcolor(0);					
			outtextxy(60,150,"1) OPEN ACCOUNT");	
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,150,"1) OPEN ACCOUNT");	
			delay(500);
			
			addaccount();
			cleardevice();
			start();
			showMenu();
			break;
		case '2':
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,210,"2) ENTRY(DEBIT OR CREDIT)");	
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,210,"2) ENTRY(DEBIT OR CREDIT)");	
			delay(500);
			 entry();

			cleardevice();
			start();
			showMenu();
			break;
                	
		case '3':
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,270,"3) ACCOUNT STATUS");	
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,270,"3) ACCOUNT STATUS");	
			delay(500);

			accstatus();
			cleardevice();
			start();
			showMenu();
			break;

		case '4':
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,330,"4) CLOSE ACCOUNT");	
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,330,"4) CLOSE ACCOUNT");	
			delay(500);

			deletecustomer();
			cleardevice();
			start();
			showMenu();
			break;
               
               
               
		case '5':
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,390,"5) EXIT");			
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,390,"5) EXIT");			
			delay(500);

			cleardevice();
			exit(0);
		default:exit(0);
			
	}
    }

		
}

void addaccount(void)
{
FILE *fpoin;
	char temp[30];

	int a=35;
	fpoin=fopen("c:\\bankingrecord.txt","a");
	cleardevice();
	start();
        
        setcolor(YELLOW);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
	outtextxy(35,40,"ADD ACCOUNT");

	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
       outtextxy(60,85,"ENTER ACCOUNT  NO");
	gotoxy(a,6);
	gets(temp);
	strcpy(customer.accno,strupr(temp));

        
        
	outtextxy(60,100,"ENTER CUSTOMER NAME");
	gotoxy(a,7);
	gets(temp);
	strcpy(customer.name,strupr(temp));

	outtextxy(60,115,"ENTER ADDRESS");
	gotoxy(a,8);
	gets(temp);
	strcpy(customer.address,strupr(temp));

	outtextxy(60,130,"ENTER CITY");
	gotoxy(a,9);
	gets(temp);
	strcpy(customer.city,strupr(temp));

	outtextxy(60,145 ,"ENTER PAN NO");
	gotoxy(a,10);
	gets(temp);
	strcpy(customer.panno,strupr(temp));

	outtextxy(60,160,"ENTER DATE OF BIRTH");
	gotoxy(a,11);
	gets(temp);
	strcpy(customer.dob,strupr(temp));

	outtextxy(60,175,"OPENING DEPOSIT");
	gotoxy(a,12);
	scanf("%d",&customer.bal);

	outtextxy(60,205,"ENTER MOBILE NO");
	gotoxy(a,14);
	scanf("%d",&customer.mnno);

        
        
        
        
	fwrite(&customer, sizeof(customer),1, fpoin);


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
void accstatus(void)
{
	FILE *fpoin;

	char *searchname,temp[30];
	int count=0;
	cleardevice();
	start();
	gotoxy(10,5);
	printf("Enter the ACCOUNT NO to search:");
        gets(temp);
	searchname=strupr(temp);
	fpoin=fopen("c:\\bankingrecord.txt","r");

	while((fread(&customer,sizeof(customer),1,fpoin))!=NULL)
	{


		if(strcmp(searchname,customer.accno)==0)
		{
			cleardevice();
			start();

			gotoxy(9,10);
			printf("CUSTOMER NAME");
			gotoxy(26,10);
			puts(customer.name);
                        gotoxy(9,12);
                        printf("CUSTOMER ADDRESS");
			gotoxy(26,12);
			puts(customer.address);
			gotoxy(9,14);
                        printf("CUSTOMER CITY");
			gotoxy(26,14);
			puts(customer.city);
                        gotoxy(9,16);
                        printf("CUSTOMER PAN NO");
			gotoxy(26,16);
			puts(customer.panno);
                        gotoxy(9,18);
                        printf("CUSTOMER DOB");
			gotoxy(26,18);
			puts(customer.dob);
                        gotoxy(9,20);
                        printf("CUSTOMER BALANCE");
			gotoxy(26,20);
			printf("%d",customer.bal);
                        gotoxy(9,22);
			
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
void deletecustomer()
{
	char *searchname,temp[30];
	int count=0,count1=0,success=0,i,j,success2=0,k=0;

	FILE *fpoin1,*fpoin2;
	cleardevice();
	start();

	cleardevice();
	start();
	gotoxy(10,5);
	printf("ENTER THE ACC NO");
	gets(temp);
	searchname=strupr(temp);
	gotoxy(10,7);
	fpoin1=fopen("c:\\bankingrecord.txt","r");
	while((fread(&customer,sizeof(customer),1,fpoin1))!=NULL)
	{

		count1++;
		if((strcmp(searchname,customer.accno)==0))
		{
			success2=1;
			cleardevice();
			start();

			gotoxy(9,10);
			printf("CUSTOMER NAME");
			gotoxy(34,10);
			puts(customer.name);
			gotoxy(20,11);

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
		fpoin2=fopen("c:\\bankingrecord.txt","w");

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

			remove("c:\\bankingrecord.txt");
			rename("c:\\temp.txt","c:\\bankingrecord.txt");
			fpoin1=fopen("d:\\bankingrecord.txt","r");

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
void inv(void)
{
			sound(700);
			outtextxy(300,430,"INVALID INPUT");
			delay(500);
			nosound();
			setcolor(0);
			outtextxy(300,430,"INVALID INPUT");
}
void entry(void)
{
	char *searchname,temp[30];
	int count=0,count1=0,success=0,i,j,success2=0,k=0;

	FILE *fpoin1,*fpoin2;
	cleardevice();
	start();

	cleardevice();
	start();
	gotoxy(10,5);
	printf("ENTER THE ACC NO OF CUSTOMER:");
	gets(temp);
	searchname=strupr(temp);
	gotoxy(10,7);
	fpoin1=fopen("c:\\bankingrecord.txt","r");
	while((fread(&customer,sizeof(customer),1,fpoin1))!=NULL)
	{

		count1++;
		if((strcmp(searchname,customer.accno)==0))
		{
			success2=1;
			cleardevice();
			start();

			gotoxy(9,10);
			printf("CUSTOMER NAME");
			gotoxy(34,10);
			

			start();
			count++;

			gotoxy(20,23);
			printf("(T)RANSACTION OR  (M)OVE FURTHER");
			switch(getch())
			{
				case 'T':
				case 't':
					  k=1;
					  success=1;
					  break;
				case 'M':
				case 'm':
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

			c=1;
			d=1;
			question();

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

			remove("d:\\bankingrecord.txt");
			rename("d:\\temp.txt","d:\\bankingrecord.txt");
			fpoin1=fopen("d:\\bankingrecord.txt","r");

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
void question()
{ 
FILE *fpoin;
	char temp[30];

	int a=50;
	fpoin=fopen("c:\\bankingrecord.txt","a");
	cleardevice();
	start(); 
    
  printf("\t WANTS TO (W)ITHDRAW MONEY OR (S)UBMIT MONEY");
  switch(getch())
 {

	case 'W':
        case 'w':{printf("\t enter amount to withdraw");
scanf("%d",&amt);
if(customer.bal>amt)
{customer.bal=customer.bal-amt;}
else printf(" not enough balance");}
break;

	case 'S':
	case 's':{printf("\t enter amount to submit");scanf("%d",&amt);customer.bal=customer.bal+amt;}
break;
}

	fwrite(&customer, sizeof(customer),1, fpoin);


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
void firstscreen()
{
   void start() ;
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);		
		setcolor(4);						
		outtextxy(16,40,"PROJECT ON  PUNJAB NATIONAL BANK");
		setcolor(8);
                outtextxy(30,200," MADE BY=");
                setcolor(5);
		outtextxy(180,200,"ANURAG GOEL");
	
		setcolor(5);
		settextstyle(1,1,25);
while(!(kbhit()))
	{

		
		settextstyle(1,0,25);
		outtextxy(180,350,"");

}
                
                  getch();

}

        

