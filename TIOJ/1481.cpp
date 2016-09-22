#include<bits/stdc++.h>
#include"lib1481.h"
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue

inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
}

int n,k,cnt;
vector<pair<int,int> > G;
int mp[2005][2005];
int num[20005];
bool gone[2005];

// void Init(){}
// void Possible(){}
// void Number(int x){cout<<x<<endl;}
// void Finish(){}

int F(int x,int y){
    // cout<<"F,"<<x<<" "<<y<<endl;
    if(x>y)swap(x,y);
    for(int i=0;i<k;i++){
        if(G[i].X==x && G[i].Y==y){
            return i;
        }
    }
}

void dfs(int now){
    for(int i=1;i<=n;i++){
        if(mp[now][i] && !gone[i]){
            gone[i]=1;
            int f=F(now,i);
            num[f]=num[f]?num[f]:cnt++;
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(mp[now][i]){
            int f=F(now,i);
            num[f]=num[f]?num[f]:cnt++;
        }
    }
}

int main(){
    Init();
    n=rit(),k=rit();
    for(int i=0;i<k;i++){
        int st=rit(),ed=rit();
        if(ed<st)swap(ed,st);
        G.push_back({st,ed});
        mp[st][ed]=mp[ed][st]=1;
    }
    // for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<mp[i][j]<<" ";cout<<endl;}
    Possible();
    gone[1]=1;
    cnt=1;
    dfs(1);
    for(int i=0;i<k;i++){
        Number(num[i]);
    }
    Finish();
}
