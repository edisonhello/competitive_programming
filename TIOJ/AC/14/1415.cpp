#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define ll long long

priority_queue<int,vector<int>,less<int>> pql;
priority_queue<int,vector<int>,greater<int>> pqg;

main(){
int t;while(~scanf("%d",&t)){
    ll ans=0;
    while(pql.size())pql.pop();
    while(pqg.size())pqg.pop();

    while(t--){
        int n;scanf("%d",&n);
        while(n--){
            int t;scanf("%d",&t);
            pql.push(t);
            pqg.push(t);
            // while((int)pql.size()>5005)pql.pop();
            // while((int)pqg.size()>5005)pqg.pop();
        }
        if(pql.size() && pqg.size()){
            ans+=(pql.top()-pqg.top());
            pql.pop(),pqg.pop();
        }
    }
    printf("%lld\n",ans);
}}
