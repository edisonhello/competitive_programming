#include<bits/stdc++.h>
using namespace std;

#define int long long
int a[123123];

int get(int ma,int n){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<ma;++i)pq.push(0);
    int rt=0;
    for(int i=1;i<=n;++i){
        pq.push(pq.top()+a[i]);
        rt=max(rt,pq.top()+a[i]);
        pq.pop();
    }
    return rt;
}

int32_t main(){
    int t; cin>>t; while(t--){
        int n,d; cin>>n>>d;
        for(int i=1;i<=n;++i)cin>>a[i];
        bool ok=1;
        for(int i=1;i<=n;++i)if(a[i]>d)ok=0;
        if(!ok){cout<<-1<<endl; break;}
        int L=1,R=n;
        while(R>L){
            int m=(L+R)>>1;
            if(get(m,n)>d)L=m+1;
            else R=m;
        }
        cout<<L<<endl;
    }
}
