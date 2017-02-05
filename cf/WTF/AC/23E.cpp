#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> G[300005];
int sz[300005],deg[300005];
bool ali[300005];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); // no this->TLE
    int n;cin>>n;n*=3;
    for(int i=1,s,t;i<n;++i){
        cin>>s>>t;
        G[s].push_back(t);
        G[t].push_back(s);
        ++deg[s],++deg[t];
    }
    queue<int> leaf;
    for(int i=1;i<=n;++i){
        sz[i]=1;ali[i]=1;
        if(G[i].size()==1u){
            leaf.push(i);
        }
    }
    while(leaf.size()){
        int f=leaf.front();leaf.pop();
        int p=-1;
        for(auto &i:G[f]){
            if(ali[i]){
                p=i;break;
            }
        }
        ali[f]=0;--deg[p];
        sz[p]+=sz[f];
        if(deg[p]==1){
            if(sz[p]==3){
                ali[p]=0;
            }
            else if(sz[p]>3){
                cout<<"No\n";
                return 0;
            }
            else if(sz[p]<3){
                leaf.push(p);
            }
        }
    }
    cout<<"Yes\n";
}
