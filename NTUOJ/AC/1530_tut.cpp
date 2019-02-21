#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t; cin.ignore();
    while(t--){
        string s; getline(cin,s);
        stringstream ss(s);
        vector<int> a; int x;
        while(ss>>x)a.push_back(x);
        auto ok=[&](int len)->bool{
            vector<vector<int>> G(len+1);
            for(int d:a){
                if(d>0){
                    for(int i=0;i+d<=len;++i)G[i].push_back(i+d);
                }
                if(d<0){
                    for(int i=0;i-d<=len;++i)G[i-d].push_back(i);
                }
            }
            vector<int> ind(len+1,0);
            for(auto &v:G)for(int i:v)++ind[i];
            queue<int> q;
            int cq=0;
            for(int i=0;i<=len;++i)if(ind[i]==0)++cq,q.push(i);
            while(q.size()){
                int now=q.front(); q.pop();
                for(int i:G[now]){
                    --ind[i];
                    if(ind[i]==0)++cq,q.push(i);
                }
            }
            if(cq==len+1)return 1;
            return 0;
        };
        int L=0,R=2100;
        while(R>L){
            int M=(L+R+1)>>1;
            if(ok(M))L=M;
            else R=M-1;
        }
        if(L==2100)cout<<-1<<endl;
        else cout<<L<<endl;
    }
}
