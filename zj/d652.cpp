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

int a[55];
bool b[55];
ll dpa[55][55];

ll dp(int l,int r){
    // cout<<"dping: "<<l<<" "<<r<<endl;
    if(l==r-2){
        dpa[l][r]=a[l]*a[l+1]*a[r];
    }
    if(l==r-1){
        return 0;
    }
    if(!dpa[l][r]){
        ll mn=(1ll<<40);
        for(int m=l+1;m<r;m++){
            mn = min(mn,dp(l,m)+dp(m,r)+a[l]*a[m]*a[r]);
        }
        dpa[l][r]=mn;
    }
    return dpa[l][r];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    dp(1,n);

    // cout<<"dpa :\n";
    // for(int i=1;i<=n;i++){
        // for(int j=1;j<=n;j++){
            // cout<<dpa[i][j]<<" ";
        // }
        // cout<<endl;
    // }

    cout<<dpa[1][n]<<endl;
}
