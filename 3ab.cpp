#include<stdio.h>
#include<string.h> 
#include"dssv.h"
int main()
{
	node* p=NULL;
	int n;
	sv a;
	printf("\nNhap so sinh vien: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\nNhap thong tin sinh vien thu %d\n",i+1);
		printf("Nhap MaSV: ");
		scanf("%d",&a.masv);
		printf("Nhap ho va ten: ");
		fflush(stdin);
		gets(a.hoten);
		do
		{
			printf("Nhap diem trung binh: ");
			scanf("%f",&a.dtb);	
		}	
		while(a.dtb<0||a.dtb>10);
		insert(p,a);
	}
	printf("\nDanh sach sinh vien trong cay: "); 
	NLR(p);
	char y[10];
	printf("\nNhap ten sinh vien can tim: ");
	fflush(stdin); gets(y);	
	node* t;
	t=timsvY(p,y); 
	if(t!=NULL)
	{
		printf("\nTim thay! ",t->info);
	}
	else
	{
		printf("\nKhong tim thay! ");	
    }
	return 0; 
}
