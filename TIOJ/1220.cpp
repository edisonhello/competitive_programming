#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n,m,i,j,x,y;
vector<pair<int,int> > v;
bool app[100005];
int djs[100005],sz[100005];
set<int> s;

int F(int a){
    if(djs[a]==0)return a;
    else return djs[a]=F(djs[a]);
}
void U(int a,int b){
    if(a==b)return;
    // cout<<"do U:"<<a<<" "<<b<<endl;
    a=F(a),b=F(b);
    if(a==b)return;
    if(sz[a]>sz[b])swap(a,b);
    djs[a]=b;
    sz[b]+=sz[a];
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>x>>y;
        v.push_back({x,y});
        v.push_back({y,x});
    }
    sort(v.begin(),v.end());
    memset(sz,1,sizeof(sz));
    // for(i=0;i<v.size();i++)cout<<v[i].X<<" "<<v[i].Y<<endl;
// cout<<"ed"<<endl;
    for(i=0;i<v.size();i++){
        // cout<<i<<endl;
        if(i && v[i].X!=v[i-1].X){
            for(j=1;j<=n;j++){
                if(!app[j]){
                    U(v[i-1].X,j);
                }
            }
            memset(app,0,sizeof(app));
        }
        app[v[i].Y]=1;
    }
// cout<<"a4"<<endl;
    for(j=1;j<=n;j++){
        if(!app[j]){
            U(v[i-1].X,j);
        }
    }
    for(i=1;i<=n;i++){
        s.insert(djs[i]);
        // cout<<djs[i]<<" ";
    }
    cout<<s.size()<<endl;
}
