#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
struct node 
{
int data;
struct node *nextptr;
};
struct node *front=NULL;
struct node *rear=NULL;
int main()
{
int ch;
do{
printf("\nInput the desired operation:\n1.   ENQUEUE (Insert Data)\n2.   DEQUEUE (Delete Data)\n3.   DISPLAY\n4.   EXIT\n\n");
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
struct node *ptr;
int item;
printf("Enter the item to enqueue:\n");
scanf("%d",&item);
ptr=(struct node *)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("\nOVERFLOW");
return;
}
else
{
ptr->data=item;
if(front==NULL)
{
front=ptr;
rear=ptr;
front->nextptr=NULL;
rear->nextptr=NULL;
}
else
{
rear->nextptr=ptr;
rear=ptr;
rear->nextptr=NULL;
}
}
}

void dequeue()
{
struct node *ptr;
if(front==NULL)
{
printf("\nUNDERFLOW");
return;
}
else
{
if(front==rear)
{
ptr=front;
printf("\nDequeued data is: %d.\n",ptr->data);
front=NULL;
rear=NULL;

}
else
{
ptr=front;
printf("\nDequeued data is: %d.\n",ptr->data);
front=front->nextptr;
free(ptr);
}
}
}

void display()
{
struct node *temp;
if((front==NULL)&&(rear==NULL))
{
printf("Queue is empty.");
}
else
{
printf("\nThe queue is:\n");
temp=front;
while(temp)
{
printf("%d\n",temp->data);
temp=temp->nextptr;
}
}
}