#include<iostream>
#include<queue>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
struct s{int m,p;};
bool operator>(const s &a,const s &b){
    return (a.m!=b.m?a.m>b.m:a.p<b.p);
}
priority_queue<s,vector<s>,greater<s>> pq;
int n,mx,nw;
int main(){
    while(cin>>n){
        while(pq.size())pq.pop();
        mx=nw=0;
        for(int i=0,s,e;i<n;++i){
            cin>>s>>e;
            pq.push({s,1});
            pq.push({e,-1});
        }
        while(pq.size()){
            s t=pq.top();pq.pop();
            nw+=t.p;
            mx=max(mx,nw);
        }
        cout<<mx<<endl;
    }
}
