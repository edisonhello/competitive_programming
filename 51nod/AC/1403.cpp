#include<bits/stdc++.h>
using namespace std;

int a[2000006];
int o[1000006];

void go(int l,int r,int &ptr){
    // cout<<"go "<<l<<" "<<r<<" "<<ptr<<endl;
    a[l]=1; a[r]=-1; ++l; --r;
    while(r>l){
        int ll=r-o[ptr]*2-1;
        --ptr;
        go(ll,r,ptr);
        r=ll-1;
    }
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>o[i]; o[n+1]=n;
    int ptr=n;
    go(0,2*n+1,ptr);
    // for(int i=1;i<=n*2;++i)cout<<a[i]<<" "; cout<<endl;
    int cnt=0;
    for(int i=1;i<=n*2;++i){
        if(a[i]==1)++cnt;
        else cout<<cnt<<" ";
    }
    cout<<endl;
}
