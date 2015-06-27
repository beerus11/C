#include <graphics.h>//for graphics
#include <dos.h>//for exit
#include <conio.h>
#include<stdio.h>
#include<string.h>//for string operation
#include<time.h>//for time
#include<stdlib.h>//for stdlib function
void printTitle(void);//print project title
void menu2(void);//print main -menu of project
void printTitle2(void);//print border and project title
void fs(void);//for circle animation page
void help(void);//for help menu
int Password(void);//for passworord menu
void start(void);//for border printing
void pass(void);//for checking password
void day(void);//for day printing
void showMenu(void);//for showing menu
void menu(void);//for main menu
void inv(void);//for making sound on invlid entry
void itemf(void);//for adding items
void edit_item();//for editing items
void option1(void);//for viewing itmes
void view_item(void);//fr view items
void delete_item(void);//for deleting items
void add_item(void);//for adding items
void menu(void);//for shop management menu
void start2(void);//for printing borders
void shopa(void);//for shop addition
void shopd(void);//for shop deletion
void shope(void);//for shop edition
void shopv(void);//for shop viewing
void shpfn(void);//for shop menu
void funto(void);//for 1st page(graphics) 
void add_customer(void);//for booking items
void view_customer(void);//for prev record
void delete_customer(void);//for cancel order
int addemp();//for adding employs
int editemp();//for employ addition
int viewemp();//for viewing employ
int opt();//for employ searching
int emenu();//for employ management menu
struct record1 {              
	    char name[20];
	    char addr[40];
            char pnum[15];
	    char dob[15];
	    char pm[15];
	    char item[20];
	    
} customer;
struct node
{
  char name[50];
  int id;
  char add[50];
  int age;
  char dob[10];
  struct node * next;
};
struct nodec
{
  char namec[50];
  int idc;
  char addc[50];
  int agec;
  char dobc[10];
  struct node * next;
}clone;
typedef struct node  N;

int driver=VGA,mode=VGAHI;
 int Proceed=1;
struct record {                
	char name[30];
	char type[15];        
	int qty;
} item;
int c,d;
FILE *fp;
int i=1,j=1;
struct  shpstr
{
     char cat[30];
     char shpnam[30];
     char onam[30];
     int eno;
}shpd;

	int ass=35;
           int no=0;
           char sname1[50],sname2[50];
           int categoriesc=1;
           int shopc=1;
struct shop
{
       char namef[50];
       char onamef[50];
       int eno;
       struct shop *nextf;
       };


struct categories
{
       char names[50];
       struct shop *nextr;
       struct categories *nextd;
       };
       typedef struct shop f;
       typedef struct categories s;
       f *tempf,*headf,*pf,*tempf1;
       s *starts,*head,*temps,*ps,*temps1;
void main()
{    
      
     help();
      initgraph(&driver,&mode,"c:\\tc\\bgi");
      pass();
      cleardevice();
      clrscr();
      setbkcolor(0);
 fs();
      getch();
 closegraph();
 start();



}

