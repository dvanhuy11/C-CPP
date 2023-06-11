#include<iostream>
using namespace std;
int max(int a[],int n)
{
    int max1=a[0];
    for(int i=0;i<n;i++)
        if(a[i]>max1)
            max1=a[i];
    return max1;
}
int main()
{
    int n,a[100],b[100];
    cin >> n;
    for(int i=0;i<n;i++)
       {
       	cout<<"nhap a["<<i<<"]:";
       	cin>>a[i];
	   }
    for(int i=0;i<=max(a,n);i++)
        b[i]=0;
    for(int i =0; i<n;i++)
        b[a[i]]+=1;
    for(int i=0;i<= max(a,n);i++)
        if(b[i]>0)
            cout<< i << " - "<< b[i]<< "; ";
    return 0;
}

