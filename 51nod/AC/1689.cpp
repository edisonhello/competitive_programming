#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005],b[100005];
int c[100005];

int main(){
    int n,k; ll t; cin>>n>>t>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    for(int i=1;i<=n;++i)cin>>c[i];
    int L=0,R=n;
    function<bool(int)> ok=[&](int targ){
        int ptr=0,cnt=0,cntc=0;
        ll nowt=0;
        priority_queue<int,vector<int>,less<int>> pqc,pq;
        for(++ptr;ptr<=n && (cnt<targ || cntc<k);++ptr){
            nowt+=a[ptr]-a[ptr-1]+b[ptr];
            ++cnt;	
            if(c[ptr])++cntc;
            if(c[ptr])pqc.push(b[ptr]);
            else pq.push(b[ptr]);
            if(cntc>k && cnt>targ){
                if(pqc.size() && pq.empty())--cntc,--cnt,nowt-=pqc.top(),pqc.pop();
                else if(pq.size() && pqc.empty())--cnt,nowt-=pq.top(),pq.pop();
                else if(pq.top()>=pqc.top())--cnt,nowt-=pq.top(),pq.pop();
                else --cnt,--cntc,nowt-=pqc.top(),pq.pop();
            }
            else if(cnt>targ && pq.size()){
                nowt-=pq.top(); pq.pop(); --cnt;
            }
        }
        // cout<<"targ: "<<targ<<" , "<<nowt<<" "<<ptr<<" "<<cnt<<" "<<cntc<<endl;
        for(;ptr<=n && nowt>t;++ptr){
            nowt+=a[ptr]-a[ptr-1]+b[ptr];
            if(c[ptr])pqc.push(b[ptr]),++cntc,++cnt;
            else pq.push(b[ptr]),++cnt;
            if(cntc>k){
                if(pqc.size() && pq.empty())--cntc,--cnt,nowt-=pqc.top(),pqc.pop();
                else if(pq.size() && pqc.empty())--cnt,nowt-=pq.top(),pq.pop();
                else if(pq.top()>=pqc.top())--cnt,nowt-=pq.top(),pq.pop();
                else --cnt,--cntc,nowt-=pqc.top(),pqc.pop();
            }
            else{
                nowt-=pq.top(); pq.pop(); --cnt;
            }
        }
        return nowt<=t && cnt>=targ && cntc>=k;
    };
    while(R>L){
        int mid=(L+R+1)>>1;
        if(ok(mid))L=mid;
        else R=mid-1;
    }
    if(L<k)cout<<-1<<endl;
    else cout<<L<<endl;
}
