#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
int a[maxsize],top=-1;
void push(int item)
{
	top++;
	a[top]=item;
}
int pop()
{
	return(a[top--]);
}
int isfull()
{
	if(top==maxsize-1)
		return 1;
	else
		return 0;
}
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int peek()
{
	return(a[top]);
}
void display()
{
	for(int i=top;i>=0;i--)
		printf("%d ",a[i]);
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("\n\n");
		printf("----------------------\n");
		printf("PROGRAM FOR STACK\n");
		printf("1. push\n");
		printf("2. pop\n");
		printf("3. display\n");
		printf("4. peek\n");
		printf("5. exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(isfull())
				{
					printf("Stack overflow");
				}
				else
				{
					printf("Enter data to push \n");
					scanf("%d",&x);
					push(x);
				}
				break;
			case 2: if(isempty())
				{
					printf("Stack underflow");
				}
				else
				{
					x=pop();
					printf("Deleted element is %d\n",x);
				}
				break;
			case 3: display();
				break;
			case 4: printf("Topmost element on the stack is %d",peek());
				break;
			case 5: exit(0);
		}
	}
}
			
					