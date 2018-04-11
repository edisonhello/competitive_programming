#include<bits/stdc++.h>
using namespace std;

vector<int> num;
vector<pair<int,int>> es[200005];
int L[100005],R[100005],w[100005];

int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i){
        cin>>L[i]>>R[i]>>w[i];
        num.push_back(L[i]);
        num.push_back(R[i]);
    }
    sort(num.begin(),num.end());
    for(int i=0;i<n;++i){
        L[i]=lower_bound(num.begin(),num.end(),L[i])-num.begin();
        R[i]=lower_bound(num.begin(),num.end(),R[i])-num.begin();
        es[L[i]].emplace_back(w[i],1);
        es[R[i]+1].emplace_back(w[i],-1);
    }
    int st=0,mx=0,now=0;
    for(int i=0;i<2*n;++i){
        for(auto p:es[i]){
            if(p.second==1){
                st+=p.first;
                now+=p.first;
            }
            else{
                st-=p.first;
            }
        }
        now=max(st,now);
        mx=max(now,mx);
    }
    cout<<mx<<endl;
}
