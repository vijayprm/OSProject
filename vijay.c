#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void *faculty();
void *staff();
void *student();
int main()
{
pthread_t t1;
int ch;
printf("Welcome to Game Scheduler\n");
printf("Who Are You ???????\n");
printf("1. Faculty\n2. Student\n3. Computer Centre Staffs\n");
scanf("%d",&ch);
switch(ch)
{
case 1: pthread_create(&t1,NULL,faculty,NULL);
        break;
case 2: pthread_create(&t1,NULL,student,NULL);
        break;
case 3: pthread_create(&t1,NULL,staff,NULL);
        break;
case 4: exit(0);
default: printf("Invalid choice\n");        
}
pthread_join(t1,NULL);
return 0;
}
void *faculty()
{
	int t;
	printf("Enter the current Time in 24 hour foramat\n");
	scanf("%d",&t);
	if((t>=15 && t<=24)||(t>=1&&t<=8))
	{
		printf("Yoy can Play the Game\n");
	}
	else
	printf("Sorry you cannot play the game\n");	
}
void *student()
{
	float t;
	printf("Enter the current Time in 24 hour foramat\n");
	scanf("%d",&t);
	if((t>=22 && t<=24)||(t>=1&&t<=6))
	{
		printf("Yoy can Play the Game\n");
	}
	else
	printf("Sorry you cannot play the game\n");	
}
void *staff()
{
	int t;
	printf("Enter the current Time in 24 hour foramat\n");
	scanf("%d",&t);
	printf("Yoy can Play the Game\n");
}
