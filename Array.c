#include<stdio.h>
#include<stdlib.h>
#define size 10
int front=-1;
int rear=-1;
int queue[size];
void enqueue();
void dequeue();
void display();
int main()
{
int ch;
do
{
printf("\nInput the desired operation:\n1.   ENQUEUE\n2.   SEQUEUE\n3.   DISPLAY\n4.   EXIT\n\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
printf("PROGRAM TERMINATED");
exit(0);
break;
}
}
while(1);
return 0;
}
void enqueue()
{
int data;
if(rear==size-1)
{
printf("OVERFLOW");
}
else
{
if(front==-1)
{
front=0;
}
printf("Input the data to enqueue:");
scanf("%d",&data);
rear=rear+1;
queue[rear]=data;
}
}
void dequeue()
{
if(front==-1)
{
printf("UNDERFLOW");
}
else
{
printf("The dequeued data is: %d.",queue[front]);
front=front+1;
if(front>rear)
{
front=-1;
rear=-1;
}
}
}
void display()
{
if(front==-1)
{
printf("Queue is empty.");
}
else
{
int i;
for(i=front;i<=rear;i++)
{
printf("\n%d",queue[i]);
}
}
}