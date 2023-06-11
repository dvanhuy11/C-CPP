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
		xuatps(*(a+i));
}
ps max(ps *a, int n)
{
	ps max;
	int i=0;
	float v=(float)(*(a+i)).tu / (*(a+i)).mau;
	for(i=1; i<n; i++)
		if((float) (*(a+i)).tu/ (*(a+i)).mau > v)
		{
			max=*(a+i);
			v=(float) (*(a+i)).tu/(*(a+i)).mau;
		}
	return max;
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
//
//ps ss(ps p1, ps p2)
//{
//	float k=(float)p2.tu/ p2.mau;
//	if(p1.tu / p1.mau >k)
//		return p1;
//	if(p1.tu / p1.mau <k)
//		return k;
//	if(p1.tu/ p1.mau ==k)
//		return p1;
//}
ps intersort(ps *a,int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			{
				float k=(float)(*(a+j)).tu/ (*(a+j)).mau;
				if((float) (*(a+i)).tu/ (*(a+i)).mau > k)
				{
					ps t=*(a+j);
					*(a+j)=*(a+i);
					*(a+i)=t;
				}
			}
	xuatmang(a,n);
}
ps tongdq(ps *a,int n)
{
	if(n==1)
		return (*(a+0));
	else 
		return  tong2PhanSo(tongdq(a,n-1),*(a+(n-1)));
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
//	printf("\nCAC PHAN SO SAU KHI RUT GON LA:");
//	rutgon(xuatmang(a,n));
	printf("\nTONG CAC PHAN SO:");
	xuatps(rutgon(tongPhanSo(a,n)));
	printf("\nTONG BANG DE QUY:");
	xuatps(rutgon(tongdq(a,n)));
	printf("\nBUBBLE SORT");
	intersort(a,n);
	free(a);
}


