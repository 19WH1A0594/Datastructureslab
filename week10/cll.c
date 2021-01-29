#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL,*cur,*temp, *t1, *t2;
void create()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter current node data:\n");
	scanf("%d",&(cur->data));
	cur->link=cur;
	if(head==NULL)
	{
		head=cur;
	}
	else
	{
		temp = head;
		while(temp->link!=head)
			temp=temp->link;
		temp->link=cur;
		cur->link=head;
	}
}
void insert_at_begin()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter beginning data:\n");
	scanf("%d",&(cur->data));
	temp=head;
	while(temp->link!=head)
			temp=temp->link;
	temp->link=cur;
	cur->link=head;
	head=cur;
}
void insert_at_position()
{
	int pos,c=1;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter new node data to be stored at a position:\n");
	scanf("%d",&(cur->data));
	printf("Enter the position:\n");
	scanf("%d",&pos);
	t1=head;
	while(c<pos)
	{
		t2=t1;
		t1=t1->link;
		c++;
	}
	t2->link=cur;
	cur->link=t1;
}
void delete_at_begin()
{
	cur=temp=head;
	while(temp->link!=head)
		temp=temp->link;
	temp->link=cur->link;
	head=cur->link;
	cur->link=NULL;
	printf("Deleted element is %d\n",cur->data);
	free(cur);
}
void delete_at_end()
{
	t1=head;
	while(t1->link!=head)
	{
		t2=t1;
		t1=t1->link;
	}
	t2->link=head;
	t1->link=NULL;
	printf("Deleted element is %d\n",t1->data);
	free(t1);
}
void delete_at_position()
{
	int pos,c=1;
	printf("Enter position of deletion:\n");
	scanf("%d",&pos);
	t1=head;
	while(c<pos)
	{
		t2=t1;
		t1=t1->link;
		c++;
	}
	t2->link=t1->link;
	t1->link=NULL;
	printf("deleted element is %d\n",t1->data);
	free(t1);
}
void display()
{
	if(head==NULL)
	{
		printf("CLL is empty\n");
	}
	else
	{
		temp=head;
		while(temp->link!=head)
		{
			printf("%d->",temp->data);
			temp=temp->link;
		}
		printf("%d",temp->data);
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n\n");
		printf("------------------------------------------------------------------------\n");
		printf("PROGRAM FOR CIRCULAR LINKED LIST\n");
		printf("1. Create a single linked list\n");
		printf("2. Insert at begin\n");
		printf("3. Insert at position\n");
		printf("4. Delete at begin\n");
		printf("5. Delete at end\n");
		printf("6. Delete at position\n");
		printf("7. display\n");
		printf("8. Exit \n");
		printf("---------------------------------END-------------------------------------\n"); 
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: insert_at_begin();
				break;
			case 3: insert_at_position();
				break;
			case 4: delete_at_begin();
				break;
			case 5: delete_at_end();
				break;
			case 6: delete_at_position();
				break;
			case 7: display();
				break;
			case 8: exit(0);
		}
	}
}