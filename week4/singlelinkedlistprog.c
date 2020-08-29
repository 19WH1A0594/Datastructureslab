#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL, *tail=NULL, *cur, *prev, *next;
void create()
{
	int n;
	printf("Enter number of nodes:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cur = (struct node *)malloc(sizeof(struct node));
		printf("Enter current node data:\n");
		scanf("%d",&(cur->data));
		cur->link=NULL;
		if(head==NULL)
		{
			head=tail=cur;
		}
		else
		{
			tail->link=cur;
			tail=cur;
		}
	}
}
void insert_at_begin()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter beginning data:\n");
	scanf("%d",&(cur->data));
	cur->link=head;
	head=cur;
}
void insert_at_end()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter ending node data:\n");
	scanf("%d",&(cur->data));
	cur->link=NULL;
	tail->link=cur;
	tail=cur;
}
void insert_at_position()
{
	int pos,c=1;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter new node data to be stored at a position:\n");
	scanf("%d",&(cur->data));
	printf("Enter the position:\n");
	scanf("%d",&pos);
	next=head;
	while(c<pos)
	{
		prev=next;
		next=next->link;
		c++;
	}
	prev->link=cur;
	cur->link=next;
}
void insert_before_node()
{
	int value;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter new node data:\n");
	scanf("%d",&(cur->data));
	printf("Enter the node data before which the new data should be stored:\n");
	scanf("%d",&value);
	next=head;
	while(next->data!=value && next!=NULL)
	{
		prev=next;
		next=next->link;
	}
	prev->link=cur;
	cur->link=next;
}
void insert_after_node()
{
	int value;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter new node data:\n");
	scanf("%d",&(cur->data));
	printf("Enter the node data after which the new data should be stored:\n");
	scanf("%d",&value);
	next=head;
	while(next->data!=value && next!=NULL)
	{
		next=next->link;
	}
	cur->link=next->link;
	next->link=cur;
}
void traversal()
{
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		next=head;
		while(next!=NULL)
		{
			printf("%d->",next->data);
			next=next->link;
		}
	}
}
void delete_at_begin()
{
	cur=head;
	head=cur->link;
	cur->link=NULL;
	printf("Deleted element is %d\n",cur->data);
	free(cur);
}
void delete_at_end()
{
	cur=head;
	while(cur->link!=tail)
	{
		cur=cur->link;
	}
	cur->link=NULL;
	next=tail;
	printf("Deleted element is %d\n",next->data);
	free(next);
	tail=cur;
}
void delete_at_position()
{
	int pos,c=1;
	printf("Enter position of deletion:\n");
	scanf("%d",&pos);
	next=head;
	while(c<pos)
	{
		prev=next;
		next=next->link;
		c++;
	}
	prev->link=next->link;
	printf("deleted element is %d\n",next->data);
	next->link=NULL;
	free(next);
}
void delete_before_node()
{
	int value;
	printf("Enter before which node we need to delete:\n");
	scanf("%d",&value);
	next=head;
	while(next->link->data!=value)
	{
		prev=next;
		next=next->link;
	}
	prev->link=next->link;
	next->link=NULL;
	printf("Deleted element is %d\n",next->data);
	free(next);
}
void delete_after_node()
{
	int value;
	printf("Enter after which node we need to delete:\n");
	scanf("%d",&value);
	next=head;
	while(next->data!=value)
	{
		prev=next;
		next=next->link;
	}
	cur=next->link;
	next->link=cur->link;
	printf("Deleted element is %d\n",cur->data);
	cur->link=NULL;
	free(cur);
}
void search_an_element()
{
	int value,c=0,flag=0;
	printf("Enter the element which you want to search:\n");
	scanf("%d",&value);
	next=head;
	while(next!=NULL)
	{
		if(next->data==value)
		{
			flag=1;
			break;
		}
		next=next->link;
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
void reverse(struct node *head)
{
	if(head!=NULL)
	{
		reverse(head->link);
		printf("<-%d",head->data);
	}
	else
	{
		printf("NULL");
	}
	
}
void reverse_array()
{
	int a[100];
	int i=0;
	cur=head;
	while(cur!=NULL)
	{
		a[i]=cur->data;
		cur=cur->link;
		i++;
	}
	i-=1;
	printf("NULL");
	while(i>=0)
	{
		printf("<-%d",a[i]);
		i--;
	}
}
void bubblesort()
{
	struct node *p1,*p2;
	int c=0,t;
	p1=head;
	while(p1!=NULL)
	{
		c++;
		p1=p1->link;
	}
	for(int i=0;i<c;i++)
	{
		p2=head;
		while(p2->link!=NULL)
		{
			if(p2->data > p2->link->data)
			{
				t=p2->data;
				p2->data=p2->link->data;
				p2->link->data=t;
			}
			p2=p2->link;
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
		while(p1->link!=last)
		{
			if(p1->data>p1->link->data)
			{
				t=p1->data;
				p1->data=p1->link->data;
				p1->link->data=t;
				c=1;
			}
		p1=p1->link;
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
		printf("PROGRAM FOR SINGLE LINKED LIST\n");
		printf("1. Create a single linked list\n");
		printf("2. Insert at begin\n");
		printf("3. Insert at end\n");
		printf("4. Insert at position\n");
		printf("5. Insert before node\n");
		printf("6. Insert after node\n");
		printf("7. Traversal\n");
		printf("8. Delete at begin\n");
		printf("9. Delete at end\n");
		printf("10. Delete at position\n");
		printf("11. Delete before node\n");
		printf("12. Delete after node\n");
		printf("13. Search an element\n");
		printf("14. Reverse\n");
		printf("15. Reverse array\n");
		printf("16. Bubblesort\n");
		printf("17. sorting\n");
		printf("18. Exit \n");
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
			case 7: traversal();
				break;
			case 8: delete_at_begin();
				break;
			case 9: delete_at_end();
				break;
			case 10: delete_at_position();
				break;
			case 11: delete_before_node();
				break;
			case 12: delete_after_node();
				break;
			case 13: search_an_element();
				break;
			case 14: reverse(head);
				break;
			case 15: reverse_array();
				break;
			case 16: bubblesort();
				break;
			case 17: sorting();
				break;
			case 18: exit(0);
		}
	}
}