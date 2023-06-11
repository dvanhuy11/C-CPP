#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct BenhNhan{
	int stt;
	char tenBN[40];
	int tuoi;
};
struct queue{
	BenhNhan info;
	struct queue* next;
};
void addBN(BenhNhan &s)
{
	fflush(stdin);
	printf("\n nhap ho ten:");
	gets(s.tenBN);
	printf("\n nhap tuoi:");
	scanf("%d",&s.tuoi);
}
void showBN(BenhNhan s)
{
	printf("\n STT: %d - HoTen: %s - tuoi: %d",s.stt,s.tenBN,s.tuoi);
}
queue* createNode(BenhNhan x)
{
	queue* t;
	t=(queue*)malloc(sizeof(struct queue));
	t->info=x;
	t->next=NULL;
	return t;
}
queue* insert(queue* &p,BenhNhan x)
{
	queue *t=createNode(x);
	if(p==NULL)
	{
		p=t;
		return 0;
	}
	queue* i=p;
	while(i->next!=NULL)
		i=i->next;
	i->next=t;
}
void addQueue(queue* &p)
{
	int n;
	printf("\n nhap so luong benh nhan:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		BenhNhan s;
		s.stt=i+1;
		printf("\nBENH NHAN THU %d",i+1);
		addBN(s);
		insert(p,s);
	}
}
queue* remove(queue* &p)
{
	if (p==NULL)
		return NULL;
	queue* t=p;
	p=p->next;
	return t;
}
void showList(queue* p)
{
	queue* i=p;
	while(i!=NULL)
	{
		showBN(i->info);
		i=i->next;
	}
}
int count(queue* p)
{
	int c=0;
	queue* i=p;
	while(i!=NULL)
	{
		c++;
		i=i->next;
	}
	return c;
}
void add1(queue* &p)
{
	printf("\n---THEM BENH NHAN VAO QUEUE-----");
	BenhNhan s;
	s.stt=count(p)+1;
	addBN(s);
	insert(p,s);
}
void showBNnext(queue *p)
{
	if(p!=NULL)
	{
		printf("\nBENH NHAN TIEP THEO SE KHAM LA:");
		showBN(p->info);
		printf("\n");
	}
	else 
		printf("\n ds rong");
}
int main()
{
	queue*p=NULL;
	queue* q=NULL;
	addQueue(p);
	printf("\n DANH SACH BENH NHAN");
	showList(p);
	add1(p);
	printf("\n DANH SACH SAU KHI THEM\n");
	showList(p);
	while(p!=NULL)
	{
		showBNnext(p);
		insert(q,remove(p)->info);
		printf("\n >>>>SO BEN NHAN CHUA KHAM:%d",count(p));
		showList(p);
		printf("\n----DANH SACH BEN NHAN DA KHAM LA------");
		showList(q);
	}
	return 0;
}
