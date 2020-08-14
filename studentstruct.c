#include<stdio.h>
struct student
{
	char roll[15];
	char name[20];
	int m[4];
};
int main()
{
	struct student s[40];
	int n,i,j;
	float avg,sum;
	char grade;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		sum=0;
		scanf("%s", s[i].roll);
		scanf("%s", s[i].name);
		for(j=0;j<4;j++)
		{
			scanf("%d",&s[i].m[j]);
			sum=sum+s[i].m[j];
		}
		avg = sum/4.0;
		if(avg >= 50)
			grade = 'A';
		else
			grade = 'B';
	}
	for(i=0;i<n;i++)
	{
		printf("roll = %s name = %s grade = %c\n",s[i].roll,s[i].name,grade);
	}
}