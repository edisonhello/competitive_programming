#include<vector>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<map>
#include<queue>
#include<utility>
using namespace std;
int n;

vector<int> G[100005];
int aG[3005][3005];
int mid[100005],pre[100005],pst[100005],pos[100005],lvl[100005];

void d1(int pl,int pr,int ml,int mr){
    d1(pl)
}

void doInp(int t/*,bool j3*/){
    string s;getline(cin,s);
    stringstream ss;
    if(t==1){
        for(int i=1,t;i<=n;++i){
            getline(cin,s);
            ss.clear();ss<<s;ss>>t;
            while(ss>>t){
                G[i].push_back(t);
                // if(j3)aG[i][t]=1;
            }
        }
    }
    else if(t==2){
        for(int i=1,u,v;i<n;++i){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
            // if(j3)aG[u][v]=aG[v][u]=1;
        }
        for(int i=1;i<=n;++i)sort(G[i].begin(),G[i].end());
    }
    else if(t==3){
        for(int i=1,t;i<=n;++i){
            cin>>t;
            for(int j=1;j<=n;++j){
                cin>>aG[i][j];
                if(aG[i][j])G[i].push_back(j);
            }
        }
    }
    else if(t==4){
        map<int,int> m;
        getline(cin,s);m[1]=1;
        for(int i=2,x,y;i<=n;++i){
            cin>>x>>y;
            int p=m.find(x>>1)->second;
            G[p].push_back(y);
            G[y].push_back(p);
            // if(j3)aG[p][y]=aG[y][p]=1;
        }
    }
    else if(t==5){
        for(int i=2,t;i<=n;++i){
            cin>>t;
            G[i].push_back(t);
            G[t].push_back(i);
        }
    }
    else if(t==6){
        for(int i=1;i<=n;++i)cin>>lvl[i];
        for(int i=1;i<=n;++i){
            cin>>mid[i];
            pos[mid[i]]=i;
        }
        queue<pair<int,int>> q;
        q.push({1,n});int ptr=1;
        while(q.size()){
            if(q.top().first>q.top().second){q.pop();continue;}
            if(pos[lvl[ptr+1]]>=q.top().first && pos[lvl[ptr+1]]<=q.top().second){
                G[lvl[ptr]].push_back(lvl[ptr+1]);
                G[lvl[ptr+1]].push_back(lvl[ptr]);
                q.push({q.top().first,pos[lvl[ptr+1]]-1});
                q.push({pos[lvl[ptr+1]]+1,q.top().second});
            } //!!
            q.pop();
            ++ptr;
        }
    }
    else if(t==7){
        for(int i=1;i<=n;++i)cin>>pre[i];
        for(int i=1;i<=n;++i){
            cin>>mid[i];
            pos[mid[i]]=i;
        }
        d1(1,n,1,n);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    int I,J;cin>>I>>J;
    doInp(I/*,J==3*/);
    doOup(J);
}
