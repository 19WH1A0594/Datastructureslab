#include<stdio.h>
int linear_search(int n,int a[50], int target)
{
	static int i=0;
	if(a[i]==target)
	{
		return i;
	}
	else if(i < n)
	{
		i++;
		linear_search(n,a,target);
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