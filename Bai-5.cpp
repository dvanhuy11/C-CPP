#include<stdio.h>
int USCLN(int a,int b)
{
	if(a==b)
		return a;
	else
		if(a>b)
				return USCLN(a-b,b);
		if(a<b)
				return USCLN(b-a,a);
}

int main()
{
	int n;
	int a,b;
	printf("Nhap 2 so nguyen a va b : ");
	scanf("%d%d",&a,&b);
	printf("Uoc so chung lon nhat cua hai so a va b la : %d",USCLN(a,b));
}
