#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void nhapn(int &n)
{
	do
	{
		printf("nhap n=");
		scanf("%d",&n);
	}while(n<0 || n>100);
}
void random(int a[],int n)
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
		a[i]=rand()%100;
}
void merge(int a[], int l, int m, int r)
{
    int i,j,k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for ( j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}
void xuat(int a[], int size)
{
    for (int i=0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}
 
 
int main()
{
    int a[100],n;
    nhapn(n);
    random(a,n);
    printf("Xuat Mang: \n");
    xuat(a,n);
    mergeSort(a, 0,n-1);
    printf("\Merge Sort:\n");
    xuat(a,n);
    return 0;
}
