#include<stdio.h>
#include<time.h>
void faculty();
void staff();
void student();
int main()
{
int ch;
printf("Welcome to Game Scheduler\n");
printf("Who Are You ???????\n");
time_t curtime;
struct tm *loc_time;
char buf[150];
curtime = time (NULL);
loc_time = localtime (&curtime);
strftime (buf, 150, "%I\n", loc_time);
printf("%d",buf);
printf("1. Faculty\n2. Student\n3. Computer Centre Staffs\n");
scanf("%d",&ch);
switch(ch)
{
case 1: faculty();
        break;
case 2: student();
        break;
case 3: staff()
        break;
case 4: exit(0);
default: printf("Invalid choice\n");        
}
}


