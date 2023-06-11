#include<stdio.h>
#include<string.h>
struct gv
{
	int magv;
	char name[20];
	int chucdanh;
};
struct node
{
	gv data; 
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
void timNodethemang(TREE &x, TREE &y)
{
	if(y->pLeft!=NULL)
	{
		timNodethemang(x,y->pLeft);
	}
	else
	{
		x->data.magv=y->data.magv;
		x=y;
		y=y->pRight;
	}
}
void remove(TREE &t,gv x)
{
	if(t==NULL)
		return ;
	else
	{
		if(x.magv < t->data.magv) 
			remove(t->pLeft,x);
		else if(x.magv > t->data.magv)
			remove(t->pRight,x);
		else
		{
			node* p=t;
			if(t->pLeft==NULL)
				t=t->pRight;
			else if(t->pRight==NULL)
				t=t->pLeft;
			else
				timNodethemang(p,t->pRight);
			delete p;
		}
	}
}
void ThemNodeVaoCay(TREE &t, gv x)
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
		
		if (t->data.magv > x.magv)
			ThemNodeVaoCay(t->pLeft, x);  
		else if (t->data.magv < x.magv) 
			ThemNodeVaoCay(t->pRight, x); 
	}
}
void nhap(gv &x)
{
	printf("\nNHAP MAGV:");
	scanf("%d",&x.magv);
	printf("NHAP HO VA TEN: ");
	fflush(stdin);
	gets(x.name);
	printf("NHAP CHUC VI (0:TRO GIANG 1:GIANG VIEN 2:GIANG VIEN CHINH) :");
	scanf("%d",&x.chucdanh);
}
void xuatinfoGV(gv x)
{
	printf(" %d : %s : %d ",x.magv,x.name,x.chucdanh);
}
void xuatGVchinh(TREE t)
{
	if (t != NULL)
	{
		if(t->data.chucdanh == 2 )
		{
			xuatinfoGV(t->data);
			printf("\n");
		}
		xuatGVchinh(t->pLeft); 
		xuatGVchinh(t->pRight);
	}	
}
int main()
{
	TREE t;
	KhoiTaoCay(t);
	gv x;
	int n;
	printf("\nNHAP SO GIAP VIEN CAN THEM VAO CAY:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{

		printf("\nNHAP GIAO VIEN %d:",i+1);
		nhap(x);
		ThemNodeVaoCay(t,x);
	}
	printf("\n---DUYET THEO NLR----");
	Duyet_NLR(t);
	printf("\n---XUAT CAC GIANG VIEN CHINH---");
	printf("\n");
	xuatGVchinh(t);
	printf("\n---XOA GIAO VIEN CO MA LA X---");
	printf("\nNHAP GIAO VIEN CO MA LA X:");
	scanf("%d",&x.magv);
	remove(t,x);
	printf("\nSAU KHI XOA GIAO VIEN CO MA LA X: ")
	Duyet_NLR(t);
	return 0;
}
