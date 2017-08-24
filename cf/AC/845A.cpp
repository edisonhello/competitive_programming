#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){int n;cin>>n;for(int i=0;i<2*n;++i)cin>>a[i];sort(a,a+n*2);cout<<(a[n-1]==a[n]?"NO":"YES")<<endl;}
