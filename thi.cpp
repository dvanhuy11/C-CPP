#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
struct ps
{
	int tu;
	int mau;
};
void nhapn(int &n)
{
	do 
	{
		printf("nhap n=");
		scanf("%d",&n);
	}while(n<0 || n>100);
}
void xuatps(ps p)
{
	printf(" %d/%d",p.tu,p.mau);	
}
void random(ps *a,int n)
{
    srand(time(NULL));
    int min=10;
    int max=99;
    for (int i=0;i<n;i++)
    	{
    		(*(a+i)).tu=min+rand()%(max-min+1);
    		(*(a+i)).mau=rand()%(max-min+1);
		}
}
void xuatmang(ps *a,int x)
{
	for(int i=0; i<x; i++)
		printf("%d / %d\n",(*(a+i)).tu,(*(a+i)).mau);
}
ps tong2PhanSo(ps p1, ps p2)
{
	ps tong;
	tong.mau=p1.mau *p2.mau;
	tong.tu = p1.tu*p2.mau + p2.tu*p1.mau;
	return tong;
}
ps tongPhanSo(ps *p, int n)
{
	ps tong;
	tong.tu=0;
	tong.mau=1;
	for(int i=0; i<n; i++)
	{
		tong=tong2PhanSo(*(p+i),tong);
	}
	return tong;
}
int UCLN(int a, int b)
{
	a=abs(a);
	b=abs(b);
	while(a!=b)
	{
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}	
	return a;
}
ps rutgon(ps p)
{
	int uc=UCLN(p.tu,p.mau);
	p.tu=p.tu/uc;
	p.mau=p.mau/uc;
	return p;
}
ps ps1(ps *a,int n)
{
	
	for(int i=0;i<n;i++)
		if((*(a+i)).tu/ (*(a+i)).mau > 1)
			xuatps(*(a+i));
	
}
bool sosanh(ps *p1,ps *p2)
{
	if(p1>p2)
		return true;
	else 
		return false;
}
ps bubblesort(ps *a,int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if((*(a+i)).tu/ (*(a+i)).mau)>(*(a+j)).tu/ (*(a+j)).mau)
				{
					ps t=*(a+j);
					*(a+j)=*(a+i);
					*(a+i)=t;
				}
	xuatmang(a,n);
}
int tongdq(ps *a,int n)
{
	if(n==1)
		return *(a+0);
	else 
		return tongdq(a,n-1)+(*(a+(n-1)));
	return tongdq(a,n-1);
}
int main()
{
	struct ps *a;
	int n;
	a = (struct ps*) malloc(n * sizeof(struct ps));
	nhapn(n);
	random(a,n);
	printf("\nXUAT MANG:");
	xuatmang(a,n);
	printf("\nCAC PHAN SO CO GIA TRI LON HON 1:");
	ps1(a,n);
	printf("\nCAC PHAN SO SAU KHI RUT GON LA:");
	rutgon(xuatmang(a,n));
	printf("\nTONG CAC PHAN SO:");
	xuatps(rutgon(tongPhanSo(a,n)));
	printf("\nTONG BANG DE QUY");
	rutgon(tongdq(a,n));
	printf("\nBUBBLE SORT");
	bubblesort(a,n);
	printf("\n");
	free(a);
}


