#include<iostream>
#include<queue>
using namespace std;
#define int long long
priority_queue<int,vector<int>,less<int>> pq;

main(){
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    int now=0;
    int t;
    int ans=0;
    while(n--){
        cin>>t;
        now+=t;
        if(t<0)pq.push(-t);
        while(now<0){
            now+=pq.top();pq.pop();++ans;
        }
    }
    cout<<ans<<endl;
}
