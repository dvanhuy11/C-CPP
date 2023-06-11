#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define MAX 100
void randommt(int a[][MAX],int m, int n)
{
	FILE *f1;
	f1=fopen("D:\\CODE\\bai3trang71.inp.txt","rt");
	fscanf(f1,"%d %d",&m,&n);
//	srand(time(NULL));
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
				fscanf(f1,"%d",&a[i][j]);												//		
																				//			a[i][j]=rand()%100;
																				//		//	fscanf(f1,"%d",a[i][j]);
																				//		}
	fclose(f1);
}
void xuat(int a[][100], int m, int n)
{
   for(int i = 0; i < m; i++)
   {
      	for(int j = 0; j < n; j++)
        	 printf("%d\t", a[i][j]);
    	printf("\n");
   }
}
void xuatmt(int a[][MAX],int m, int n)
{
	FILE *f1,*f2;
	f1=fopen("D:\\CODE\\bai3trang71.inp.txt","rt");
	fscanf(f1,"%d %d",&m,&n);
	 for(int i = 0; i < m; i++)
  		 {
      		for(int j = 0; j < n; j++)
        		 printf("%d\t", a[i][j]);
    		printf("\n");
  		}
  	fclose(f2);
}
void mtvuong(int a[][MAX],int m, int n)
{
	FILE *f1,*f2;
	f1=fopen("D:\\CODE\\bai3trang71.inp.txt","rt");
	fscanf(f1,"%d %d",&m,&n);
	f2=fopen("D:\\CODE\\bai3trang71.out.txt","w");
	if(m==n)
		{
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)	
					if(i==j)
						fprintf(f2," %d ",a[i][i]);
		}
	fclose(f1);
	fclose(f2);
}
int main()
{
	int n,m,a[MAX][MAX];
	randommt(a,m,n);
	xuatmt(a,m,n);
	mtvuong(a,m,n);
	return 0;
}

