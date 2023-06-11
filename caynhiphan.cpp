#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *pleft;
	struct node *pright;
};
typedef node *tree;
//khoi tao cay
node *createNode(int x)
{
	node *p=new node;//khoi tao mot node de them vao cay
	p->data=x;
	p->pleft=NULL;
	p->pright=NULL;
	return p;
}
void createTree(tree &t)
{
	t=NULL;
}
int isEmpty(tree t)
{
	return (t==NULL);//cay rong
}
//them X vao cay
void insert(tree &t,int x)
{
	if(t==NULL)
	{
		t=createNode(x);
	}
	else
	{
		if(x==t->data)
		{
			return;
		}
		else if(x<t->data)
		{
			insert(t->pleft,x);
		}
		else 
		{
			insert(t->pright,x);
		}
	}
}
//xuat du lieu
void duyetNLR(tree t)
{
	if(t!=NULL)
	{
		printf("\t%d",t->data);
		duyetNLR(t->pleft);
		duyetNLR(t->pright);
	}
}
void duyetNRL(tree t)
{
	if(t!=NULL)
	{
		printf("\t%d",t->data);
		duyetNRL(t->pright);
		duyetNRL(t->pleft);
	}
}
void duyetLNR(tree t)
{
	if(t!=NULL)
	{
		duyetLNR(t->pleft);
		printf("\t%d",t->data);
		duyetLNR(t->pright);
	}
}
bool KTSNT(int x)
{
	if(x<2)
	{
		return false;
	}
	else
	{
		if(x==2)
		{
			return true;
		}
		else
		{
			if(x%2==0)
			{
				return false;
			}
			else
			{
				for(int i=2;i<x;i++)
				{
					if(x%1==0)
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}
void demSNT(tree t,int &dem)
{
	if(t!=NULL)
	{
		if(KTSNT(t->data)==1)
			dem++;
		demSNT(t->pleft,dem);
		demSNT(t->pright,dem);
	}
}
node* timkiem(tree t,int x)
{
	if(t==NULL)
	{
		return NULL;
	}
	else
	{
		if(x < t->data)
		{
			timkiem(t->pleft,x);
		}
		else if(x > t->data)
		{
			timkiem(t->pright,x);
		}
		else
		{
			return t;	
		}
	}
}
void node2con(tree t)
{
	if(t!=NULL)
	{
		if(t->pleft!=NULL && t->pright!=NULL)
		{
			printf("\t%d",t->data);
		}
		node2con(t->pleft);
		node2con(t->pright);
	}
}
void node1con(tree t)
{
	if(t!=NULL)
	{
		if(t->pleft!=NULL && t->pright==NULL || t->pleft==NULL && t->pright!=NULL)
		{
			printf("\t%d",t->data);
		}
		node1con(t->pleft);
		node1con(t->pright);
	}
}
void nodela(tree t)
{
	if(t!=NULL)
	{
		if(t->pleft==NULL && t->pright==NULL)
		{
			printf("\t%d",t->data);
		}
		nodela(t->pleft);
		nodela(t->pright);
	}
}
int timMAX(tree t)
{
	if(t->pright==NULL)
	{
		return t->data;
	}
	return timMAX(t->pright);
}
void timNodethemang(tree &x, tree &y)
{
	if(y->pleft!=NULL)
	{
		timNodethemang(x,y->pleft);
	}
	else
	{
		x->data=y->data;
		x=y;
		y=y->pright;
	}
}
void remove(tree &t,int x)
{
	if(t==NULL)
	{
		return ;
	}
	else
	{
		if(x < t->data)
		{
			remove(t->pleft,x);
		}
		else if(x > t->data)
		{
			remove(t->pright,x);
		}
		else
		{
			node* p=t;
			if(t->pleft==NULL)
			{
				t=t->pright;
			}
			else if(t->pright==NULL)
			{
				t=t->pleft;
			}
			else
			{
				timNodethemang(p,t->pright);
			}
			delete p;
		}
	}
}
//nhap du lieu
void menu(tree &t)
{
	while(true)
	{
		system("cls");
		printf("\n\n\t\t==========MENU=========");
		printf("\n1. Nhap du lieu");
		printf("\n2. Xuat du lieu NLR");
		printf("\n3. Dem so luong nguyen to");
		printf("\n4. Tim kiem phan tu trong cay");		
		printf("\n5. Xuat cac node co 2 con");
		printf("\n6. Xuat cac node co 1 con");
		printf("\n7. Xuat cac node la");
		printf("\n8. Tim MAX");
		printf("\n9. Xoa node");
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
			printf("\nNhap so nguyen x:");
			scanf("%d",&x);
			insert(t,x);
		}
		else if(option==2)
		{
			printf("\n\n\t\tDUYET CAY THEO NLR");
			duyetNLR(t);
			getch();
		}
		else if(option==3)
		{
			int dem=0;
			demSNT(t,dem);
			printf("\nSo luong SNT:%d",dem);
		}
		else if(option==4)
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
			{
				printf("\nPhan tu %d co ton tai",x);
			}
			getch();
		}
		else if(option==5)
		{
			printf("\n\t Node co 2 con: ");
			node2con(t);
			getch();
		}
		else if(option==6)
		{
			printf("\n\t Node co 1 con: ");
			node1con(t);
			getch();
		}
		else if(option==7)
		{
			printf("\n\t Node la: ");
			nodela(t);
			getch();
		}
		else if(option==8)
		{
			int kq=timMAX(t);
			printf("\nGia tri lon nhat:%d",kq);
			getch();
		}
		else if(option==9)
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
}
int main()
{
	tree t;
	createTree(t);
	menu(t);
	getch();
	return 0;
}
