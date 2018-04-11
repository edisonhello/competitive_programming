#include<bits/stdc++.h>
using namespace std;

long long a[200005];
bitset<200005> del;
map<long long,int> pos;

void go(int idx){
    auto &ii=pos[a[idx]];
    if(!ii)return;
    del[ii]=1;
    a[idx]<<=1;
    ii=0;
    go(idx);
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        go(i);
        pos[a[i]]=i;
    }
    cout<<n-del.count()<<endl;
    for(int i=1;i<=n;++i)if(!del[i])cout<<a[i]<<" ";
}
