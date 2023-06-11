#include<stdio.h>
struct NODE
{
	int data;
	struct NODE* pnext;
};
struct LIST//tao danh sach
{
	NODE* phead;
	NODE* ptail;
};
void khoitao(LIST &l)
{
	l.phead=NULL;
	l.ptail=NULL;
}
NODE *taonode(int x)
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
void insertDau(LIST &l, NODE *p)
{
	if(l.phead==NULL)
		{
		 	l.phead=l.ptail=p;// not dau cung chinh la not cuoi
		}
	else
		{
			p->pnext=l.phead;
			l.phead=p; 	
		} 
}
void insertCuoi(LIST &l,NODE *p)
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
		printf(" %d ",k->data);
}
int max(LIST l)
{
	int max=l.phead->data;
	for(NODE *k=l.phead->pnext;k!=NULL;k=k->pnext)
			if (k->data>max)
				max =k->data;
	return max;
}
int min(LIST l)
{
	int min=l.phead->data;
	for(NODE *k=l.phead->pnext;k!=NULL;k=k->pnext)
			if (k->data<min)
				min=k->data;
	return min;
}
int countNode(LIST l)
{
	int d=0;
	for(NODE *k=l.phead;k!=NULL;k=k->pnext)
		d++;
	return d;
}
int nhap(int &x)
{
	printf("\nNHAP GIA TRI CAN TIM:");scanf("%d",&x);
}
void insertAfter(LIST l)
{
	int x,b;
	nhap(x);
	NODE *q=taonode(x);
	printf("\nNHAP GIA TRI CAN THEM:");
		scanf("%d",&b);
	for(NODE *k=l.phead;k!=NULL;k=k->pnext)
		if(k->data==q->data)
			{
				NODE *p=taonode(b);
				NODE *g=k->pnext;
				p->pnext=g;
				k->pnext=p;
			} // 1 2 3 25
	xuat(l);
}
void insertBefore(LIST l)
{
	int x,b;
	nhap(x);
	NODE *q=taonode(x);
	printf("\nNHAP GIA TRI CAN THEM:");
		scanf("%d",&b);
	NODE *g=new NODE;//// g=0;
	for(NODE *k=l.phead;k!=NULL;k=k->pnext)
	{
		if(k->data==q->data)
			{
				NODE *p=taonode(b);
				p->pnext=k;
				g->pnext=p;
			} 
		g=k;/// danh dau sau moi lan duyet, giu moi lien ket giua not k va not sau no'
	}
	xuat(l);
}
int check(LIST l)
{
	int vt,check=1;
	printf("\nNHAP VI TRI K:");
	scanf("%d",&vt);
	for(NODE *k=l.phead;k!=NULL;k=k->pnext)
		{
			if(check==vt)
				return k->data;
			else 
				check++;
		}
}
void InterchangeSort(LIST l)
{
 	for(NODE *i=l.phead;i!=NULL;i=i->pnext)
 		 for(NODE *j=i->pnext;j!=NULL;j=j->pnext)
   			 if((j->data)<(i->data)) 
    			 {
     				  int t=i->data;
     				  i->data=j->data;
      				  j->data=t;
   				  }
   	xuat(l);
}
void deleteFirt(LIST l)
{
	NODE *p=l.phead;
	l.phead=l.phead->pnext;
	delete p;
}
void deleteLast(LIST l)
{
	for(NODE *i=l.phead;i!=NULL;i=i->pnext)
		if(i->pnext==l.ptail)
		 	{
		 		delete l.ptail;
		 		i->pnext=NULL;
		 		l.ptail=i;
			 }
}
void Delete(LIST l)// xoa sau khoa K
{
	int x;
	printf("\nNHAP GIA TRI CAN XOA:");
	scanf("%d",&x);
	if(l.phead->data==x)
		deleteFirt(l);
	if(l.ptail->data==x)
		deleteLast(l);
	NODE *k=taonode(x);
	NODE *danhdau=new NODE;
	for(NODE *i=l.phead;i!=NULL;i=i->pnext)
		{
			if(i->data==k->data)
				{
					NODE *danhdau=i->pnext;
					i->pnext=danhdau->pnext;
					delete danhdau;
				}
			danhdau=i;
		}
	xuat(l);
}
int main()
{
	LIST l;
	khoitao(l);
	int n;
	printf("Nhap so luong node can them:");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		{
			int x;
			printf("nhap gia tri X:");
			scanf("%d",&x);
			NODE *p=taonode(x);
		//	insertDau(l,p);
			insertCuoi(l,p);
		}
	printf("\nDANH SACH LIEN KET DON");xuat(l);
	printf("\nGIA TRI LON NHAT: %d",max(l));
	printf("\nGIA TRI NHO NHAT: %d",min(l));
	printf("\nSO NODE CO TRONG DANH SACH LA: %d",countNode(l));
	printf("\n----THEM NODE Y VAO SAU NODE X------");
	insertAfter(l);
//	printf("\n----THEM NODE Y VAO TRUOC NODE X------");
//	insertBefore(l);
	//system("pause");
	printf("\nGIA TRI NODE THU K TRONG DANH SACH: %d",check(l));
	printf("\n------INTERCHANGE SORT-----");
	InterchangeSort(l);
	printf("\n------XOA TAI VI TRI KHOA K-----");
	Delete(l);
	return 0;
}
