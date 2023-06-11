#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
typedef struct
{
	int tu;
	int mau;
}ps;
void taoPhanSo(ps &p)
{
	int min=1;
	int max=20;
	int v;	
	p.tu = min+ rand()%(max-min+1);
	do{		
		v=min+ rand()%(max-min+1);
		if(v!=0)
			p.mau=v;
	}while(v==0);
}
void xuatPhanSo(ps p)
{
	printf(" %d/%d",p.tu,p.mau);	
}
void nhapN(int &n)
{
	do{
		printf("Nhap so luong phan tu:");
		scanf("%d",&n);
	}while(n<=0);
}
void nhapMangPhanSo(ps p[], int n)
{
	srand(time(0));
	for(int i=0; i<n; i++)
	{
	
		taoPhanSo(p[i]);
	}	
}
void xuatMangPhanSo(ps p[], int n)
{
	for(int i=0; i<n; i++)
		xuatPhanSo(p[i]);	
}
ps tong2PhanSo(ps p1, ps p2)
{
	ps tong;
	tong.mau=p1.mau *p2.mau;
	tong.tu = p1.tu*p2.mau + p2.tu*p1.mau;
	return tong;
}
ps tongPhanSo(ps p[], int n)
{
	ps tong;
	tong.tu=0;
	tong.mau=1;
	for(int i=0; i<n; i++)
	{
		tong=tong2PhanSo(p[i],tong);
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
ps rutGonPhanSo(ps p)
{
	int uc=UCLN(p.tu,p.mau);
	p.tu=p.tu/uc;
	p.mau=p.mau/uc;
	return p;
}
ps timMaxPhanSo(ps p[], int n)
{
	ps max;
	float v=(float) p[0].tu/p[0].mau;
	for(int i=1; i<n; i++)
		if((float) p[i].tu/p[i].mau > v)
		{
			max=p[i];
			v=(float) p[i].tu/p[i].mau;
		}
	return max;
}
int main()
{
	int n;
	ps p[20];
	nhapN(n);
	nhapMangPhanSo(p, n);
	printf("Mang phan so:");
	xuatMangPhanSo(p,n);
	printf("\nTong cac phan so:");
	xuatPhanSo(rutGonPhanSo(tongPhanSo(p,n)));
	printf("\nPhan so lon nhat:");
	xuatPhanSo(timMaxPhanSo(p,n));
	return 0;
}




