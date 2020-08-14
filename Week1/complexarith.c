#include<stdio.h>
struct complex
{
	int real,imag;
}c1,c2,c3;
struct complex add(struct complex s1, struct complex s2)
{
	struct complex s3;
	s3.real = s1.real + s2.real;
	s3.imag = s1.imag + s2.imag;
	return s3;
}
struct complex sub(struct complex s1, struct complex s2)
{
	struct complex s3;
	s3.real = s1.real - s2.real;
	s3.imag = s1.imag - s2.imag;
	return s3;
}
struct complex mul(struct complex s1, struct complex s2)
{
	struct complex s3;
	s3.real = (s1.real*s2.real)-(s1.imag*s2.imag);
	s3.imag = (s1.real*s2.imag)+(s2.real*s1.imag);
	return s3;
}
int main()
{
	scanf("%d%d", &c1.real, &c1.imag);
	scanf("%d%d", &c2.real, &c2.imag);
	c3=add(c1,c2);
	printf("add = %d+i%d\n",c3.real,c3.imag);
	c3=sub(c1,c2);
	printf("sub = %d+i%d\n",c3.real,c3.imag);
	c3=mul(c1,c2);
	printf("mul = %d+i%d\n",c3.real,c3.imag);
}