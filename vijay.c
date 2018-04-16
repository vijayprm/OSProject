#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
void *faculty(void *n);
void *staff(void *n);
void *student(void *n);
int main()
{
time_t curtime;
   struct tm *loc_time;
  char buf[150],buf1[10];
   curtime = time (NULL);
loc_time = localtime (&curtime);
strftime (buf, 150, "%I \n", loc_time);
strftime(buf1,10,"%p\n",loc_time);
int k;
if(buf[0]=='0')
{
	k=(int)buf[1];
	k-=48;
	if(buf1[0]=='P')
	k+=12;
}
else
{
	k=(int)buf[1];
	k-=38;
	if(buf1[0]=='P')
	k+=12;
} 
pthread_t t1;
int ch;
printf("Welcome to Game Station.\n");
printf("Who Are You ?\n");
printf("1. Faculty\n2. Student\n3. Computer Centre Staffs\n");
scanf("%d",&ch);
switch(ch)
{
case 1: pthread_create(&t1,NULL,faculty,(void*)&k);
        break;
case 2: pthread_create(&t1,NULL,student,(void*)&k);
        break;
case 3: pthread_create(&t1,NULL,staff,(void*)&k);
        break;
case 4: exit(0);
default: printf("Invalid choice\n");        
}
pthread_join(t1,NULL);
return 0;
}
void *faculty(void *n)
{
	int t=*(int *)n;
	if((t>=15 && t<=24)||(t>=1&&t<=8))
	{
		printf("You can Play the Game\n");
	}
	else
	printf("Sorry you cannot play the game\n");	
}
void *student(void *n)
{
	int t=*(int *)n;
	if((t>=22 && t<=24)||(t>=1&&t<=6)||t==12)
	{
		printf("You can Play the Game\n");
	}
	else
	printf("Sorry you cannot play the game\n");	
}
void *staff(void *n)
{
	
	printf("You can Play the Game\n");
}
