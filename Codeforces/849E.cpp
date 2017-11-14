#include<bits/stdc++.h>
using namespace std;

struct o{
    int type,x,y,qid,t;
} os[600009];

int timer,optr,a[100009];
set<int> num[100009];


int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i],num[a[i]].insert(i);
    for(int i=1;i<=n;++i){
        int t,x,y; cin>>t>>x>>y;
        if(t==1){
            auto it=num[a[x]].find(x);
            if(it!=num[a[x]].begin())os[optr++]={-1,x,a[x]}
        }
        else{
            
        }
    }
}
