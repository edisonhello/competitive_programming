#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define ll long long

priority_queue<int,vector<int>,less<int>> pql;
priority_queue<int,vector<int>,greater<int>> pqg;

int main(){
int t;while(cin>>t){
    ll ans=0;
    while(pql.size())pql.pop();
    while(pqg.size())pqg.pop();

    while(t--){
        int n;cin>>n;
        while(n--){
            int t;cin>>t;
            pql.push(t);
            pqg.push(t);
            while((int)pql.size()>5005)pql.pop();
            while((int)pqg.size()>5005)pqg.pop();
        }
        if(pql.size() && pqg.size()){
            ans+=(int)(pql.top()-pqg.top());
            pql.pop(),pqg.pop();
        }
    }
    cout<<ans<<endl;
}}
