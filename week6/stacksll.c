#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *top=NULL,*cur;
void push()
{
	cur=(struct node *)malloc(sizeof(struct node));
	printf("Enter current node data\n");
	scanf("%d",&(cur->data));
	cur->link=top;
	top=cur;
}
void pop()
{
	cur=top;
	top=cur->link;
	printf("Deleted element is %d\n",cur->data);
	cur->link=NULL;
	free(cur);
}
void display()
{
	if(top==NULL)
	{
		printf("Stack underflow");
	}
	else
	{
		cur=top;
		while(cur!=NULL)
		{
			printf("%d->",cur->data);
			cur=cur->link;
		}
	}
}
void peek()
{
	if(top!=NULL)
	{
		printf("Top element is %d",top->data);
	}
	else
	{
		exit(0);
	}
}
int main()
{
	int ch;
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
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			case 4: peek();
				break;
			case 5: exit(0);
		}
	}
}

	
	