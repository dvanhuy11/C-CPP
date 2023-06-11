#include<stdio.h>
#include <string.h>
#include <conio.h>
struct sv
{
	char mssv[20];
	char name[20];
	float diem;
};
struct NODE
{
	sv data;
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
void nhap(sv &x)
{
	fflush(stdin);
	printf("\nNHAP MSSV:");
	gets(x.mssv);
	printf("NHAP HO VA TEN: ");
	gets(x.name);
	printf("NHAP DIEM:");
	scanf("%f",&x.diem);
}
NODE *taonode(sv x)
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
void xuatinfoSV(sv x)
{
	printf(" %s:%s:%.2f ",x.mssv,x.name,x.diem);
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
			xuatinfoSV(k->data);
			printf("\n");
		}
}
void xuatDTB(LIST l)
{
	printf("\n");
	for(NODE *k=l.phead;k!=NULL;k=k->pnext)
		if(k->data.diem>5)
		{
			xuatinfoSV(k->data);
			printf("\n");
		}
}
void check(LIST l)
{
	sv x;
	printf("\nNHAP MA X:");
	fflush(stdin);
	gets(x.mssv);
	for(NODE *k=l.phead;k!=NULL;k=k->pnext)
			if((strcmp(k->data.mssv,x.mssv))==0)
				printf("------->>>%s",k->data.name);
}
void interchangeSort(LIST l)
{
	for(NODE *i=l.phead;i!=NULL;i=i->pnext)
 		 for(NODE *j=i->pnext;j!=NULL;j=j->pnext)
 		 		if(i->data.diem>j->data.diem)
 		 			{
 		 				sv t=i->data;
 		 				i->data=j->data;
 		 				j->data=t;
					}
	xuat(l);
}
void insertAfter(LIST l)
{
	sv x,y;
	printf("\nNHAP SINH VIEN X:");
	fflush(stdin);
	gets(x.mssv);
	NODE *q=taonode(x);
	nhap(y);
	for(NODE *k=l.phead;k!=NULL;k=k->pnext)
		if(strcmp(k->data.mssv,q->data.mssv)==0)
			{
				NODE *p=taonode(y);
				NODE *g=k->pnext;
				p->pnext=g;
				k->pnext=p;
			} // 1 2 3 25
	xuat(l);
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
	sv x;
	printf("\nNHAP MSSV X CAN XOA:");
	fflush(stdin);
	gets(x.mssv);
	NODE *q=taonode(x);
	if(strcmp(l.phead->data.mssv,x.mssv)==0)
		deleteFirt(l);
	if(strcmp(l.ptail->data.mssv,x.mssv)==0)
		deleteLast(l);
	NODE *danhdau= new NODE;
	for(NODE *i=l.phead;i!=NULL;i=i->pnext)
		{
			if((strcmp(i->data.mssv,q->data.mssv))==0)
				{
					danhdau->pnext=i->pnext;
					i=danhdau;
				}
			 	danhdau=i;
		}
	xuat(l);
}
void deleteall(LIST l)
{
	for(NODE *i=l.phead;i!=NULL;i=i->pnext)
				i=i->pnext;
	printf("\n>>>>>>>>>DANH SACH RONG");
}
int main()
{
	
	LIST l;
	sv x;
	khoitao(l);
	int n;
	printf("Nhap so luong SV:");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		{
			printf("\nNHAP THONG TIN SINH VIEN THU %d:",i);
			nhap(x);
			NODE *p=taonode(x);
			insertLast(l,p);
		}
	printf("\n--DANH SACH SINH VIEN----");
	printf("\n");
	xuat(l);
	printf("\n-----------------------");
	printf("\nTHONG TIN SINH VIEN CO DIEM TRUNG BINH >5:");
	xuatDTB(l);
	printf("\n-----------------------");
	printf("\nSINH VIEN CO MA LA X:");
	check(l);
	printf("\n-----------------------");
	printf("\nSAP XEP TANG DAN THEO DIEM TRUNG BINH: \n");
	interchangeSort(l);
	printf("\n-----------------------");
	printf("\nTHEM VAO SAU SINH VIEN X");
	insertAfter(l);
	printf("\n-------");
	printf("\nXOA DAU DANH SACH\n");
	deleteFirt(l);
	printf("\n-------");
	printf("\nXOA CUOI DANH SACH\n");
	deleteLast(l);
	printf("\n-----------------------");
	printf("\nXOA SINH VIEN CO MA LA X");
	DeleteX(l);
	printf("\n-----------------------");
	printf("\nXOA DANH SACH SINH VIEN");
	deleteall(l);
	return 0;
}
