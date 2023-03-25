#include <stdio.h>
#define MAX_SIZE 5
int front = -1, rear = -1;
int queue[MAX_SIZE];
void enqueue(int element);
int dequeue();
void display();
int main()
{
int choice, element;
do
{
printf("\n\nInput desired operation:\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice)
{
case 1:
printf("Enter the element to enqueue: ");
scanf("%d", &element);
enqueue(element);
break;
case 2:
element = dequeue();
if (element != -1)
printf("Dequeued element: %d\n", element);
break;
case 3:
display();
break;
case 4:
printf("Exiting...\n");
break;
default:
printf("Invalid choice!\n");
}
} 
while (choice != 4);
return 0;
}
void enqueue(int element)
{
if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
{
printf("Queue is full!\n");
return;
}
if (front == -1 && rear == -1)
{
front = rear = 0;
}
else if (rear == MAX_SIZE - 1)
{
rear = 0;
}
else
{
rear++;
}
queue[rear] = element;
printf("Enqueued element: %d\n", element);
}
int dequeue()
{
if (front == -1 && rear == -1)
{
printf("Queue is empty!\n");
return -1;
}
int element = queue[front];
if (front == rear)
{
front = rear = -1;
}
else if (front == MAX_SIZE - 1)
{
front = 0;
}
else
{
front++;
}
return element;
}
void display()
{
if (front == -1 && rear == -1)
{
printf("Queue is empty!\n");
return;
}
printf("Queue elements: ");
if (rear >= front)
{
for (int i = front; i <= rear; i++)
printf("%d ", queue[i]);
}
}