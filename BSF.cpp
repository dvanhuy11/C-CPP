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
void duyetLNR(TREE t)
{
	if(t!=NULL)
	{
		duyetLNR(t->pLeft);
		printf("\t%d",t->data);
		duyetLNR(t->pRight);
	}
}
void duyetLRN(TREE t)
{
	if(t!=NULL)
	{
		duyetLRN(t->pRight);
		printf("\t%d",t->data);
		duyetLRN(t->pLeft);
	}
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
}
int max(TREE t)
{
	if(t->pRight==NULL)
	{
		return t->data;
	}
	return max(t->pRight);
}
int MIN(TREE t)
{
	if(t->pLeft==NULL)
	{
		return t->data;
	}
	return MIN(t->pLeft);
}
int dem(TREE t)
{
	if(t==NULL)
		return 0;
	return 1+dem(t->pLeft)+dem(t->pRight);
}
int demla(TREE t)
{
	if(t==NULL)
		return 0;
	if(t->pLeft==NULL && t->pRight==NULL)
//		{
//			printf("\nNODE LA %d",t->data);
			return 1;
//		}
	return demla(t->pLeft)+demla(t->pRight);
}
int demnodegiua(TREE t)
{
	return dem(t)-demla(t)-1;
}
int tong(TREE t)
{
	if(t==NULL)
		return 0;
	return t->data+tong(t->pLeft)+tong(t->pRight); 
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
	printf("\n---DUYET TANG DAN LNR----");
	duyetLNR(t);
	printf("\n---DUYET GIAM DAN RNL----");
	duyetRNL(t);
	printf("\nGIA TRI LON NHAT TRONG CAY: %d",max(t));
	printf("\nGIA TRI NHO NHAT TRONG CAY: %d",MIN(t));
	printf("\nSO NODE LA:%d",demla(t));
	printf("\nSO NODE GIUA:%d",demnodegiua(t));
	printf("\nTONG CAC GIA TRI TREN CAY:%d",tong(t));
	printf("\n----XAC DINH NODE CHA CUA X----");
	printf("\nNHAP X:");
	int v;
	scanf("%d",&v);
	node *c=nodecha(t,v);
	printf("\nNODE CHA CUA %d la:%d",v,c);
	return 0;
}
