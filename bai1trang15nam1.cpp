#include <stdio.h>
#define MAX 100;
//CAU A
void nhapn(int &n)
{
	do 
	{
		printf("nhap n=");
		scanf("%d",&n);
	}while(n<0 || n>100);
}
void nhapmang(int a[],int x)
{
	for(int i=0;i<x;i++)
		{
			printf("a[%d]",i);
			scanf("%d",&a[i]);
		}
}
//CAU B
void xuatmang(int a[],int x)
{
	for(int i=0;i<x;i++)
		printf(" %d ",a[i]);
}
//CAU C ( TIM VI TRI VA GIA TRI CUA PHAN TU DUONG DAU TIEN )
void fist(int a[],int x)
{
	int vitri,gt;
	for(int i=0;i<x;i++)
		if (a[i]>0)
			{
				vitri=i;
				gt=a[i];
				break;
			}
	printf("\n vi tri cua phan tu duong dau tien: i=%d \n",vitri);
	printf("gia tri cua phan tu duong dau tien: %d\n",gt);
}
//CAU D ( TIM VI TRI VA GIA TRI CUA PHAN TU DUONG CUOI CUNG )
void last(int a[],int x)
{
	int vt1,gt1;
	for(int i=x-1;i>=0;i--)
		if (a[i]>0)	
			{
				vt1=i;
				gt1=a[i];
				break;
			}
	printf("\nvi tri cua phan tu duong cuoi cung : i=%d\n",vt1);
	printf("gia tri cua phan tu duong cuoi cung : %d\n",gt1);
}

//CAU E ( TIM GIA TRI LON NHAT TRONG MANG )
int gtln(int a[],int x)
{
	int max=a[0];
	for(int i=1;i<x;i++)
		if (a[i]>max)
				max=a[i];
	return max;
}
// CAU F ( XUAT SO LUONG CAC GIA TRI LON NHAT)
int dem(int a[],int x )
{
	int demmax=0;
	for(int i=0;i<x;i++)	
		if (a[i]==gtln(a,x))
			demmax++;
	return demmax;
}
// CAU G ( XUAT VI TRI CAC GIA TRI LON NHAT)
void xuatmax(int a[],int l)
{
	int j=0;
	int b[100];
	for(int k=0;k<l;k++)	
		if(a[k]==gtln(a,l))
			printf(" %d ",k);
}	
// CAU H ( THEM 1 PHAN TU MOI VAO DAU MANG ), 
void nhapai(int &h)
{
	printf(" \n nhap gia tri can hien thi= ");
	scanf("%d",&h);
}
void nhapgt(int &x)
{
	printf("\n nhap vi tri tuong tac= ");
	scanf("%d",&x);	
}
// CAU H ( CHEN VAO DAU MANG )
void addf(int a[],int x,int k) 
{
	nhapai(k);
	for(int i=x;i>=1;i--)
  		{
   			a[i]=a[i-1]; 
 	    }
 	a[0]=k; 
 	x++;
 	printf("\nMANG SAU KHI THEM PHAN TU VAO DAU MANG: ");	
 	xuatmang(a,x); 
}
// CAU J ( XOA PHAN TU DAU TIEN )
void xoaf(int a[],int x)
{
	for(int i=0;i<x;i++)
  		{
   			a[i]=a[i+1];
 	    }
 	printf("\nMANG SAU KHI XOA PHAN TU TAI DAU MANG: ");	
 	xuatmang(a,x); 
}
// CAU I ( CHEN VAO VI TRI K );
void chen(int a[],int n,int k,int x)
{
 nhapai(x);
 do
 	{
 		nhapgt(k);
	}while (k<0 || k >=n);
 for(int i=n;i>=k;i--)
 		a[i]=a[i-1]; 
 a[k]=x;
 n++; 
 /* neu nhap n bang 5 thi
 1 2 3 4 6
 phai n++ de len n=6 thi moi chen duoc */
 printf("\n MANG SAU KHI THEM PHAN TU VAO VI TRI i=%d: ",k);
 xuatmang(a,n);
}
// CAU K ( XOA PHAN TU TAI VI TRI K )
void xoa(int a[],int n,int k)
{
 do
 	{
 		nhapgt(k);
	}while (k<0 || k >=n);
 for(int i=k;i<=n;i++) //
 		a[i]=a[i+1];
 printf("\n MANG SAU KHI XOA TAI VI TRI i=%d: ",k);
 xuatmang(a,n);
}
// CAU L (KIEM TRA SO LE )
void le(int a[], int x)
{
	int r=0;
	for(int i=0;i<x;i++)
		if (a[i] %2 ==0)
			r++;
	if (r ==0)
		printf("\n MANG KHONG CHUA SO LE");
	else 
		printf("\n MANG CHUA SO LE");
		
}
int main()
{
	int n,k,x;
	int a[1000];
	nhapn(n);
	nhapmang(a,n);
	printf("------MANG SAU KHI NHAP--------: ");
	xuatmang(a,n);
	printf("\n-------VI TRI CUA PHAN TU DUONG DAU TIEN------------\n");
	fist(a,n);
	printf("\n-------VI TRI CUA PHAN TU DUONG CUOI CUNG------------\n");
	last(a,n);
	printf("\n gia tri lon nhat trong mang la: %d \n",gtln(a,n));
	printf(" so luong phan tu lon nhat: %d \n",dem(a,n));
	printf("----------VI TRI CAC PHAN TU LON NHAT-------\n");
	printf("cac vi tri cua gia tri lon nhat : ");
	xuatmax(a,n);
	printf("\n-----THEM PHAN TU VAO DAU MANG-------\n");
	addf(a,n,k);
	xoaf(a,n);
	printf("\n ------THEM PHAN TU VAO VI TRI K------");
	chen(a,n,k,x);
	xoa(a,n,k);
	printf("\n");
	le(a,n);
	return 0;
}

