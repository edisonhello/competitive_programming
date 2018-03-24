#include<bits/stdc++.h>
using namespace std;


int a[100005],cnt[100005],n,ccnt[100005],ans;

void add(int v){
    if(cnt[v])--ccnt[cnt[v]];
    ++cnt[v];
    ++ccnt[cnt[v]];
    if(cnt[v]>ans)ans=cnt[v];
}
void sub(int v){
    --ccnt[cnt[v]];
    --cnt[v];
    ++ccnt[cnt[v]];
    while(!ccnt[ans])--ans;
}

long long get(int mid){
    long long rt=0;
    int L=1,R=0;
    for(;L<=n;++L){
        while(R<n && ans<mid)add(a[++R]);
        if(ans>=mid)rt+=n-R+1;
        sub(a[L]);
    }
    return rt;
}


int main(){
    vector<int> num;
    int k; cin>>n>>k;
    for(int i=0;i<n;++i)cin>>a[i],num.push_back(a[i]);
    sort(num.begin(),num.end()); num.resize(unique(num.begin(),num.end())-num.begin());
    for(int i=0;i<n;++i)a[i]=lower_bound(num.begin(),num.end(),a[i])-num.begin();
    int L=1,R=n;
    while(R>L){
        int mid=(L+R+1)>>1;
        if(get(mid)>=k)L=mid;
        else R=mid-1;
    }
    cout<<L<<endl;
}