void printTitle(void)
{
		int temp, temp2;

		temp=(rand()% 15)+1;
		settextstyle(7,HORIZ_DIR,6);
		setcolor(temp);						
		outtextxy(100,180,"SHOPING -MALL");
		temp2=(rand()%15)+1;
		setcolor(temp2);
		line(100,240,551,240);

		delay(400);

}
void fs()
{
int userpat=1,c=1,i=1;
cleardevice();
setbkcolor(WHITE);
   setcolor(5);

   settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
   outtextxy(180,40,"DS - PROJECT");
      setlinestyle(0, userpat, 1);
      setcolor(7);
      while(!(kbhit()))
	{
		 setfillstyle(SOLID_FILL,c);
      bar(150,65,480,70);
      delay(500);
       c++;
       printTitle();
	}
      printTitle();
      getch();
      setlinestyle(3,1,3);
      line(100,245,551,245);
	setcolor(4);
       settextstyle(10,HORIZ_DIR,4);
      outtextxy(140,280,"THE-OPULENT");
      setcolor(2);
       settextstyle(3,HORIZ_DIR,5);
      outtextxy(100,380,"MADE BY :ANURAG GOEL");
       setviewport(60,75,600,195,1);

      while(!(kbhit()))
      {
      setcolor(2);
      circle(100+i,58,25);
      setcolor(3);
      circle(150+i,58,25);
      setcolor(4);
      circle(200+i,58,25);
      setcolor(5);
      i=i+31;

      delay(400);
      clearviewport();
      }
    setbkcolor(0);

       setcolor(6);
       settextstyle(8,HORIZ_DIR,4);
       outtextxy(80,55,"NO DREAM IS TOO BIG");

 getch();
}
void help( )
{        
	
        
	 int i;
         
         funto();

         
	textcolor(RED+BLINK);
	gotoxy(18,2);
	cprintf("  P R O J E C T - SHOPING MALL ") ;
	textcolor(YELLOW+BLINK);
	gotoxy(18,4); 
	cprintf(" By- ANURAG GOEL AKSHAY GARG IRSHAD ALI SANTAOSH SHARMA ");
	delay(10) ;
	gotoxy(10,6);  printf("In  this  Project  you  can keep  records  of  daily  booking ORDER") ;
	delay(10) ;
	gotoxy(10,7);  printf(" It can book productS THAT have  to purchase             ") ;
	delay(10) ;
	gotoxy(10,9);  printf(" This  program is capable of holding reord of booking " );
	delay(10) ;
	gotoxy(10,11); printf("- an option for shop management" );
	delay(10) ;
	gotoxy(10,12); printf(" an option of item management in the mall") ;
	delay(10) ;
	gotoxy(10,14); printf("- booking and cancelation of records" );
	delay(10) ;
	gotoxy(10,16); printf("- previous records are available" );
	delay(10) ;
	gotoxy(10,18); printf("- There is an option for employees management" );
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
		delay(200) ;
		gotoxy(1,i);
	}

}
int Password ()
 
{         


	 char Password[12]="cracker"; 
	 char pass[20];
	 char UserName[15];
	 char user[15]="hacker";
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
void pass()
{
do
	{
	   Proceed = Password();
	} while ( Proceed!=1);
}
void start(void)

{
	initgraph(&driver,&mode,"c:\\tc\\bgi");

	day();
	setcolor(RED);
	setlinestyle(SOLID_LINE,1,3);
	rectangle(0,0,639,479);            
	setcolor(BLUE);
	setlinestyle(SOLID_LINE,1,2);     
	rectangle(10,10,629,469);
        menu();
	getch();
	closegraph();
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

void showMenu(void)
{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
		setcolor(WHITE);					
		outtextxy(60,150,"1) SHOP MANAGEMENT");	
		outtextxy(60,210,"2) ADD ITEMS");
                outtextxy(60,270,"3) BOOK/CANCELORDER/PREVRECORDS ");
                outtextxy(60,330,"4) EMPLOY MANAGEMENT");		
		outtextxy(60,390,"5) EXIT");		
}
void menu(void)
{
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
		setcolor(WHITE);					
		outtextxy(60,150,"1) SHOP MANAGEMENT");	
		outtextxy(60,210,"2) ADD ITEMS");
                outtextxy(60,270,"3) BOOK/CANCELORDER/PREVRECORDS ");
                outtextxy(60,330,"4) EMPLOY MANAGEMENT");		
		outtextxy(60,390,"5) EXIT");
	while (1)          						
   {
	while(!(kbhit()))//fuction run key is pressed
	{
		printTitle2();
	}
	switch(getch())
	{
		case '1':

			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,150,"1) SHOP MANAGEMENT");		
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,150,"1) SHOP MANAGEMENT");		
			delay(500);
                        shpfn();
                        cleardevice();
			start2();
		        menu();
			break;

			
			
		case '2':
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,210,"2) ADD ITEMS");	
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,210,"2) ADD ITEMS");	
			delay(500);
                        itemf();
			cleardevice();
			start2();
			menu();
                         break;
		
                case '3':
                        settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,270,"3) BOOK/CANCELORDER/PREVRECORDS ");			
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,270,"3) BOOK/CANCELORDER/PREVRECORDS ");			
			delay(500); 
                        menu2();
                        cleardevice();
			start2();
			menu();
                         break;
			
	       case '4':
                        settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,330,"4) EMPLOY MANAGEMENT");			
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,330,"4) EMPLOY MANAGEMENT");			
			delay(500);
                         emenu();
                          cleardevice();
			start2();
			menu();
                         break;
			
               case '5':
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,390,"5) EXIT");			
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
			setcolor(10);					
			outtextxy(60,390,"5) EXIT");			
			delay(500);

			 exit(0);
			break;
		default:inv();
			
	}
    }

}
void printTitle2( )
{
		int temp, temp2;

		temp=(rand()% 15)+1;
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);		
		setcolor(temp);						
		outtextxy(16,40,"The Opulent");	

		temp2=(rand()%15)+1;
		setcolor(temp2);						
		line(20,80,215,80);

		delay(400);						

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
void itemf(void)
{
	d=0,c=0;
	cleardevice();
        initgraph(&driver,&mode,"c:\\tc\\bgi");

	start2();
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
	setcolor(GREEN);
	outtextxy(25,40," ITEM INFORMATION");
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
			start2();
			menu();
			break;

		default :
			inv();
			itemf();
closegraph();
	 }

