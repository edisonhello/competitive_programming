#include<bits/stdc++.h>
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
};

int n;
ll a[502][502];
ll ans;
ll rr[502][502];

void t(int x,int y){
    ll now=0,mx=0;
    for(int i=1;i<=n;i++){
        now+=(rr[y][i]-rr[x-1][i]);
        if(now<0)now=0;
        mx=max(mx,now);
    }
    ans=max(mx,ans);
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            for(int k=1;k<=i;k++){
                rr[i][j]+=a[k][j];
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<rr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            t(i,j);
        }
    }
    cout<<ans<<endl;
}
