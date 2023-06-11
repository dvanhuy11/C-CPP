#include<stdio.h>
void nhapn(int &n)
{
	do 
	{
		printf("nhap n=");
		scanf("%d",&n);
	}while(n<0 || n>100);
}
void nhapmang(int b[],int x)
{
	for(int i=0;i<x;i++)
		{
			printf("b[%d]",i);
			scanf("%d",&b[i]);
		}
}
void xuatmang(int b[],int x)
{
	for(int i=0;i<x;i++)
		printf(" %d ",b[i]);
}
int Max(int b[], int n)
{
	if (n == 0)
		return -1;
	if (n == 1)
		return b[0];
	else
	{
		if (b[n - 1] > Max(b, n - 1))
			return b[n - 1];
		else
			return Max(b, n - 1);
	}
}
int dem(int b[],int i)
{
	i--;
    if(i==(0)) return 0;
    else
    {
        if(b[i]%2==0) 
			return 
				1+dem(b, i);
        else 
			return dem(b, i);
    }
}
int main()
{
	int n,b[100];
	nhapn(n);
	nhapmang(b,n);
	xuatmang(b,n);
	printf("\n GIA TRI LON NHAT TRONG MANG LA:%d",Max(b,n));
	printf("\n SO LUONG PHAN TU CHAN TRONG MANG LA:%d",dem(b,n));
	return 0;
}