getch();
}
void add_item(void)
{
	FILE *fpoin;
	char temp[30];

	int a=35;
	fpoin=fopen("c:\\item.txt","a");
	cleardevice();
	start2();
        setcolor(WHITE);
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


	
	cleardevice();
	start2();
	outtextxy(90,290,"RECORD ADDED");
	outtextxy(90,310,"PRESS ANY KEY TO CONTINUE");
	getch();
	

	fclose(fpoin);
	fflush(stdin);
}
void delete_item(void)
{
	char *searchname,temp1[30],temp[30];
	int count=0,count1=0,success=0,i,j,success2=0,k=0;

	FILE *fpoin,*fpoin1;
	cleardevice();
	start2();

	cleardevice();
	start2();
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
			start2();

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
			start2();
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
					start2();
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
				start2();
				setcolor(RED);
				outtextxy(100,170,"RECORD DELETED");
				delay(1500);

			fread(&item,sizeof(item),1,fpoin);

			while((fread(&item,sizeof(item),1,fpoin))!=NULL)
			fwrite(&item, sizeof(item),1,fpoin1);

			start2();



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


	start2();
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
	start2();
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
			start2();

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
			start2();
			count++;
			getch();

		}
	 }
	printf("\n\n\t\t\tTHERE ARE %d RECORD(S)",count);
	start2();
	getch();
}


