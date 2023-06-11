#include<stdio.h>
#include<math.h>
int dem(int n)
{
	int d=0;
	for (int i=0;i<=n;i++)
		if (i%3==0)
			d++;
	return d;
}
int snt(int x)
{
	if (x<=1)
		return 0;
	for (int j=2;j<=sqrt(x);j++)
		if(x%j==0)
			return 0;
	return 1;
}
///
int main()
{
	int n;
	printf("nhap n=");scanf("%d",&n);
	if (snt(n))
		printf("day la so nguyen to");
	else 
		printf("day khong phai la so nguyen to ");
	printf("\nso luong so nguyen chia het cho 3: %d\n",dem(n));
	return 1;
}