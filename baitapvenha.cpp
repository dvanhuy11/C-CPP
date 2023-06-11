#include <stdio.h>
#include <math.h>
int snt(int x)
{
	if (x<=1)
		return 0;
	for (int j=2;j<=sqrt(x);j++)
		if(x%j==0)
			return 0;
	return 1;
}
// CAU A
int demnt(int x)
{
	int dem=0;
	for(int i=1;i<x;i++)
		if(snt(i))
			dem++;
	return dem;
}
// CAU B
long tongcs(int x)
{
	int sum=0,t;
	while(x%10!=0)
	{
		t=x %10;
		sum+=t;
		x=x/10;
	}
	return sum;
}
// CAU C
int min(int x)
{
	int minnt=x;
	for(int i=x;i<100;i++)
		if((snt(i)) && (i>minnt))
		{
			minnt=i;
			break;
		}
	return minnt;
}
int minN(int x)
{
	int minN=0;
	if (min(x)>x)
		minN=min(x);
	return minN;
}
int main()
{
	int n;
	printf("NHAP N:");
	scanf("%d",&n);
	printf("\n CO %d SO NGUYEN TO TU 1 TOI %d",demnt(n),n);
	printf("\n TONG CAC CHU SO CO TRONG %d la: %d",n,tongcs(n));
	printf("\n SO NGUYEN TO NHO NHAT LON HON %d la: %d",n,minN(n));
	return 0;
}