void edit_item()
{
	char *searchname,temp1[30],temp[30];
	int count=0,count1=0,success=0,i,j,k=0,success2=0;

	FILE *fpoin,*fpoin1;
	cleardevice();
	start2();

	cleardevice();
	start2();
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
			start2();

			gotoxy(9,10);
			printf("item NAME");
			gotoxy(26,10);
			puts(item.name);
			gotoxy(20,11);

			printf("\n\n\n\n\n");
			start2();
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
				start2();
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
				start2();
				setcolor(RED);
				outtextxy(100,170,"RECORD MODIFIED");
				delay(1500);

			while((fread(&item,sizeof(item),1,fpoin))!=NULL)
			fwrite(&item, sizeof(item),1,fpoin1);

			start2();



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
void start2(void)

{
	

	day();

	setcolor(RED);
	setlinestyle(SOLID_LINE,1,3);
	rectangle(0,0,639,479);            
	setcolor(BLUE);
	setlinestyle(SOLID_LINE,1,2);     
	rectangle(10,10,629,469);
	
	
}
void shopa(void)
{

           
           clrscr();
           cleardevice();

       

           printf("\n-----------Welcome-----------\n");
           printf("\n \n Press  enter 0 if u dont want to add more  \n\n");
           head=NULL;
           
	   while(categoriesc!=0)
           { no++;
           temps=(s*)malloc(sizeof(s));
           temps->nextd=NULL;
           temps->nextr=NULL;
           if(starts==NULL)
           {
                          starts=head=temps;
                          }
                          else
                          {
                              head->nextd=temps;
                              head=temps;
                              }
                              printf("\nEnter %dth categories name  :",j);
                              scanf("%s",&temps->names);
                              while(shopc!=0)
                              {

                                           tempf=(f*)malloc(sizeof(f));
                                           tempf->nextf=NULL;

                                           if(temps->nextr==NULL)
                                           {
                                                                temps->nextr=tempf;
                                                                headf=tempf;
                                                                }
                                                                else
                                                                headf->nextf=tempf;
                                                                headf=tempf;
                                                                 printf("\nEnter name of  %dth  shop of %s : ",i,temps->names);
                                                                 scanf("%s",&tempf->namef);
                                                                  printf("\nEnter Owner Name  %dth  shop of %s : ",i,temps->names);
                                                                 scanf("%s",&tempf->onamef);
                                                                  printf("\nEnter no of employs  %dth  shop of %s : ",i,temps->names);
                                                                 scanf("%d",&tempf->eno);

                                                                printf("\nDo you want to enter more shops =");
            scanf("%d",&shopc);
            i++;
           }
           shopc=1;
           i=1;
            printf("\nDo you want to enter more categories  :");
            scanf("%d",&categoriesc);
            j++;
           }

	       temps=starts;
          fp=fopen("C:\\shopmagement.txt","w");
         
       
            while(temps!=NULL)
               {
                    
                    strcpy(shpd.cat,strupr(temps->names));
                   tempf=temps->nextr;
                   
                    while(tempf!=NULL)
                   {
	
	strcpy(shpd.shpnam,strupr(tempf->namef));
	strcpy(shpd.onam,strupr(tempf->onamef));
	shpd.eno=tempf->eno;

	
                     fwrite(&shpd, sizeof(shpd),1, fp);
                   printf("\n %s ", tempf->namef);
                     tempf=tempf->nextf;
                   }
                
                  temps=temps->nextd;

           }


  fflush(stdin);
  fclose(fp);

}

void shpfn()
{         
	cleardevice();
         clrscr();
         start2();
         printTitle2( );

        settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
	outtextxy(60,150,"1)ADD SHOP");
	outtextxy(60,210,"2)DELETE SHOP");
	outtextxy(60,270,"3)VIEW SHOP");
	outtextxy(60,330,"4)EDIT SHOP INFORMATION");
	outtextxy(60,390,"5)GO BACK TO THE MAIN MENU");
	switch(getch())
	{
		case '1':

			shopa();
			cleardevice();
			shpfn();
			break;
                case '2':

			shopd();
			cleardevice();
			shpfn();
			break;
                case '3':

			shopv();
			cleardevice();
			shpfn();
			break;
                case '4':

			shope();
			cleardevice();
			shpfn();
			break;
                case '5':
                         cleardevice();
			start();
			menu();
			break;




		default :
			inv();
			
	 }




    fflush(stdin);


}
void funto()
{
           int gdriver = DETECT,gmode;
       int x,y,i;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	x=getmaxx()/2;
	y=getmaxy()/2;
	for(i=30;i<200;i++)
	{
		delay(10);
				setcolor(i/10);
		arc(x,y,0,180,i-10);
	}
	setcolor(RED);
	settextstyle(1,0,8);
	outtextxy(50,290,"ANURAG GOEL");
	setcolor(YELLOW);
	settextstyle(1,0,4);
	outtextxy(50,370,"Email: thechampanurag@gmail.com");
	setcolor(GREEN);
	settextstyle(1,0,6);
	outtextxy(150,410,"9810972388");

	settextstyle(1,0,4);
	while (!kbhit())
{

setcolor(i%15);
outtextxy(10,260,"Desgin By :");
delay(10);

i++;
}
closegraph();
}


    
    int addemp()
    {    FILE *fpe;
         N * temp , *head;
        head  =  NULL;
	temp=(N*)malloc(sizeof(N));
         fpe=fopen("c:\\emp.txt","a");
        printf("\n \t\tEnter Employee  Name  :");
        scanf("%s",&temp->name);
        printf("\n\t\tEnter Employee  Address :");
        scanf("%s",&temp->add);
        printf("\n \t\tEnter Employee  Dob  :");
        scanf("%s",&temp->dob);
        printf("\n\t\tEnter Employee  ID  :");
        scanf("%d",&temp->id);
        printf("\n\t\tEnter Employee  Age  :");
        scanf("%d",&temp->age);
        strcpy(clone.namec,strupr(temp->name));
        strcpy(clone.addc,strupr(temp->add));
        strcpy(clone.dobc,strupr(temp->dob));
        clone.idc=temp->id;
        clone.agec=temp->age;
        
         fwrite(&clone, sizeof(clone),1, fpe);
        temp->next=head;
         head=temp;
         fclose(fpe);
	      fflush(stdin);
        return 0;
        
        
    }
int editemp()
{
    
    
   char *searchname,temp1[30],temp[30];
	int count=0,count1=0,success=0,i,j,success2=0,k=0;

	FILE *fpoin,*fpoin1;
	printf("ENTER THE NAME OF THE EMPLOYEE:");
	scanf("%s",&temp1);
	searchname=strupr(temp1);

	fpoin=fopen("c:\\emp.txt","r");
	while((fread(&clone,sizeof(clone),1,fpoin))!=NULL)
	{

		count1++;
		if((strcmp(searchname,clone.namec)==0))
		{
			success2=1;
		

		
			printf("\n\tEMPLOYEE NAME    :");
		
			puts(clone.namec);
		
                         printf("\tDOB\t\t :%s \
			 \n\tAGE\t\t :%d       \
			        \
				  ",clone.dobc,clone.agec);


			printf("\n\n\n\n\n");
		
			count++;
			
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
					 
			}

			  if(success==1)
			  break;
		}


	}

       if((success2==1)&&(success==1))
	  {
		rewind(fpoin);
		fpoin1=fopen("c:\\emp.txt","w");

		for(i=1;i<count1;i++)
		{
			fread(&clone,sizeof(clone),1,fpoin);
			fwrite(&clone, sizeof(clone),1,fpoin1);
		}

				  for(j=0;j<=3;j++)
				{
				
				
					printf("\nRECORD DELETING");

				 }
				
				printf("RECORD DELETED");
				

			fread(&clone,sizeof(clone),1,fpoin);

			while((fread(&clone,sizeof(clone),1,fpoin))!=NULL)
			fwrite(&clone, sizeof(clone),1,fpoin1);




			fclose(fpoin1);
			fclose(fpoin);

			remove("c:\\emp.txt");
			rename("c:\\temp23.txt","c:\\emp.txt");
			fpoin=fopen("c:\\emp.txt","r");

	  }

		if(success2==0)
	  {
		
		printf("RECORD NOT FOUND");
		getch();
	  }

	 if((count!=0)&&(k==0))
		{
		  
		  printf("THERE ARE %d RECORD(S) LEFT",count);
		  getch();
		}
		 return 0;
}
 int emenu()
	{   int choice;
            cleardevice();
	    clrscr();
    printf("\t\t********************Welcome**********************");
    printf("\n\t\t 1.Add Employee   ");
    printf("\n\t\t 2.Edit Employee   ");
    printf("\n\t\t 3.View Employee   ");
    printf("\n\t\t 4.Back \n  ");
    scanf("\n\t\t%d",&choice);
    switch(choice)
    {
                      case 1:   addemp();
                               emenu();
                                break;
                     case 2: editemp();
                             emenu();
                              break; 
                     
                     case 3:  
                            viewemp();
                            break; 
                     case 4: cleardevice();
                             clrscr();
                            menu();
                             break;
                          
                          default: ;
                          }
                          
                          return 0;
                          }
                          
                         
                          
                          int viewemp()
{

	
	printf("\nPRESS");
	printf("\n1 - TO SEARCH BY NAME");
	printf("\n2 - TO GO BACK");

	switch(getch())
	{
		case '1':
			 opt();
			 viewemp();
			 break;
		
		case '2':
			 emenu();
			 break;
		default :
			
			 viewemp();

	}
	fflush(stdin);
	return 0;
}



