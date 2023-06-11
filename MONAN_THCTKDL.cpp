#include<stdio.h>
#include <string.h>
#include <conio.h>
struct monan
{
	int mamonan;
	char name[30];
	int cost;
};
struct NODE
{
	monan data;
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
void nhap(monan &x)
{
	printf("\nNHAP MA MON AN:");
	scanf("%d",&x.mamonan);
	printf("NHAP TEN MON AN: ");
	fflush(stdin);
	gets(x.name);
	printf("NHAP GIA:");
	scanf("%d",&x.cost);
}
NODE *taonode(monan x)
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
void xuatinfo(monan x)
{
	printf(" %d:%s:%d ",x.mamonan,x.name,x.cost);
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
void interchangeSort(LIST l)
{
	for(NODE *i=l.phead;i!=NULL;i=i->pnext)
 		 for(NODE *j=i->pnext;j!=NULL;j=j->pnext)
 		 		if(i->data.mamonan < j->data.mamonan)
 		 			{
 		 				monan t=i->data;
 		 				i->data=j->data;
 		 				j->data=t;
					}
	xuat(l);
}
void interchangeSorttang(LIST l)
{
	for(NODE *i=l.phead;i!=NULL;i=i->pnext)
 		 for(NODE *j=i->pnext;j!=NULL;j=j->pnext)
 		 		if(i->data.cost > j->data.cost)
				  	{
 		 				monan t=i->data;
 		 				i->data=j->data;
 		 				j->data=t;
					}
}
void giathapnhat(LIST l)
{
	interchangeSorttang(l);
	int i=0;
	for(NODE *k=l.phead;k!=NULL;k=k->pnext)
		if(i<2)
		{
			printf("\n");
			
			xuatinfo(k->data);
			i++;
		}
}
int main()
{
	LIST l;
	khoitao(l);
	int n;
	printf("Nhap so luong mon an:");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	
		{
			monan x;
			printf("\nNHAP THONG TIN MON AN  THU %d:",i);
			nhap(x);
			NODE *p=taonode(x);
			insertLast(l,p);
		}
	printf("\n--DANH SACH MON AN----");
	printf("\n");
	xuat(l);
	printf("\n--THONG TIN MON AN GIAM DAN THEO MA----\n");
	interchangeSort(l);
	printf("\nXUAT THONG TIN 2 MON AN CO GIA THAP NHAT----");
	giathapnhat(l);
	return 0;
}
