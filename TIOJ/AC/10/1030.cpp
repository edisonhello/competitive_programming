#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) reserve(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue

int r[100005];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    while(cin>>n && n){
        for(int i=0;i<n;i++){
            cin>>r[i];
        }
        sort(r,r+n);
        ll ans=0;
        ans=1;
        for(int i=0;i<n;i++){
            // cout<<r[i]<<endl;
            ans+=r[i];
        }
        ans+=r[n-1];
        cout<<ans<<'\n';
    }
}