int opt()
{
	FILE *fpoin;

	char *searchname,temp[30];
	int count=0;
	printf("\n\nEnter the name of employee to search:");
	scanf("%s",&temp);
	searchname=strupr(temp);
	fpoin=fopen("c:\\emp.txt","r");

	while((fread(&clone,sizeof(clone),1,fpoin))!=NULL)
	{


		if(strcmp(searchname,clone.namec)==0)
		{
			
		printf("\n\tEMPLOYEE NAME    :");
		
			puts(clone.namec);
		
                         printf("\tDOB\t\t :%s \
			 \n\tAGE\t\t :%d       \
			        \
				  ",clone.dobc,clone.agec);


			printf("\n\n\n\n\n");
			
			count++;
			getch();

		}
	 }
	printf("\n\n\t\t\tTHERE ARE %d RECORD(S)",count);
	 return 0;
	
}







void menu2(void)
  
{               cleardevice();
                 start2();
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
		setcolor(WHITE);					
		outtextxy(60,150,"1) NOTHING");	
		outtextxy(60,210,"2) RECORD");
                outtextxy(60,270,"3) BOOK ORDER");
                outtextxy(60,330,"4) CANCEL ORDER");		
		outtextxy(60,390,"5) EXIT");	

	while (1)          						
   {
	while(!(kbhit()))
	{
		printTitle2();
	}

	switch(getch())                					
	{
		case '1':

			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,150,"1) NOTHING");	
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,150,"1) NOTHING");	
			delay(500);
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
			start2();
			menu2();
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
                        cleardevice();
			start2();
			menu2();
			break;
	       case '4':
                        settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,330,"4) CANCEL ORDER");			
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,330,"4) CANCEL ORDER");			
			delay(500);
			delete_customer();
                        cleardevice();
			start2();
			menu2();
			break;;
               case '5':
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);		
			setcolor(0);					
			outtextxy(60,390,"5) EXIT");			
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);		
			setcolor(10);					
			outtextxy(60,390,"5) EXIT");			
			delay(500);

			exit(0);                                
			break;
		default:
			inv();
	}
    }
}

