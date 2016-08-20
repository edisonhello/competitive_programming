#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second

int n,m,k;
vector<pair<int,int> > path[100005];
int ks[100005];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>n>>m>>k;
    if(!k){
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=0;i<m;i++){
        int from,end,cost;
        cin>>from>>end>>cost;
        path[from].PB(make_pair(end,cost));
        path[end].PB(make_pair(from,cost));
    }
    int minpath = 1e9+20;
    for(int i=0;i<k;i++){
        int sto;
        cin>>sto;
        ks[sto] = 1;
    }
    for(int i=1;i<=n;i++){
        if(ks[i]){
            for(int j=0;j<path[i].size();j++){
                if(!ks[path[i][j].X]){
                    minpath = min(minpath,path[i][j].Y);
                }
            }
        }
    }

    cout<<(minpath==1e9+20?-1:minpath)<<endl;
}
