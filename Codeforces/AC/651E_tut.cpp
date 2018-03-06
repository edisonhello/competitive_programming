#include<bits/stdc++.h>
using namespace std;
#define pipii pair<int,pair<int,int>>
#define mp make_pair

int n,m,deg[2000006],pos[2000006];
vector<vector<int>> a;
vector<int> G[2000006],tp;
int djs[2000006];


int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
void U(int x,int y){x=F(x); y=F(y); djs[x]=y;}


int main(){
    cin>>n>>m;
    a.resize(n);
    for(int i=0;i<n;++i)a[i].resize(m);
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>a[i][j];
    for(int i=0;i<2000006;++i)djs[i]=i;
    for(int i=0;i<n;++i){
        vector<pair<int,int>> v;
        for(int j=0;j<m;++j){
            v.emplace_back(a[i][j],j);
        }
        sort(v.begin(),v.end());
        for(int j=1;j<m;++j){
            if(v[j].first==v[j-1].first)U(i*m+v[j].second,i*m+v[j-1].second);
        }
    }
    for(int j=0;j<m;++j){
        vector<pair<int,int>> v;
        for(int i=0;i<n;++i){
            v.emplace_back(a[i][j],i);
        }
        sort(v.begin(),v.end());
        for(int i=1;i<n;++i){
            if(v[i].first==v[i-1].first)U(v[i].second*m+j,v[i-1].second*m+j);
        }
    }
    for(int i=0;i<n;++i){
        vector<pair<int,int>> v;
        for(int j=0;j<m;++j){
            v.emplace_back(a[i][j],F(i*m+j));
        }
        sort(v.begin(),v.end()); v.resize(unique(v.begin(),v.end())-v.begin());
        for(int j=1;j<v.size();++j){
            G[v[j-1].second].push_back(v[j].second);
            ++deg[v[j].second];
        }
    }
    for(int j=0;j<m;++j){
        vector<pair<int,int>> v;
        for(int i=0;i<n;++i){
            v.emplace_back(a[i][j],F(i*m+j));
        }
        sort(v.begin(),v.end()); v.resize(unique(v.begin(),v.end())-v.begin());
        for(int i=1;i<v.size();++i){
            G[v[i-1].second].push_back(v[i].second);
            ++deg[v[i].second];
        }
    }
    queue<int> q;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(deg[i*m+j]==0)q.push(i*m+j);
    while(q.size()){
        // cout<<"q in "<<q.front()<<endl;
        tp.push_back(q.front());
        for(int i:G[q.front()]){
            --deg[i];
            if(deg[i]==0){
                // cout<<q.front()<<" update "<<i<<endl;
                q.push(i),pos[i]=max(pos[i],pos[q.front()]+1);
            }
        }
        q.pop();
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<pos[F(i*m+j)]+1<<" ";
        }
        cout<<endl;
    }
}
