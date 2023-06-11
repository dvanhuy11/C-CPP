#include<stdio.h>
struct sv
{
	int mssv;
	char name[20];
	float diem;
};
struct node
{
	sv data; 
	struct node *pLeft; 
	struct node *pRight; 
};
typedef struct node NODE;
typedef NODE* TREE;
void KhoiTaoCay(TREE &t)
{
	t = NULL; 
}
void Duyet_NLR(TREE t)
{ 
	if (t != NULL)
	{
		printf(" \t%d ",t->data);
		Duyet_NLR(t->pLeft); 
		Duyet_NLR(t->pRight);
	}
}
int dosau(TREE t,int &max,int ds)
{
	if(t==NULL)
		return max;
	if(ds>max)
		max=ds;
	ds++;
	dosau(t->pLeft,max,ds);
	dosau(t->pRight,max,ds);
	return max;
}
int bf(TREE t)
{
	int max=0;
	int max2=0;
	int ds=0;
	int ds2=0;
	return dosau(t->pLeft,max,ds)-dosau(t->pRight,max2,ds2);
}
node *xoaytrai(TREE t)
{
	//TH1: khong xoay duoc thi T rong 
	if(t==NULL)
		return NULL;
	//TH2: khong xoay duoc do nut p khong co con phai
	if(t->pRight==NULL)
		return NULL;
	//TH3 :xoay duoc 
	node *pivot=t->pRight;
	t->pRight=pivot->pLeft;
	pivot->pLeft=t;
	return pivot;
}
node *xoayphai(TREE t)
{
	if(t==NULL)
		return NULL;
	if(t->pLeft==NULL)
		return NULL;
	node *pivot=t->pLeft;
	t->pLeft=pivot->pRight;
	pivot->pRight=t;
	return pivot;			
}
node *canbang(TREE t )
{
	if(bf(t)<-1)
	{
	// lech phai xoay trao
		if(bf(t->pRight)>0) // nhanh ben phai lech trai
			t->pRight=xoayphai(t->pRight);//xoau phai voi nhanh ben phai
	t=xoaytrai(t);
    }
	else if(bf(t)>1){// lech trai ->> xoay phai
			if(bf(t->pLeft)<0)
				t->pLeft=xoaytrai(t->pLeft);
	t=xoayphai(t);
	}
	return t;	
}
void timNodethemang(TREE &x, TREE &y)
{
	if(y->pLeft!=NULL)
	{
		timNodethemang(x,y->pLeft);
	}
	else
	{
		x->data=y->data;
		x=y;
		y=y->pRight;
	}
}
void ThemNodeVaoCay(TREE &t, sv x)
{
	if (t == NULL)
	{
		NODE *p = new NODE; 
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else 
 	{
		
		if (t->data.mssv> x.mssv)
			ThemNodeVaoCay(t->pLeft, x);  
		else if (t->data.mssv < x.mssv) 
			ThemNodeVaoCay(t->pRight, x); 
	}
	t=canbang(t);
}
void nhap(sv &x)
{
	fflush(stdin);
	printf("\nNHAP MSSV:");
	scanf("%d",x.mssv);
	printf("NHAP HO VA TEN: ");
	gets(x.name);
	printf("NHAP DIEM:");
	scanf("%f",&x.diem);
}
void remove(TREE &t,sv x)
{
	if(t==NULL)
	{
		return ;
	}
	else
	{
		if(x.mssv < t->data.mssv)
		{
			remove(t->pLeft,x);
		}
		else if(x.mssv > t->data.mssv)
		{
			remove(t->pRight,x);
		}
		else
		{
			node* p=t;
			if(t->pLeft==NULL)
			{
				t=t->pRight;
			}
			else if(t->pRight==NULL)
			{
				t=t->pLeft;
			}
			else
			{
				timNodethemang(p,t->pRight);
			}
			delete p;
		}
	}
	if(t==NULL)	
		return ;
	else 
		t=canbang(t);
}
void xuatinfoSV(sv x)
{
	printf(" %s:%s:%.2f ",x.mssv,x.name,x.diem);
}
int main()
{
	TREE t;
	KhoiTaoCay(t);
	sv x;
	int n;
	printf("\nNHAP SINH VIEN CAN THEM VAO CAY:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{

		printf("\nNHAP SINH VIEN %d:",i+1);
		nhap(x);
		ThemNodeVaoCay(t,x);
	}
	printf("\n---DUYET THEO NLR----");
	Duyet_NLR(t);
	return 0;
}
