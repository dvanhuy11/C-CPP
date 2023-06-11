#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
struct MAT
{
	int sk;
	int kc;
	int hat;
	char t[10];
};
bool snt(int x)
{
	if (x<=1)
		return false;
	for (int j=2;j<=sqrt(x);j++)
		if(x%j==0)
			return false;
	return true;
}
void nhap(MAT &x)
{
	printf("nhap=");
	scanf("%d %d %d",&x.sk,&x.kc,&x.hat);
	gets(x.t);
}
void xuat(MAT x)
{
	printf("%d %d %d %s",x.sk,x.kc,x.hat,x.t);
}
bool triangular(int num)
{
    if (num < 0)
        return false;
    int sum = 0;
    for (int n=1; sum<=num; n++)
    {
        sum = sum + n;
        if (sum==num)
            return true;
    }
 
    return false;
}
float tinh(MAT x)
{
	int P1,P2;
	float f;
	if(x.kc<200)
		return f=0;
	if(200<=x.kc<300)
	{
		if(snt(x.sk))
				{
					P1=1000;
					P2=(x.sk+x.hat)%1000;
					f=((float)(x.kc+P1+P2))/1000;
					if (f>0.8)
						return f=0;
				}
		else
				{
					P1=x.sk;
					P2=(x.sk+x.kc)%100;
					f=((float)(x.kc+P1+P2))/1000;
					if(f>0.8)
						return f=0;
				}
	}
	if(300<=x.kc<=800)
	{
		int k=x.hat%6,g=0,p=0;
		switch(k)
		{
			case 0:
				g+=x.hat/2;
				break;
			case 1:
				g+=2*x.hat;
				break;
			case 2:
				g+=(-pow(x.hat%9,3))/5;
				break;
			case 3:
				g+=(-pow(x.hat%30,2))+(3*x.hat));
				break;
			case 4:
				g+=-(x.hat);
				break;
			case 5:
				g+=-(triangular((x.hat%5)+5));
				break;	
		}
		switch(x.t)
		{
			case 'Food':
					switch(k)
						case 1:
							p
		}
	}
//	switch(x->kc)
//	{
//		case(x->kc<200):
//			f=0;
//			break;
//		case(200<=x->kc<300):
//			if(snt(x->sk))
//				{
//					P1=1000;
//					P2=(x->sk+x->hat)%1000;
//					f=((float)(x->kc+P1+P2))/1000;
//					if (f>0.8)
//						return f=0;
//					else 
//						return f;
//				}
//			else
//				{
//					P1=x->sk;
//					P2=(x->sk+x->kc)%100;
//					f=((float)(x->kc+P1+P2))/1000;
//					if(f>0.8)
//						return f=0;
//					else 
//						return f;
//				}
//			break;
//		default:
//			break;	
	return f;			
}

int main()
{
	MAT x;
//	MAT t[10];
	nhap(x);
	xuat(x);
	printf("\n%.2f",tinh(x));
	return 0;
	
}
