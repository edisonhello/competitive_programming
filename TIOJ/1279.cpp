#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;

struct node{
    int x,y,v;
    friend bool operator <(const node &l,const node &r){
        return l.v<r.v;
    }
};

priority_queue<node,vector<node>,less<node> > pq;
int a[1005][1005];
bool sec[1005][1005];
ll ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            pq.push({i,j,a[i][j]});
        }
    }

    while(pq.size()){
        node tmp = pq.top();
        pq.pop();
        int x=tmp.x,y=tmp.y,v=tmp.v;
        // cout<<x<<" "<<y<<endl;
        sec[x][y]=1;
        if(sec[x+1][y]){
            ans+=a[x+1][y];
        }
        if(sec[x-1][y]){
            ans+=a[x-1][y];
        }
        if(sec[x][y+1]){
            ans+=a[x][y+1];
        }
        if(sec[x][y-1]){
            ans+=a[x][y-1];
        }
        ans+=v;
    }
    cout<<ans<<endl;
}
