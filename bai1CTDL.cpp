#include <stdio.h>
#define MAX 100

void NhapSL (int &n)
{
	do{
		printf ("Nhap so phan tu :");
		scanf("%d",&n);
	}while (n<=0 || n> MAX);
}
void NhapMang(int a[], int n)
{
	for(int i= 0; i< n; i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void XuatMang (int a[], int n)
{
	for (int i=0; i<n; i++)
		printf("%5d",a[i]);
}
int TinhTong( int a[], int n)
{
	int tong = 0;
	for (int i=0; i<n;i++)
	{
		tong +=a[i];
	}
	return tong;
}
float  TinhTrungBinhCong(int a[], int n)
{
    int tb=0;
    for (int i=0; i<n; i++)
    {
    	float tb=TinhTong(a,n)/n;
    	return tb;
    }
}
int TimTuyenTinh(int a[], int n, int X)
{
	for (int i = 0; i < n;i++)
		if (a[i] == X)
			return i;
}
void SapXep(int a[], int n)
{
    int tg;
    for(int i = 0; i < n - 1; i++)
	{
    	for(int j = i + 1; j < n; j++)
		{
            if(a[i] > a[j])
			{
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;        
            }
        }
    }   
}
char TimKiem(int A[], int n, int x){
   for(int i = 0; i<n ; i++)
   if(x==A[i])
      return 1;
   return 0;
}
int main()
{
	int n;
	int a[MAX];
	NhapSL(n);
	NhapMang(a,n);
	printf("Mang sau khi nhap:");
	XuatMang(a,n);
	int tong = TinhTong(a,n);
	float tbc = TinhTrungBinhCong(a,n);
	printf("\nTong cac phan tu = %d\n",tong);
	printf("Trung binh cong cac phan tu = %0.3f\n",tbc); 
	int X;
	printf(" Nhap gia tri can tim:");
	scanf("%d",&X);
	int vt = TimTuyenTinh(a,n,X);
	if (vt == -1 )
		printf("Khong tim thay");
	else
		printf("\nTim thay %d tai vi tri %d\n",X,vt);
	SapXep(a,n);
	printf("\nMang sau khi sap tang dan:"); XuatMang(a,n);
	return 0;
}
