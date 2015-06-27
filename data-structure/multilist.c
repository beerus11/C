#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
struct friend
{
       char namef[50];
       struct friend *nextf;
       };

struct student
{
       char names[50];
       struct friend *nextr;
       struct student *nextd;
       };
       typedef struct friend f;
       typedef struct student s;
       f *tempf,*headf;
       s *start,*head,*temps;
       int main()
       {
           printf("\n-----------Welcome-----------\n");
           printf("\n \n Press  enter 0 if u dont want to add more  \n\n");
           head=NULL;
           int i,j,ch,gotit=0;
           int studentc=1;
           int friendc=1;
           i=1;
           j=1;
           char sname1[50],sname2[50];
           while(studentc!=0)
           {
           temps=(s*)malloc(sizeof(s));
           temps->nextd=NULL;
           temps->nextr=NULL;
           if(start==NULL)
           {
                          start=head=temps;
                          }
                          else
                          {
                              head->nextd=temps;
                              head=temps;
                              }
                              printf("\nEnter %dth student name  :",j);
                              scanf("%s",&temps->names);
                              while(friendc!=0)
                              {

                                           tempf=(f*)malloc(sizeof(f));
                                           tempf->nextf=NULL;
                                           tempf->namef;
                                           if(temps->nextr==NULL)
                                           {
                                                                temps->nextr=tempf;
                                                                headf=tempf;
                                                                }
                                                                else
                                                                headf->nextf=tempf;
                                                                headf=tempf;
                                                                 printf("\nEnter name of  %dth  friend of %s : ",i,temps->names);
                                                                 scanf("%s",&tempf->namef);
                                                                printf("\nDo you want to enter more friends =");
            scanf("%d",&friendc);
            i++;
           }
           friendc=1;
           i=1;
            printf("\nDo you want to enter more student  :");
            scanf("%d",&studentc);
            j++;
           }
           printf("\n\n\n\n\n");
           printf("\n\n(1)	Display list of all college friends of ABC (user entered student name)");
           printf("\n\n(2)	Display list of all students to whom ABC is one of the friend");
           printf("\n\n(3)	Display list of students who are friend to ABC as well as XYZ (another student name entered by user).");
           printf("\n\n(4)	Display name of student (s) who has maximum friends.");
           printf("\n\n(5)	Display name of students (s) who has maximum common friends.");
           printf("\n\n(6)	Due to some reason one student left the college. Delete his name from the list of students as well as delete his name from all students friend list");
           printf("\n\n(7)	Some students may join the college late and make friends after words. Add these students record into list of students along with their list of friends. Further, add their names into the friend lists of other students whom newly joined student is a friend.");
           printf("\n");
           scanf("%d",&ch);
           printf("\n\n\n\n");
           if(ch==1)
           {
               printf("\n Enter the Student name  :\n");
               scanf("%s",&sname1);

               temps=start;
               while(temps!=NULL)
               {
                   tempf=temps->nextr;
                    if(strcmpi(temps->names,sname1)==0)
                 {
                    while(tempf!=NULL)
                   {
                   printf("\n %s ", tempf->namef);
                     tempf=tempf->nextf;
                   }
                 }
                  temps=temps->nextd;

           }
           }
           if(ch==2)
           {printf("\n Enter the Student name  :");
               scanf("%s",&sname1);

               temps=start;
               while(temps!=NULL)
               {
                   tempf=temps->nextr;

                 {
                    while(tempf!=NULL)
                   {
                       if(strcmpi(tempf->namef,sname1)==0)
                {
                     printf("\n%s",temps->names);
                    break;
                }
                     tempf=tempf->nextf;
                   }
                 }
                  temps=temps->nextd;

           }

           }
           if(ch==3)
           {
printf("\n Enter the  1st Student name  :");
               scanf("%s",&sname1);
               printf("\n Enter the 2nd Student name  :");
               scanf("%s",&sname2);

               temps=start;
               while(temps!=NULL)
               {
                   tempf=temps->nextr;


                    while(tempf!=NULL)
                   {
                       if(strcmpi(tempf->namef,sname1)==0)
                {

                      gotit++;
                }
                 if(strcmpi(tempf->namef,sname2)==0)
                {

                      gotit++;
                }
                     tempf=tempf->nextf;
                   }
                   if(gotit==2)
                      {
                          printf(" \n The student  who is friend of both student is  : %s",temps->names);
                      }

                  temps=temps->nextd;

           }
           }
           return 0;
           getch();
           }
