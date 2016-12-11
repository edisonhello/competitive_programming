#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

bool G[65][65],v[65];
int n;
stack<int> s;
int longestPoint,longestLength;
bool inTheLongest[65];
int chainLength[65];
int dfs1(int now,int dep){
    v[now]=1;
    if(dep>longestLength){
        longestLength=dep;
        longestPoint=now;
    }
    for(int i=0;i<n;++i){
        if(G[now][i] && !v[i]){
            dfs1(i,dep+1);
        }
    }
    return 0;
}
int dfs2(int now,int dep){
    v[now]=1;
    if(dep>longestLength){
        longestLength=dep;
    }
    for(int i=0;i<n;++i){
        if(G[now][i] && !v[i]){
            dfs2(i,dep+1);
        }
    }
    return 0;
}
int dfs3(int now,int dep){
    v[now]=1;
    if(dep==longestLength){
        s.push(now);
        return 1;
    }
    for(int i=0;i<n;++i){
        if(G[now][i] && !v[i]){
            int res=dfs3(i,dep+1);
            if(res){
                s.push(now);
                return 1;
            }
        }
    }
    return 0;
}
int dfs4(int now,int dep,int head){
    v[now]=1;
    for(int i=0;i<n;++i){
        if(G[now][i] && !inTheLongest[i] && !v[i]){
            int res=dfs4(i,dep+1,0);
            if(!head)return res;
            else chainLength[res]++;
        }
    }
    return dep;
}
void sol(){
    longestPoint=longestLength=0;
    dfs1(0,1);memset(v,0,sizeof(v));
    dfs2(longestPoint,1);memset(v,0,sizeof(v));
    dfs3(longestPoint,1);memset(v,0,sizeof(v));
    while(s.size()){
        inTheLongest[s.top()]=1;
        s.pop();
    }
    for(int i=0;i<n;++i){
        if(inTheLongest[i]){
            dfs4(i,0,1);memset(v,0,sizeof(v));
        }
    }
    cout<<longestLength<<endl;
    bool anyExtraChain=0;
    for(int i=0;i<n;++i){
        if(chainLength[i]){
            anyExtraChain=1;
            cout<<"C"<<i<<":"<<chainLength[i]<<endl;
        }
    }
    if(!anyExtraChain)cout<<"No functional group\n";
}

int main(){
    while(cin>>n,n){
        memset(G,0,sizeof(G));
        memset(v,0,sizeof(v));
        memset(inTheLongest,0,sizeof(inTheLongest));
        memset(chainLength,0,sizeof(chainLength));
        while(s.size())s.pop();

        char c1,c2;
        int i1,i2;
        for(int i=0;i<n-1;++i){
            cin>>c1>>c2;
            if(c1>='A'&&c1<='Z')i1=c1-'A';
            else if(c1>='a'&&c1<='z')i1=c1-'a'+26;
            else if(c1>='0'&&c1<='9')i1=c1-'0'+52;
            if(c2>='A'&&c2<='Z')i2=c2-'A';
            else if(c2>='a'&&c2<='z')i2=c2-'a'+26;
            else if(c2>='0'&&c2<='9')i2=c2-'0'+52;
            G[i1][i2]=G[i2][i1]=1;
        }
        sol();
    }
}
