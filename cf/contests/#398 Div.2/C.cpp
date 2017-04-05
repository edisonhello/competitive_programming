#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<vector>
#include<utility>

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define LN(x) ((int)(x).length())
#define rz(x) resize(x)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
#define endl '\n'
#define el putchar('\n')
#define spc putchar(' ')


int n,root=0,tott=0;
int p[1000006],t[1000006],ind[1000006],ans[5];
vint G[1000006];
queue<int> lf;
bool jizz=0;

void dfs(int now){
    for(int i:G[now]){
        dfs(i);
        t[now]+=t[i];
    }
    if(t[now]>tott/3){jizz=1;return;}
    if(t[now]==tott/3 && now!=root && !ans[1]){
        if(ans[0])ans[1]=now;
        else ans[0]=now;
        t[now]=0;
    }
}

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;++i){
        cin>>p[i]>>t[i];
        if(!p[i])root=i;
        tott+=t[i];
        G[p[i]].pb(i);
    }
    if(tott%3!=0)return cout<<-1<<endl,0;
    dfs(root);
    if(ans[1] && !jizz){
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    else cout<<-1<<endl;
}
// 24766710 76:44 WA 3
// 24769626 95:18 WA 3
// 24772770 113:55 WA 3
// 24773048 115:24 WA 3
// 24774243 119:50 WA 3
