#include<bits/stdc++.h>
using namespace std;

struct p{
    int l,r,lb,i;
} a[1000006];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;++i){
        int l,r; cin>>l>>r;
        a[i]={l,r,l/1000,i+1};
    }
    sort(a,a+n,[](const p &a,const p &b){return a.lb==b.lb?a.lb&1?a.r<b.r:a.r>b.r:a.lb<b.lb;});
    for(int i=0;i<n;++i)cout<<a[i].i<<" "; cout<<endl;
}
