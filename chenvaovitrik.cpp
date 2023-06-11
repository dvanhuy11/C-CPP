#include <iostream>
#include <conio.>
#include <stdio.h>
using namespace std;
int main()
{
    int a[100],n,x,k;
    cin>>n;
   // cin>>k>>x;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>k>>x;
    for(int i=n;i>=k+1;i--)
        a[i]=a[i-1];
    a[k]=x;
    n++;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    getch();
    return 0;
}