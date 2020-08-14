#include<stdio.h>
int linear_search(int n,int a[50],int target)
{
	int i,pos;
	for(i=0;i<n;i++)
	{
		if(a[i]==target)
		{
			pos=i;
			break;
		}
	}
	if(pos!=-1)
	{
		return pos;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int i,pos,n,target,a[50];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&target);
	pos = linear_search(n,a,target);
	if(pos == -1)
	{
		printf("element not present");
	}
	else
	{
		printf("element present at %d location",pos+1);
	}
}
