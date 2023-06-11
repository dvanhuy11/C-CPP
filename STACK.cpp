#include<stdio.h>
struct NODE 
{
	int data;
	struct NODE *pnext;
};
NODE *taonode(int x)
{
	NODE *p= new NODE;
	if( p==NULL)
	{
		printf("KHONG DU BO NHO");
		return NULL;
	}
	p->data=x;
	p->pnext= NULL;
	return p;
}
struct STACK
{
	NODE *ptop;
};
void TaoStack(STACK &x)
{
	x.ptop=NULL;
}
bool IsEmpty(STACK x)

{
	if(x.ptop==NULL)
		return true;
	else 
		return false;
}
bool Push(STACK &x, NODE *p)// them vao dau
{
	if (IsEmpty(x)==true)
			x.ptop=p;
	else 
		{
			p->pnext=x.ptop;
			x.ptop=p;
		}
	return true;
}
bool Pop(STACK &x,int &k)// lay 1 gia tri dau roi xoa no
{
	if (IsEmpty(x)==true)
		return false;
	else 
	 {
	 	NODE *p=x.ptop;
	 	k=p->data;// gan gia tri vao dau danh sach
	 	x.ptop=x.ptop->pnext;
	 	delete p;
	 }
	return true;
}
bool top(STACK &s,int &x)
{
	if(IsEmpty(s)==true)
		return false;
	x=s.ptop->data;
	return true;
}
void nhapStack(STACK &s,int n)
{
	for(int i=0;i<n;i++)
	{
		int x;
		printf("\n NHAP PHAN TU CAN THEM:");
		scanf("%d",&x);
		NODE *p=taonode(x);
		Push(s,p);	
	}
}
void chuyencoso(STACK &s,int coso,int thapphan)
{
	while(thapphan!=0)
	{
		int x=thapphan % coso;
		NODE *p=taonode(x);
		Push(s,p);
		thapphan /=coso;
	}
}
void xuat(STACK &s)
{
	while(IsEmpty(s)==false)
		{
			int x;
			Pop(s,x);
			printf(" %d ",x);
		}
}
void xuatcoso(STACK &s)
{
	while(IsEmpty(s)==false)
	{
		int x;
		Pop(s,x);
		if (x<10)
			printf("%d",x);
		else 
			if(x==10)
				printf("A");
			else if(x==11)
				printf("B");
			else if(x==12)
				printf("C");
			else if(x==13)
				printf("D");
			else if(x==14)
				printf("E");
			else if(x==15)
				printf("F");
	}
}
int main()
{
	STACK s;
	TaoStack(s);
//	int n;
//	printf("NHAP VAO SO LUONG PHAN TU:");
//	scanf("%d",&n);
//	nhapStack(s,n);
//	xuat(s);
	int thapphan;
	printf("\n NHAP GIA TRI HE THAP PHAN CAN CHUYEN: ");
	scanf("%d",&thapphan);
	int coso;
	printf("\n NHAP GIA TRI CO SO(2,8,16) CAN CHUYEN: ");
	scanf("%d",&coso);
	chuyencoso(s,coso,thapphan);
	printf("\SAU KHI CHUYEN:");
	xuatcoso(s);
}

