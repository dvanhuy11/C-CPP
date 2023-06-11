#include<stdio.h>
#include <stdlib.h>
void Kiemtra(int a[][100],int n)
{
 int s,d,u;
 d=0;
 for(int i=1; i<=n;i++)
 {
   s=0;
   for(int j=1; j<=n;j++)
   	 s+=a[i][j];
   if(s%2!=0)
  	{
  		 d++; 
  		 u=i; // danh dau dinh bac le
   }
 }
 if(d==2) 
 	printf("DO THI CO DUONG DI EULER ");
 else 
	printf("DO THI CO CHU TRINH EULER ");
}
void DDEULER(int a[][100],int n)
{
 FILE *f1,*f2;
 f1=fopen("D:\\CODE\\duongdiEULER.inp.txt","rt");
 f2=fopen("D:\\CODE\\duongdiEULER.out.txt","wt");
 fscanf(f1,"%d",&n);
 for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			fscanf(f1,"%d",&a[i][j]);
 int pop, x, top, dCE;
 int stack[100], CE[100];
 top=1;
 stack[top]=1;
 dCE=0; 
 do {
   pop = stack[top];
   x=1;
   while (x<=n && a[pop][x]==0)
       x++;
   if (x>n)
	{ 
    	dCE++;
		CE[dCE]=pop; 
		top--;
	}   
   else 
	{
	   top++;
	   stack[top]=x; 
	   a[pop][x]=0; 
       a[x][pop]=0; 
 	 }
 } while(top!=0);
  	fprintf(f2,"\nDUONG DI EULER LA: ");
    for(x=1; x<=dCE; x++)
  		fprintf(f2," %d ",CE[x]);
  	fclose(f1);
  	fclose(f2);
}
int main()
{	
	int a[100][100];
	int n;
	FILE *f1,*f2;
	f1=fopen("D:\\CODE\\duongdiEULER.inp.txt","rt");
	f2=fopen("D:\\CODE\\duongdiEULER.out.txt","wt");
	fscanf(f1,"%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			fscanf(f1,"%d",&a[i][j]); // 
//	if(Kiemtra(a,n)==true)
//		fprintf(f2,"DO THI CO DUONG DI EULER ");
//	else 
//		fprintf(f2,"DO THI CO CHU TRINH EULER ");
    Kiemtra(a,n);
	DDEULER(a,n);
	fclose(f1);
	fclose(f2);
	return 0;
}
