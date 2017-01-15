#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int G[15][15],bt[15][15],want[15];

vector<int> nowmnl,tmp;
int mn;

bool cmp(){
    for(int i=0;i<(int)min(nowmnl.size(),tmp.size());++i){
        if(tmp[i]<nowmnl[i]){
            nowmnl=tmp;
            return 1;
        }
        if(tmp[i]>nowmnl[i])return 0;
    }
    if(tmp.size()<nowmnl.size()){nowmnl=tmp;return 1;}
}
void BT(int i,int j){
    tmp.push_back(i);
    while(bt[i][j]!=j){
        // cout<<i<<" "<<j<<" "<<bt[i][j]<<endl;
        i=bt[i][j];
        tmp.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    int m;cin>>m;
    while(m--){
        int a,b,t;cin>>a>>b>>t;
        G[a][b]=G[b][a]=t;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(!G[i][j])G[i][j]=11111111;
            bt[i][j]=j;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i==j){G[i][j]=0;continue;}
            for(int k=0;k<n;++k){
                if(G[i][k]+G[k][j]<G[i][j]){
                    G[i][j]=G[i][k]+G[k][j];
                    bt[i][j]=k;
                }
            }
        }
    }

    // for(int i=0;i<n;++i){
    //     for(int j=0;j<n;++j){
    //         cout<<G[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<n;++j){
    //         cout<<bt[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int k;cin>>k;
    for(int i=0;i<k;++i)cin>>want[i];
    sort(want+1,want+k);
    mn=0x7f7f7f7f;
    do{
        // cout<<"af"<<endl;
        tmp.clear();
        int len=0;
        for(int i=1;i<k;++i){
            BT(want[i-1],want[i]);
            len+=G[want[i-1]][want[i]];
        }
        tmp.push_back(want[k-1]);
        if(len<mn){
            nowmnl=tmp;
            mn=len;
        }
        else if(len==mn){
            if(cmp())mn=len;
        }
    }while(next_permutation(want+1,want+k));

    cout<<"Minimum travel distance: "<<mn<<endl<<"Travel route:";
    for(int i:nowmnl)cout<<" "<<i;cout<<endl;
}
