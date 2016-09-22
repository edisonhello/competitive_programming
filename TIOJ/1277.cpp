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

int n,i,j,k,l;
ll a[502][502],ans,now,mx,rr[502][502];

inline void t(int &x,int &y){
    now=0,mx=0;
    for(l=1;l<=n;l++){
        now+=(rr[y][l]-rr[x-1][l]);
        if(now<0)now=0;
        mx=max(mx,now);
    }
    ans=max(mx,ans);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>a[i][j];
            for(k=1;k<=i;k++){
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
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            t(i,j);
        }
    }
    cout<<ans<<endl;
}
