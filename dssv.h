#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
typedef struct sinhvien
{
	int masv;
	char hoten[10];
	float dtb;
}sv;

typedef struct node
{
	sv info;
	int h; 
	struct node* left;
	struct node* right;
};
node* createnode(sv x)
{ 		    
	node* t=(node*)malloc(sizeof(struct node));
	t->info= x;
	t->left=NULL;
	t->right=NULL;
	return t;
}

void xuatsv(sv x)
{
	printf("\nMaSV: %d",x.masv);
	printf("\nHo ten: %s",x.hoten);
	printf("\nDien trung binh: %0.2f\n",x.dtb);
}

void NLR(node* p)
{
	if(p!=NULL)
	{
		xuatsv(p->info);
		NLR(p->left);
		NLR(p->right);
	}
}
int max(int a, int b)
{
	return a>b?a:b;
}

int geth(node* p)
{
	return p!=NULL?p->h:0;
} 
int bf(node *p)
{
	if (p == NULL)
	return 0;
	return geth(p->left) - geth(p->right);
}
node* xoaytrai(node* p)
{
	if(p==NULL)
	{
		return NULL;
	}
	if(p->right==NULL)
	{
		return NULL;
	}
	node* pivot=p->right;
	p->right=pivot->left;
	pivot->left=p;
	p->h = 1 + max(geth(p->right), geth(p->left));
	pivot->h = 1 + max(geth(pivot->right), geth(pivot->left));
	return pivot;
}
node* xoayphai(node* p)
{
	if(p==NULL)
	{
		return NULL;
	}
	if(p->left==NULL)
	{
		return NULL;
	}
	node* pivot=p->left;
	p->left=pivot->right;
	pivot->right=p;
	p->h= 1 + max(geth(p->right), geth(p->left));
	pivot->h= 1 + max(geth(pivot->right), geth(pivot->left));
	return pivot;
}
node* canbang(node* p)
{
	if(bf(p)<-1)
	{
		if(bf(p->right)>0)
		{
			p->right=xoayphai(p->right);
		}
		p=xoaytrai(p);
	}
	else if(bf(p)>1)
	{
		if(bf(p->left)<0)
		{
			p->left=xoaytrai(p->left);
		}
		p=xoayphai(p);
	} 
	return p;
} 
void insert(node* &p,sv x)
{       
	if(p==NULL)
	{
		p=createnode(x);
		return;
	}
	if(p->info.masv==x.masv)
	{
		return;
	}
	if(x.masv<p->info.masv)
	{
		insert(p->left,x);
	}
	else
	{
		insert(p->right,x);
	} 
	p->h = 1 + max(geth(p->left), geth(p->right));
	p=canbang(p);  
}

node* timsvY(node *p,char x[])
{
	if(p==NULL)
	{
		return NULL;
	}
	else
	{
		char a[10];
		strcpy(a,p->info.hoten);
		if(strcmp(a,x)!=0)
		{
			timsvY(p->left,x);
			timsvY(p->right,x);
		}
		else
		{			
			node* i=p;
			printf("MaSV: %d",i->info.masv);
			printf("\nHo ten: ");
			puts(i->info.hoten);
			printf("Dien trung binh: %0.2f",i->info.dtb);
		}
	}
}

node* timmsX(node *p,int x)
{
	if(p==NULL)
	{
		return NULL;
	}
	else
	{	
		if(p->info.masv>x)
		{
			timmsX(p->left,x);
		}
		else if(p->info.masv<x)
		{
			timmsX(p->right,x);
		}
		else
		{			
			node* i=p;
			printf("\nHo ten: ");
			puts(i->info.hoten);
			printf("MaSV: %d",i->info.masv);
			printf("\nDien trung binh: %0.2f",i->info.dtb);
		}
	}

}
node* max(node* p)
{
	node* i=p;
	while(i->right!=NULL)
	{
		i=i->right;
	}
	return i;
} 
node* removemsX(node* &p,int x)
{  
	if(p==NULL)
	{
		return NULL;
	} 
	if(p->info.masv>x)
	{
		removemsX(p->left,x);
	}
	else if(p->info.masv<x)
	{
		removemsX(p->right,x);	
	}
	else 
	{
		node* i=p;
		if(p->left==NULL)
		{
			p=p->right;
			free(i);
		}
		else if(p->right==NULL)
		{
			p=p->left;
			free(i);
		}
		else
		{
			node* maxleft=max(p->left);
			p->info.masv=maxleft->info.masv;
			removemsX(p->left,maxleft->info.masv);	
		}
	}
	if(p==NULL)
	{
		return NULL; 
	}
	p->h= 1 + max(geth(p->left), geth(p->right));
	p=canbang(p);  
}
node* removeTenY(node* &p,char x[])
{     
	if(p==NULL)
	{
		return NULL;
	} 
	char z[10];
	strcpy(z,p->info.hoten);
	if(strcmp(z,x)!=0)
	{
		removeTenY(p->left,x);
		removeTenY(p->right,x);
	}
	else
	{
		node* i=p;
		if(p->left==NULL)
		{
			p=p->right;
			free(i);
		}
		else if(p->right==NULL)
		{
			p=p->left;
			free(i);
		}
		else
		{
			node* maxleft=max(p->left);
			strcpy(p->info.hoten,maxleft->info.hoten);
			removeTenY(p->left,maxleft->info.hoten);	
		}
	}
	if(p==NULL)
	{
		return NULL; 
	}
	p->h= 1 + max(geth(p->left), geth(p->right));
	p=canbang(p);  
}
node* max(node* &p)
{
	int n;
    int max = p->info.dtb;
    for (int i = 1; i < n; i++)
        if (max < p->info.dtb)
            max = p->info.dtb;
    return max;
}
void xuatdtbtmax(node* p)
{
	int x=max(p);
	if(p!=NULL){
		if(p->info.dtb>max(p))
		{
			xuatsv(p->info);
		}
		xuatdtbtmax(p->left);
		xuatdtbtmax(p->right);
	}
}

int count(node* p)
{
	if(p==NULL)
	{
		return 0; 
	} 
	return 1+count(p->left)+count(p->right);
} 

