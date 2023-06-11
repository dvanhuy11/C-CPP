#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
    int n,m, a[100][100];
    getline(cin,n);
    getline(cin,m);
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    }
     for (int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout << "a[" << i <<"]["<<j<<"]=" << a[i][j] << endl;
    }
    
    return 0;
}

