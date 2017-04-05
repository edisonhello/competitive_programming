#include<cassert>
#include<cstdio>
// #include<cstdlib>
#include<cstring>
// #include<cmath>
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
// #include<unordered_map>
// #include<unordered_set>
#include<bitset>
#include<vector>
#include<utility>
#define abs(a) ((a)<0?-(a):(a))

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
#define endl '\n'
#define el putchar('\n')
#define spc putchar(' ')

inline int lowbit(int &x){return x&-x;}
inline ll lowbit(ll &x){return x&-x;}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

pii a[20008];
int n;
ll pre[20008],precnt[20008];

void modify(ll *BIT,ll v,int x){
    while(x<=20007){
        // cout<<"meow"<<endl;
        BIT[x]+=v;
        x+=lowbit(x);
    }
}
ll query(ll *BIT,int x,ll rt=0){
    while(x>0){
        rt+=BIT[x];
        x-=lowbit(x);
    } return rt;
}

int main(){
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i].X>>a[i].Y;
    sort(a,a+n); ll totD=0,ans=0;
    for(int i=0;i<n;++i){
        // cout<<a[i].X<<" "<<a[i].Y<<endl;
        int infront=query(precnt,a[i].Y+1);
        int inback =i-query(precnt,a[i].Y);
        ll frontDist=query(pre,a[i].Y+1);
        ll backDist =totD-query(pre,a[i].Y);

        // cout<<"totD "<<totD<<endl;
        // cout<<infront<<" "<<inback<<" "<<frontDist<<" "<<backDist<<endl;

        ans+=a[i].X*(infront*a[i].Y-frontDist + backDist-inback*a[i].Y);

        totD+=a[i].Y;
        modify(pre,a[i].Y,a[i].Y+1);
        modify(precnt,1,a[i].Y+1);
    }
    // pln(ans);el;
    cout<<ans<<endl;
}
