#include<bits/stdc++.h>
using namespace std;

struct point{
    int x,y,i,c;
} pt[200005];
vector<int> G[200005];
int clr[200005];

int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i){
        int x,y; cin>>x>>y;
        pt[i]={x,y,i,0};
    }
    sort(pt,pt+n,[](const point &a,const point &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
    for(int i=1;i<n;++i){
        if(pt[i].x==pt[i-1].x){
            G[pt[i].i].push_back(pt[i-1].i);
            G[pt[i-1].i].push_back(pt[i].i);
            ++i;
        }
    }
    sort(pt,pt+n,[](const point &a,const point &b){return a.y==b.y?a.x<b.x:a.y<b.y;});
    for(int i=1;i<n;++i){
        if(pt[i].y==pt[i-1].y){
            G[pt[i].i].push_back(pt[i-1].i);
            G[pt[i-1].i].push_back(pt[i].i);
            ++i;
        }
    }
    for(int i=0;i<n;++i){
        if(clr[i])continue;
        queue<int> q; q.push(i);
        clr[i]=1;
        while(q.size()){
            int now=q.front(); q.pop();
            for(int i:G[now]){
                if(clr[i])continue;
                clr[i]=3-clr[now];
                q.push(i);
            }
        }
    }
    for(int i=0;i<n;++i)cout<<(clr[i]==1?'b':'r');
    cout<<endl;
}
