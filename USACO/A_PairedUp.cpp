#include<bits/stdc++.h>
using namespace std;

pair<int,int> c[100008];

int main(){
    freopen("pairup.in","r",stdin);
    freopen("pairup.out","w",stdout);
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>c[i].second>>c[i].first;
    sort(c,c+n);
    int mx=0;
    int i=0,j=n-1;
    while(j>=i){
        int mn=min(c[i].second,c[j].second);
        c[i].second-=mn, c[j].second-=mn;
        mx=max(mx,c[i].first+c[j].first);
        while(c[i].second<=0 && j>=i)++i;
        while(c[j].second<=0 && j>=i)--j;
    } cout<<mx<<endl;
}
