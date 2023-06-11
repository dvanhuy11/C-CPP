#include<stdio.h>
#include<conio.h>
#include<algorithm> //std::__gcd(a,b)
struct PhanSoToanHoc
{
		int tu;
		int mau;
};
typedef struct PhanSoToanHoc ps;
void Nhapps(ps &x)
{
	printf("Nhap tu:");
	scanf("%d",&x.tu);
	do
	{
		printf("Nhap mau:");
		scanf("%d",&x.mau);
		if(x.mau==0)
		{
			printf("Nhap sai, nhap lai!");
		}
	}while(x.mau==0);
} 
void Xuatps(ps x)
{
	printf(" %d / %d",x.tu,x.mau);
}
ps Rutgon(ps x)
{
	int ucln = std::__gcd(x.tu,x.mau);	
	x.tu=x.tu   / ucln;
	x.mau=x.mau / ucln;
	return x;
}
ps Tongps(ps p1, ps p2)
{
	ps z;
	z.tu=p1.tu*p2.mau+p1.mau*p2.tu;
	z.mau=p1.mau*p2.mau;
    Rutgon(z);
    return z;
}
int main()
{
	ps p1, p2;
	Nhapps(p1);
	Nhapps(p2);
	printf("Phan so x :");
	p1=Rutgon(p1); 
	Xuatps(p1); 
	printf("\nPhan so y :");
	p2=Rutgon(p2); 
	Xuatps(p2);
	printf("\nTong hai phan so:");
	Xuatps(Tongps(p1,p2));	getch();
	return 0;
}
