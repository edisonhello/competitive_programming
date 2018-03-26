#include<bits/stdc++.h>
using namespace std;

int x[100005],h[100005];
bool fal[100005];
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>x[i]>>h[i];
    int cnt=1; 
    for(int i=2;i<=n;++i){
        if(x[i]-h[i]>(fal[i-1]?x[i-1]+h[i-1]:x[i-1]))++cnt;
        else if(i==n || x[i]+h[i]<x[i+1])++cnt,fal[i]=1;
    }
    cout<<cnt<<endl;
}
