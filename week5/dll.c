#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head=NULL, *tail=NULL,*temp2,*temp1,*cur;
void create()
{
	int n,i;
	printf("Enter number of nodes:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cur = (struct node *)malloc(sizeof(struct node));
		printf("Enter current node data: \n");
		scanf("%d",&(cur->data));
		cur->prev=NULL;
		cur->next=NULL;
		if(head==NULL)
		{
			head=tail=cur;
		}
		else
		{
			tail->next=cur;
			cur->prev=tail;
			tail=cur;
		}
	}
}
void insert_at_begin()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter new beginning data:\n");
	scanf("%d",&(cur->data));
	cur->prev=NULL;
	cur->next=head;
	head->prev=cur;
	head=cur;
}
void insert_at_end()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter new ending data:\n");
	scanf("%d",&(cur->data));
	cur->next=NULL;
	cur->prev=tail;
	tail->next=cur;
	tail=cur;
}
void insert_at_position()
{
	int c=1,pos;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter new node data to be stored at a position: \n");
	scanf("%d",&(cur->data));
	printf("Enter position where the data is to be stored: \n");
	scanf("%d",&pos);
	temp1=head;
	while(c<pos && temp1!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
		c++;
	}
	temp2->next=cur;
	cur->prev=temp2;
	cur->next=temp1;
	temp1->prev=cur;
}
void insert_before_node()
{
	int value;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter new node data:\n");
	scanf("%d",&(cur->data));
	printf("Enter the node data before which the new data should be stored:\n");
	scanf("%d",&value);
	temp1=head;
	while(temp1->data!=value && temp1!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
	}
	temp2->next=cur;
	cur->prev=temp2;
	cur->next=temp1;
	temp1->prev=cur;
}
void insert_after_node()
{
	int value;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter new node data:\n");
	scanf("%d",&(cur->data));
	printf("Enter the node data after which the new data should be stored:\n");
	scanf("%d",&value);
	temp1=head;
	while(temp1->data!=value && temp1!=NULL)
	{
		temp1=temp1->next;
	}
	cur->next=temp1->next;
	temp1->next->prev=cur;
	temp1->next=cur;
	cur->prev=temp1;
}
void search_for_element()
{
	int value,c=1,flag=0;
	printf("Enter the element which you want to search:\n");
	scanf("%d",&value);
	temp1=head;
	while(temp1!=NULL)
	{
		if(temp1->data==value)
		{
			flag=1;
			break;
		}
		temp1=temp1->next;
		c++;
	}
	if(flag==1)
	{
		printf("Element present at %d position\n",c);
	}
	else
	{
		printf("Element not present\n");
	}
}	
void display()
{
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		cur=head;
		while(cur!=NULL)
		{
			printf("%d<->",cur->data);
			cur=cur->next;
		}
	}
}
void display_in_reverse()
{
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		cur=tail;
		while(cur!=NULL)
		{
			printf("%d<->",cur->data);
			cur=cur->prev;
		}
	}
}
void delete_at_begin()
{
	cur=head;
	head=cur->next;
	head->prev=NULL;
	printf("Deleted element is %d\n",cur->data);
	cur->next=NULL;
	free(cur);
}
void delete_at_end()
{
	cur=tail;
	tail=cur->prev;
	tail->next=NULL;
	printf("Deleted element is %d\n",cur->data);
	cur->prev=NULL;
	free(cur);
}
void delete_at_position()
{
	int c=1,pos;
	printf("Enter position of deletion:\n");
	scanf("%d",&pos);
	temp1=head;
	while(c<pos && temp1!=NULL)
	{
		temp1=temp1->next;
		c++;
	}
	temp1->prev->next=temp1->next;
	temp1->next->prev=temp1->prev;
	printf("Deleted element is %d\n",temp1->data);
	temp1->prev=NULL;
	temp1->next=NULL;
	free(temp1);
}
void delete_before_node()
{
	int value;
	printf("Enter before which node we need to delete:\n");
	scanf("%d",&value);
	temp1=head;
	while(temp1->next->data!=value && temp1!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
	}
	temp1->prev->next=temp1->next;
	temp1->next->prev=temp1->prev;
	temp1->prev=NULL;
	temp1->next=NULL;
	printf("Deleted element is %d\n",temp1->data);
	free(temp1);
}
void delete_after_node()
{
	int value;
	printf("Enter after which node we need to delete:\n");
	scanf("%d",&value);
	temp1=head;
	while(temp1->data!=value && temp1!=NULL)
	{
		temp1=temp1->next;
	}
	cur=temp1->next;
	cur->prev->next=cur->next;
	cur->next->prev=temp1;
	cur->prev=NULL;
	cur->next=NULL;
	printf("Deleted element is %d\n",cur->data);
	free(cur);
}
void bubblesort()
{
	struct node *p1,*p2;
	int c=0,t;
	p1=head;
	while(p1!=NULL)
	{
		c++;
		p1=p1->next;
	}
	for(int i=0;i<c;i++)
	{
		p2=head;
		while(p2->next!=NULL)
		{
			if(p2->data > p2->next->data)
			{
				t=p2->data;
				p2->data=p2->next->data;
				p2->next->data=t;
			}
			p2=p2->next;
		}
	}
}
void sorting()
{
	struct node *p1,*p2,*last=NULL;
	int c,t;
	do
	{
		c=0;
		p1=head;
		while(p1->next!=last)
		{
			if(p1->data>p1->next->data)
			{
				t=p1->data;
				p1->data=p1->next->data;
				p1->next->data=t;
				c=1;
			}
		p1=p1->next;
		}
		last=p1;
	}while(c);
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n\n");
		printf("------------------------------------------------------------------------\n");
		printf("PROGRAM FOR DOUBLE LINKED LIST\n");
		printf("1. Create a double linked list\n");
		printf("2. Insert at begin\n");
		printf("3. Insert at end\n");
		printf("4. Insert at position\n");
		printf("5. Insert before node\n");
		printf("6. Insert after node\n");
		printf("7. search_for_element\n");
		printf("8. Display\n");
		printf("9. Display_in_reverse\n");
		printf("10. Delete at begin\n");
		printf("11. Delete at end\n");
		printf("12. Delete at position\n");
		printf("13. Delete before node\n");
		printf("14. Delete after node\n");
		printf("15. Bubblesort\n");
		printf("16. sorting\n");
		printf("17. Exit \n");
		printf("---------------------------------END-------------------------------------\n"); 
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: insert_at_begin();
				break;
			case 3: insert_at_end();
				break;
			case 4: insert_at_position();
				break;
			case 5: insert_before_node();
				break;
			case 6: insert_after_node();
				break;
			case 7: search_for_element();
				break;
			case 8: display();
				break;
			case 9: display_in_reverse();
				break;
			case 10: delete_at_begin();
				break;
			case 11: delete_at_end();
				break;
			case 12: delete_at_position();
				break;
			case 13: delete_before_node();
				break;
			case 14: delete_after_node();
				break;
			case 15: bubblesort();
				break;
			case 16: sorting();
				break;
			case 17: exit(0);
		}
	}
}
			
	