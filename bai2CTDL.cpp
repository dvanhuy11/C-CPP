#include <stdio.h>
#include <string.h>
#include <conio.h>
struct book 
{
	char ma[10];
	char name[40];
	float cost;
};
void nhapn(int &n)
{
	printf("NHAP SO LUONG SACH:");
	scanf("%d",&n);
}
void list(book &x)
{
	fflush(stdin);
	printf("\nMA SACH:");
	gets(x.ma);
	printf("\nTEN SACH:");
	gets(x.name);
	printf("\nGIA SACH:");
	scanf("%f",&x.cost);
}
void xuat(book n)
{
	printf(" %s:%s:%.2f ",n.ma,n.name,n.cost);
}
void nhapm(book a[],int n)
{
	for(int i=0;i<n;i++)
		{
			printf("CUON SACH THU %d",i+1);
			list(a[i]);
		}
}
void xuatm(book a[],int n)
{
	for(int i=0;i<n;i++)
	{
		xuat(a[i]);	
		printf("\n");
	}
}
void nhapx(char x[])
{
	fflush(stdin);
	printf("\nNHAP MA SACH CAN TIM =");
	gets(x);
}
int tuantu(book a[],int n,char x[])
{
	int m;
	for(int i=0;i<n;i++)
	{
		m=strcmp(a[i].ma,x);
		if((m==0))
			return i;
	}
	return -1;
}
// CAU A
void sx(book a[],int n)
{
	int k;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			{
				k=strcmp(a[i].ma,a[j].ma);
				if(k>0)
					{
						book t=a[j];
						a[j]=a[i];
						a[i]=t;
					}
			}
}
// CAU B
//void sapxep(SV a[], int n){
//    
//    SV t;
//    for(int i = 0;i < n;++i)
//        for(int j = i+1; j < n;++j)
//            if(a[i].dtb > a[j].dtb)
//			{
//                t = a[i];
//                a[i] = a[j];
//                a[j] = t;
//            }
//}
int nhiphan(book a[],int n,char x[])
{
	sx(a,n);
	int l=0,v;
	int r=n-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		v=strcmp(a[mid].ma,x);
		if(v==0)
			return mid;
		if(v<0)
			l=mid+1;
		else
			r=mid-1;
	}
		return -1;
}
int nhapg(int &g)
{
	printf("\nnhap G=");
	scanf("%d",&g);
	return g;
}
void lk(book a[],int n,int g)
{
	int d=0;
	for(int i=0;i<n;i++)
		if(a[i].cost >g)
		{
			printf("\n");
			xuat(a[i]);
			d++;
		}
	if(d==0)
		printf("0");
}
int max(book a[],int n)
{
	book max;
	int v=a[0].cost;
	for(int i=0;i<n;i++)
		if(a[i].cost>v)
		{
				max=a[i];
				v=a[i].cost;
		}	
	return v;
}
void xuatmax(book a[],int n)
{
	for(int i=0;i<n;i++)
		if(a[i].cost==max(a,n))
		 	xuat(a[i]);
}
int main()
{
	int n,g;
	book a[100];
	char x[20];
	nhapn(n);
	nhapm(a,n);
	xuatm(a,n);
	printf("TIM KIEM TUAN TU");
	nhapx(x);
	printf("\nCUON SACH CO MA LA %s O VI TRI THU %d",x,tuantu(a,n,x));
	printf("\nTIM KIEM NHI PHAN");
	nhapx(x);
	printf("\nCUON SACH CO MA LA %s O VI TRI THU %d",x,nhiphan(a,n,x));
//	printf("\nCAC CUON SACH CO GIA > %d la: ",nhapg(g));
//	lk(a,n,g)
	printf("\nCUON SACH CO GIA TRI LON NHAT=%d\n",max(a,n));
	xuatmax(a,n);
	return 0;
}

