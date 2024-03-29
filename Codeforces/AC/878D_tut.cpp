#include<bits/stdc++.h>
using namespace std;

int crea[15][100005];
bitset<12> chai[15][100005];
// bitset<100005> meow[1<<12];
bitset<(1<<12)> meow[100005];
int type[15][100005];
vector<int> num[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,q; cin>>n>>k>>q;
    for(int i=1;i<=k;++i){
        for(int j=1;j<=n;++j){
            cin>>crea[i][j];
            num[j].push_back(crea[i][j]);
        }
    }
    for(int j=1;j<=n;++j){
        sort(num[j].begin(),num[j].end()); 
        for(int i=1;i<=k;++i){
            chai[i][j]=(1<<(lower_bound(num[j].begin(),num[j].end(),crea[i][j])-num[j].begin()))-1;
        }
    }
    for(int z=0;z<k;++z){
        for(int j=1;j<=n;++j){
            int v=0;
            for(int i=1;i<=k;++i){
                if(chai[i][j][z])v|=1<<(i-1);
            }
            // if(smp[z][v])smp[z][v]=j;
            // idx[z][j]=prv[z][v];
            type[z][j]=v;
            // cout<<"type of bit "<<z<<" of cha "<<j<<" type "<<v<<endl;
        }
    }
    for(int z=0;z<(1<<k);++z){
        for(int i=0;i<k;++i){
            // meow[z][i+1]=!!(z&(1<<i));
            meow[i+1][z]=!!(z&(1<<i));
            // cout<<"meow["<<z<<"]["<<i+1<<"]="<<meow[z][i+1]<<endl;
        }
        // cout<<"meow["<<z<<"]="<<meow[z]<<endl;
    }
    int ptr=k;

    while(q--){
        int t,x,y; cin>>t>>x>>y;
        if(t==1){
            ++ptr;
            meow[ptr]=meow[x]|meow[y];
        }
        else if(t==2){
            ++ptr;
            meow[ptr]=meow[x]&meow[y];
        }
        else{
            int ans=0;
            for(int i=0;i<k;++i)ans+=meow[x][type[i][y]];
            cout<<num[y][ans]<<'\n';
        }
    }
}
