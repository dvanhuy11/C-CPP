#include<stdio.h>
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
int main()
{
	TREE t;
	KhoiTaoCay(t);
	int n;
	printf("\nNHAP SO NODE CAN THEM VAO CAY:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		printf("\nNHAP GIA TRI NODE %d:",i+1);
		scanf("%d",&x);
		ThemNodeVaoCay(t,x);
	}
	printf("\n---DUYET THEO NLR----");
	Duyet_NLR(t);
	return 0;
}
