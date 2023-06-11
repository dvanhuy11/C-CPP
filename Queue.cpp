#include<stdio.h>
#include <conio.h>
#include<string.h>
struct benhnhan
{
	char name[20];
	int tuoi;
	int tinhtrang;
};
struct NODE
{
	benhnhan data;
	struct NODE* pnext;
};
struct Queue//tao danh sach
{
	NODE* phead;
	NODE* ptail;
};
void khoitao(Queue &q)
{
	q.phead=NULL;
	q.ptail=NULL;
}
NODE *taonodeQ(benhnhan x)
{
	NODE *p=new NODE;// CAP PHAT VUNG NHO CHO NODE P
	if (p==NULL)
		{
			printf("khong du bo nho de cap phat ");
			return NULL;
		}
	p->data=x;
	p->pnext=NULL;
	return p;
}
bool IsEmpty(Queue q)

{
	if(q.phead==NULL)
		return true;
	else 
		return false;
}

bool Push(Queue &q, NODE *p) // them vao cuoi FIFO
{
	if (IsEmpty(q)==true) // neu danh sach chua co phan tu
			q.phead=q.ptail=p;
	else 
		{
			q.ptail->pnext=p;
			q.ptail=p;
		}
	return true;
}
void xuatinfo(benhnhan x)
{
	printf("%s:%d:%d ",x.name,x.tuoi,x.tinhtrang);
}
void Pop(Queue &q,benhnhan k)// lay 1 gia tri trong NODE
{
	if (IsEmpty(q)==true)
		printf("\nKHONG CO GIA TRI NAO");
	else 
	 {
	 	NODE *p=q.phead;
	 	k=q.phead->data;// gan gia tri vao dau danh sach
	 	q.phead=q.phead->pnext;
	 	delete p;
	 }	
}
bool top(Queue &q,benhnhan x)
{
	if(IsEmpty(q)==true)
		return false;
	x=q.phead->data;
	return true;
}
void nhapthongtin(benhnhan &x)
{
	fflush(stdin);
	printf("\nNHAP HO VA TEN: ");
	gets(x.name);
	printf("NHAP TUOI:");
	scanf("%d",&x.tuoi);
	printf("NHAP TINH TRANG(1/chua kham - 2/da kham):");
	scanf("%d",&x.tinhtrang);
}
void nhapStack(Queue &s,int n)
{
	for(int i=0;i<n;i++)
	{
		benhnhan x;
		printf("\n THONG TIN BENH NHAN THU %d :",i+1);
		nhapthongtin(x);
		NODE *p=taonodeQ(x);
		Push(s,p);	
	}
}
void xuat(Queue &q)
{
	for(NODE *k=q.phead;k!=NULL;k=k->pnext)
		{
			xuatinfo(k->data);
			printf("\n");
		}

}
int demChuakham(Queue &l)
{
	int i=0;
	int check=1;
	for(NODE *k=l.phead;k!=NULL;k=k->pnext)
		if(k->data.tinhtrang==check)
			i++;
	return i;
}
void xuatDakham(Queue &l)
{
	int m,i=0;
	printf("\nNHAP K (k<n) =");
	scanf("%d",&m);
	for(NODE *k=l.phead;k!=NULL;k=k->pnext)
		{
			if(i>m)
				break;
			else
				 if(k->data.tinhtrang==2)
				 	xuatinfo(k->data);
			i++;
		}
	
}
void xuatchuakham(Queue &l)
{
	int i=0;
	for(NODE *k=l.phead;k!=NULL;k=k->pnext)
		{
			if(i>m)
				break;
			else
				 if(k->data.tinhtrang==1)
				 	xuatinfo(k->data);
			i++;
		}
	
}
int main()
{
	Queue s;
	khoitao(s);
	int n;
	printf("NHAP SO LUONG BENH NHAN:");
	scanf("%d",&n);
	nhapStack(s,n);
	printf("\n---XUAT DANH SACH BENH NHAN-----\n");
	xuat(s);
	printf("\nSO LUONG NGUOI CHUA KHAM: %d",demChuakham(s));
	printf("\n--DANH SACH BENH NHAN CHUA KHAM---");
	xuatchuakham(s);
	return 0;
}
