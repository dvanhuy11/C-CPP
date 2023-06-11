#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
	int data; 
	struct node *pLeft; 
	struct node *pRight; 
};
typedef struct node NODE;
typedef NODE* TREE;
void KhoiTaoCay(TREE &t)
{
	t = NULL; 
}
void duyetRNL(TREE t)
{
	if(t!=NULL)
	{
		duyetRNL(t->pRight);
		printf("\t%d",t->data);
		duyetRNL(t->pLeft);
	}
}
void nhohonX(TREE t,int x)
{
	if(t!=NULL)
	{
		duyetRNL(t->pRight);
		if(t->pRight->data < x)
			printf("\t%d",x);
		duyetRNL(t->pLeft);
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
void ThemNodeVaoCay(TREE &t, int &x)
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
		
		if (t->data > x)
			ThemNodeVaoCay(t->pLeft, x);  
		else if (t->data < x) 
			ThemNodeVaoCay(t->pRight, x); 
	}
	t=canbang(t);
}
void remove(TREE &t,int x)
{
	if(t==NULL)
	{
		return ;
	}
	else
	{
		if(x < t->data)
		{
			remove(t->pLeft,x);
		}
		else if(x > t->data)
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
node* nodecha(TREE t,int x)
{
	if(t==NULL)
		return NULL;
	if(t->data==x)
		return NULL;
	while(t!=NULL)
	{
		if(t->pLeft!=NULL && t->pLeft->data==x)
			return t;
		if(t->pRight!=NULL && t->pRight->data==x)
			return t;
		if(t->data<x)
			t=t->pRight;
		else 
			t=t->pLeft;
	}
	return t;
}
node* timkiem(TREE t,int x)
{
	if(t==NULL)
	{
		return NULL;
	}
	else
	{
		if(x < t->data)
		{
			timkiem(t->pLeft,x);
		}
		else if(x > t->data)
		{
			timkiem(t->pRight,x);
		}
		else
		{
			return t;	
		}
	}
}
int main()
{
	TREE t;
	KhoiTaoCay(t);
	int n;
	while(true)
	{
		system("cls");
		printf("\n\n\t\t==========MENU=========");
		printf("\nDINH VAN HUY-2080601470-20DTHE5");
		printf("\n1. Nhap du lieu");
		printf("\n2. Xuat du lieu giam dan RNL");
		printf("\n3. Tim kiem phan tu trong cay");		
		printf("\n4. Xoa node");
		printf("\n0.Ket thuc");
		printf("\n\n\t\t========================");
		int option;
		printf("\nNhap lua chon:");
		scanf("%d",&option);
		if(option<0||option>9)
		{
			printf("\nLua chon khong hop le");
			getch();
		}
		else if(option==1)
		{
			int x;
			int dc=0,i=0;;
			printf("\nNhap so nguyen x:");
			scanf("%d",&x);
			ThemNodeVaoCay(t,x);
//			if(x%2==0)
//			{
//				ThemNodeVaoCay(t,x);
//				dc++;
//			}
//			else 
//				ThemNodeVaoCay(t,x);
//			if(dc<3)
//				printf("\nNHAP THIEU SO CHAN");
			getch();
		}
		else if(option==2)
		{
			printf("\n\n\t\tDUYET CAY THEO RNL GIAM DAN");
			duyetRNL(t);
			getch();
		}
		else if(option==3)
		{
			int x;
			printf("\nNhap phan tu can tim:");
			scanf("%d",&x);
			node* p=timkiem(t,x);
			if(p==NULL)
			{
				printf("\nPhan tu %d khong ton tai",x);
			}
			else
				nhohonX(t,x);
			remove(t,x);
			getch();
		}
		else if(option==4)
		{
			int x;
			printf("\nNhap gia tri can xoa:");
			scanf("%d",&x);
			remove(t,x);
		}
		else 
		{
			break;
		}
	}
	return  0;
	return 
}