void add_customer(void)
{
	FILE *fpoin1;
	char temp[30];

	int a=35;
	fpoin1=fopen("c:\\itembooking.txt","a");
	cleardevice();
	start2();

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
	start2();
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
	start2();

	cleardevice();
	start2();
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
			start2();

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

			start2();
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
					start2();
					settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
					setcolor(WHITE);
					outtextxy(100,150,"RECORD DELETING");
					delay(700);
					setcolor(BLACK);
					outtextxy(100,150,"RECORD DELETING");
					delay(700);
					setcolor(WHITE);

				 }


			start2();
				cleardevice();
				start2();
				setcolor(RED);
				outtextxy(100,170,"RECORD DELETED");
				delay(1500);



			fclose(fpoin2);
			fclose(fpoin1);

			remove("c:\\itembooking.txt");
			rename("c:\\temp.txt","c:\\itembooking.txt");
			fpoin1=fopen("c:\\itembooking.txt","r");

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
	start2();
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
			start2();

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
			start2();
			count++;
			getch();

		}
	 }
	printf("\n\t\t\tTHERE ARE %d RECORD(S)",count);
	start2();
	getch();

}


void shope()
{
clrscr();
cleardevice();
printf("\n\nplz try tomorrow,server busy");
getch();

}
void shopv()
{
clrscr();
cleardevice();
printf("\n\nplz try tomorrow,server busy");
getch();
}

void shopd()
{
char *searchname,temp1[30],temp[30];
	int count=0,count1=0,success=0,i,j,success2=0,k=0;

	FILE *fpoin,*fpoin1;
	cleardevice();
	start2();

	cleardevice();
	start2();
	gotoxy(10,5);
	printf("ENTER THE NAME OF THE SHOP:");
	gets(temp1);
	searchname=strupr(temp1);
	gotoxy(10,7);
	
	fpoin=fopen("c:\\shopmagement.txt","r");
	while((fread(&shpd,sizeof(shpd),1,fpoin))!=NULL)
	{

		count1++;
		if((strcmp(searchname,shpd.shpnam)==0))
		{
			success2=1;
			cleardevice();
			start2();

			gotoxy(9,10);
			printf("CATEGORY NAME");
			gotoxy(26,10);
			puts(shpd.cat);
			gotoxy(20,11);
                         printf("\n\tSHOP CATEGORY  NAME\t\t\t %s \
			 \n\tOWNER NAME\t\t %s       \
			        \
				  ",shpd.cat,shpd.onam);


			printf("\n\n\n\n\n");
			start2();
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
		fpoin1=fopen("c:\\shopmagement.txt","w");

		for(i=1;i<count1;i++)
		{
			fread(&shpd,sizeof(shpd),1,fpoin);
			fwrite(&shpd, sizeof(shpd),1,fpoin1);
		}

				  for(j=0;j<=3;j++)
				{
					cleardevice();
					start2();
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
				start2();
				setcolor(RED);
				outtextxy(100,170,"RECORD DELETED");
				delay(1500);

			fread(&item,sizeof(shpd),1,fpoin);

			while((fread(&shpd,sizeof(shpd),1,fpoin))!=NULL)
			fwrite(&shpd, sizeof(shpd),1,fpoin1);

			start2();



			fclose(fpoin1);
			fclose(fpoin);

			remove("c:\\shopmagement.txt");
			rename("c:\\temp.txt","c:\\shopmagement.txt");
			fpoin=fopen("c:\\shopmagement.txt","r");

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

