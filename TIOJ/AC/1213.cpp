
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define X first
#define Y second
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
// typedef struct { int m, k; int *x, *y, *len; } MAP;

int n;
vector<pair<int,int>> G[100006];

int longestrd,longestn;
bool gone[1000006];
void dfs(int now,int len){
    // cout<<"dfs:"<<now<<" "<<len<<endl;
    if(len>longestrd){
        longestrd=len;
        longestn=now;
        // cout<<"update longest n:"<<longestn<<" ,length="<<longestrd<<endl;
    }
    for(int i=0;i<G[now].size();i++){
        if(!gone[G[now][i].X]){
            gone[G[now][i].X]=1;
            dfs(G[now][i].X,len+G[now][i].Y);
        }
    }
}
inline int findL(int st){
    memset(gone,0,sizeof(gone));
    gone[st]=1;
    longestrd=-99;
    longestn=-1;
    dfs(st,0);
    // cout<<"found farest1:"<<longestn<<endl;
    memset(gone,0,sizeof(gone));
    gone[longestn]=1;
    longestrd=-99;
    dfs(longestn,0);
    // cout<<"found longestrd:"<<longestrd<<endl;
    return longestrd;
}
int rit_t,rit_k;
char rit_c;

inline int rit(){
    rit_t=0,rit_k=1;
    do{
        rit_c=getchar_unlocked();
        if(rit_c=='-')rit_k=-1;
    }while(rit_c<'0'||rit_c>'9');
    do{
        rit_t=rit_t*10+rit_c-'0';
        rit_c=getchar_unlocked();
    }while(rit_c>='0'&&rit_c<='9');
    return rit_t*rit_k;
}


int main(){
    while(scanf("%d",&n)&&n){
        for(int i=1;i<=n;++i)G[i].clear();
        for(int l=0;l<n-1;++l){
            int i=rit(),j=rit(),c=rit();
            G[i].push_back({j,c});
            G[j].push_back({i,c});
        }
        printf("%d\n",findL(1));
    }
}
