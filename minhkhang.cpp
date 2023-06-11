#include <stdio.h>
#include <string.h>
#include <conio.h>
struct nv
{
	char ms[5];
	char name[30];
	float cost;
};
void nhapn(int &n)
{
	printf("NHAP SO NHAN VIEN:");
	scanf("%d",&n);
}
void list(nv &x)
{
	fflush(stdin);
	printf("\nMA NHAN VIEN:");
	gets(x.ms);
	printf("\nHO TEN NHAN VIEN:");
	gets(x.name);
	printf("\nHE SO LUONG:");
	scanf("%f",&x.cost);
}
void xuat(nv n)
{
	printf(" %s:%s:%.2f ",n.ms,n.name,n.cost);
}
void nhapm(nv a[],int n)
{
	for(int i=0;i<n;i++)
		{
			printf("----------\n");
			printf("NHAN VIEN THU %d",i+1);
			list(a[i]);
		}
}
void xuatm(nv a[],int n)
{
	for(int i=0;i<n;i++)
	{
		xuat(a[i]);	
		printf("\n");
	}
}
void nhapx(char x[20])
{
	fflush(stdin);
	printf("\nNHAP MA SO X=");
	gets(x);
}
//CAU e
void swap(nv &a, nv &b)
{
    nv t = a;
    a = b;
    b = t;
}
//int chia (nv a[], int low, int high)
//{
//    nv danhdau = a[high];   
//    int l = low;
//    int r = high - 1;
//    while(true){
//        while(l <= r && (strcmp(a[l].ms,danhdau)<0)) 
//			l++;
//        while(r >= l && (strcmp(a[r].ms > danhdau)>0))
//			r--;
//        if (l>=r) break;
//        swap(a[l].ms, a[r].ms);
//        l++;
//        r--;
//    }
//    swap(a[l].ms, a[high].ms);
//    return l;
//}
//void quickSort(nv a[], int low, int high)
//{
//    if (low < high)
//    {
//        int pi = chia(a, low, high);
//        quickSort(a, low, pi - 1);
//        quickSort(a, pi + 1, high);
//    }
//    xuatm(a,high+1);
//}
// CAU F
void sx(nv a[],int n)
{
	int k;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			{
				k=strcmp(a[i].ms,a[j].ms);
				if(k>0)
					{
						nv t=a[j];
						a[j]=a[i];
						a[i]=t;
					}
			}
}	
int nhiphan(nv a[],int n)
{
	sx(a,n);
	char x[20];
	nhapx(x);
	int l=0,v;
	int r=n-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		v=strcmp(a[mid].ms,x);
		if(v==0)
			return mid;
		if(v<0)
			l=mid+1;
		else
			r=mid-1;
	}
		return -1;
}
int main()
{
	int n,g;
	FILE *f;
	nv a[100];
	nhapn(n);
	nhapm(a,n);
	xuatm(a,n);
	printf("\nVI TRI NHAN VIEN THEO MA SO %d",nhiphan(a,n));
	printf("\n");
	xuatm(a,n);
//	quickSort(a,0,n-1);
// CAU G
	f=fopen("D:\\CODE\\nv.txt","w");
	fprintf(f,"%d\n",n);
	for(int i=0;i<n;i++)
		{
			fprintf(f,"%s:%s:%.2f",a[i].ms,a[i].name,a[i].cost);
			fprintf(f,"\n");
		}
	fclose(f);
	return 0;
}

