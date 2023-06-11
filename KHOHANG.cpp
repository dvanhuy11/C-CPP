#include<stdio.h>
#include <string.h>
#include <conio.h>
struct KHOHANG
{
	char Mahang[20];
	char name[20];
	int soluongtonkho;
	int cost;
};
struct NODE
{
	KHOHANG data;
	struct NODE* pnext;
};
struct LIST
{
	NODE* phead;
	NODE* ptail;
};
void khoitao(LIST &l)
{
	l.phead=NULL;
	l.ptail=NULL;
}
void nhap(KHOHANG &x)
{
	fflush(stdin);
	printf("\nNHAP MA HANG:");
	gets(x.Mahang);
	printf("NHAP TEN HANG: ");
	gets(x.name);
	printf("NHAP SO LUONG TON KHO:");
	scanf("%d",&x.soluongtonkho);
	printf("NHAP DON GIA:");
	scanf("%d",&x.cost);
}
NODE *taonode(KHOHANG x)
{
	NODE *p=new NODE;
	if (p==NULL)
		{
			printf("khong du bo nho de cap phat ");
			return NULL;
		}
	p->data=x;
	p->pnext=NULL;
	return p;
}
void xuatinfo(KHOHANG x)
{
	printf(" %s : %s : %d : %d ",x.Mahang,x.name,x.soluongtonkho,x.cost);
}
void insertLast(LIST &l,NODE *p)
{
	if(l.ptail== NULL)
		l.phead=l.ptail=p;
	else 
		{
			l.ptail->pnext=p;
			l.ptail=p;  
		}
}
void xuat(LIST l)
{
	for(NODE *k=l.phead;k!=NULL;k=k->pnext)
		{
			xuatinfo(k->data);
			printf("\n");
		}
}
void SOLUONGTONBE10(LIST l)
{
	for(NODE *k=l.phead;k!=NULL;k=k->pnext)
		if(k->data.soluongtonkho < 10)
			{
				xuatinfo(k->data);
				printf("\n");
			}
}
void deleteFirt(LIST l)
{
	if(l.phead==NULL)
		printf("DANH SACH RONG");
	l.phead=l.phead->pnext;
	xuat(l);
}
void deleteLast(LIST l)
{
	for(NODE *i=l.phead;i!=NULL;i=i->pnext)
		if(i->pnext==l.ptail)
		 	{
		 		i->pnext=NULL;
		 		l.ptail=i;
		  }
	xuat(l);
}
void DeleteX(LIST l)
{
	KHOHANG x;
	printf("\nNHAP MAT HANG CO MA LA X:");
	fflush(stdin);
	gets(x.Mahang);
	NODE *q=taonode(x);
	if(strcmp(l.phead->data.Mahang,x.Mahang)==0)
		deleteFirt(l);
	if(strcmp(l.ptail->data.Mahang,x.Mahang)==0)
		deleteLast(l);
	NODE *danhdau= new NODE;
	for(NODE *i=l.phead;i!=NULL;i=i->pnext)
		{
			if((strcmp(i->data.Mahang,q->data.Mahang))==0)
				{
					danhdau->pnext=i->pnext;
					i=danhdau;
				}
			 	danhdau=i;
		}
	xuat(l);
}
int tong(LIST l)
{
	int sum=0;
	for(NODE *k=l.phead;k!=NULL;k=k->pnext)
		if(k->data.soluongtonkho!=0)
			sum+=k->data.soluongtonkho * k->data.cost;
	return sum;
}
int main()
{
	
	LIST l;
	KHOHANG x;
	khoitao(l);
	int n;
	printf("Nhap so luong hang :");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		{
			printf("\nNHAP THONG TIN HANG THU %d:",i);
			nhap(x);
			NODE *p=taonode(x);
			insertLast(l,p);
		}
	printf("\n--DANH SACH HANG HOA----");
	printf("\n");
	xuat(l);
	printf("\n--DANH SACH MAT HANG CO SO LUONG TON KHO < 10 ----\n");
	SOLUONGTONBE10(l);
	printf("\n--TIM VA XOA THONG TIN MAT HANG CO MA LA X----");
	DeleteX(l);
	printf("\nTONG GIA TIEN CAC MAT HANG TON KHO:%d",tong(l));
	return 0;
}
