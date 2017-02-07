#include<iostream>
using namespace std;
#include<queue>

struct st{int t,v;};
bool operator<(const st &a,const st &b){return a.v<b.v;}
bool operator>(const st &a,const st &b){return a.v>b.v;}
priority_queue<st,vector<st>,greater<st>> pq;

int main(){
    int U,P,B;cin>>U>>P>>B;
    int m;cin>>m;
    while(m--){
        int v;string t;
        cin>>v>>t;
        if(t=="USB"){
            pq.push({1,v});
        }
        else{
            pq.push({2,v});
        }
    }
    int cnt=0;
    long long ans=0;
    while(pq.size()){
        if(pq.top().t==1){
            if(U>0){
                --U;
                ++cnt;
                ans+=pq.top().v;
            }
            else if(B>0){
                --B;
                ++cnt;
                ans+=pq.top().v;
            }
        }
        if(pq.top().t==2){
            if(P>0){
                --P;
                ++cnt;
                ans+=pq.top().v;
            }
            else if(B>0){
                --B;
                ++cnt;
                ans+=pq.top().v;
            }
        }
        pq.pop();
    }
    cout<<cnt<<" "<<ans<<endl;
}
