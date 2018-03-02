#include<bits/stdc++.h>
using namespace std;
#define ll long long

int h[12];
vector<int> tetro[8]={
    {4},
    {1,1,1,1},
    {2,2},
    {1,2,1},
    {1,3},
    {2,1,1},
    {3,1},
    {1,1,2}
};

vector<pair<char,int>> ans;
set<ll> vis;

bool dfs(int ptr,int mx){
    if(ptr>10)return 1;
    ll hhh=0;
    for(int i=1;i<=10;++i)hhh=hhh*16+h[i];
    ////  cout<<hhh<<endl;
    if(vis.find(hhh)!=vis.end())return 0;
    vis.insert(hhh);
    for(int i=0;i<8;++i){
        // cout<<i<<" "<<ptr+tetro[i].size()<<endl;
        if(ptr+tetro[i].size()-1>10)continue;
        bool ok=1;
        for(int j=0;j<tetro[i].size();++j){
            if(h[ptr+j]+tetro[i][j]>mx){ok=0; break;}
        }
        if(ok){
            for(int j=0;j<tetro[i].size();++j){
                h[ptr+j]+=tetro[i][j];
            }
            ans.emplace_back(i+'A',ptr);
            /* {
                cout<<"trying put "<<(char(i+'A'))<<" in "<<ptr<<" , now h: ";
                for(int i=1;i<=10;++i)cout<<h[i]<<" "; cout<<endl;
            } */
            int pptr=ptr;
            while(pptr<=10 && h[pptr]==mx)++pptr;
            // cout<<"new pptr is "<<pptr<<endl;
            if(dfs(pptr,mx))return 1;
            ans.pop_back();
            for(int j=0;j<tetro[i].size();++j){
                h[ptr+j]-=tetro[i][j];
            }
        }
    }
    return 0;
}

void go(int mx){
    int pptr=1;
    while(pptr<=10 && h[pptr]==mx)++pptr;
    if(dfs(pptr,mx)){
        cout<<ans.size()<<endl;
        for(auto i:ans)cout<<i.first<<" "<<i.second<<'\n';
        exit(0);
    }
}

int main(){
    for(int i=1;i<=10;++i)cin>>h[i];
    int maxh=0;
    for(int i=1;i<=10;++i)maxh=max(maxh,h[i]);
    /* for(int i=1;i<=10;++i){
        while(h[i]+4<maxh){
            ans.emplace_back('A',i);
        }
    } */
    for(;;++maxh){
        // cout<<maxh<<endl;
        go(maxh);
        vis.clear();
    }
}
