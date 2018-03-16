#include<bits/stdc++.h>
using namespace std;
#define ll long long

template<typename T>void print(T pq){
    while(pq.size()){
        cout<<pq.top()<<" ";
        pq.pop();
    } cout<<endl;
}


int delta;

bool flag;
void solve(ll n,int k,int y){
    if(!flag && (1ll<<y)*k>=n)flag=1;
    if(!flag)return;
    // cout<<y<<endl;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    while(n){
        // cout<<n<<" "<<y<<endl;
        while(n>=(1ll<<y)){
            n-=(1ll<<y);
            pq.push(y);
        }
        --y;
    }
    if(pq.size()>k){
        return;
    }
    // print(pq);
    while(pq.size()<k){
        int tmp=pq.top(); pq.pop();
        pq.push(tmp-1);
        pq.push(tmp-1);
    }
    cout<<"Yes"<<endl;
    stack<int> ans;
    while(pq.size()){
        ans.push(pq.top());
        pq.pop();
    }
    while(ans.size()){
        cout<<ans.top()-delta<<" ";
        ans.pop();
    }
    cout<<endl;
    exit(0);
}

int cnt[66];
int main(){
    ll n; int k; cin>>n>>k;
    while(n<k)n<<=1,++delta;
    priority_queue<ll,vector<ll>,less<ll>> pq;
    for(int y=0;;++y){
        solve(n,k,y);
        /* if(n&(1ll<<y)){
            n-=(1ll<<y);
            pq.push(y);
        } */
        if((1ll<<y)>n){
            cout<<"No"<<endl;
            exit(0);
        }
    }
    if(pq.size()>k){
        cout<<"No"<<endl;
        exit(0);
    }
    while(pq.size()<k){
        pq.push(pq.top()-1);
        pq.push(pq.top()-1);
        pq.pop();
    }
    cout<<"Yes"<<endl;
    ll sum=0;
    while(pq.size()){
        cout<<pq.top()<<" ";
        ++cnt[pq.top()];
        sum+=(1ll<<pq.top());
        pq.pop();
    }
    cout<<endl;
    cout<<cnt[44]<<" "<<sum<<endl;
}
