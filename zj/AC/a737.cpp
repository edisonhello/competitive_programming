#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define rz(x) reserve(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;


int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    int ts;cin>>ts;
    int a[505]={0};
    cin.ignore();
    while(ts--){
        MS0(a);
        string s;
        getline(cin,s);
        stringstream ss(s);
        int t,n=0;
        ss>>t;
        while(ss>>t){
            a[n++]=t;
        }
        sort(a,a+n);
        // cout<<a[0]<<a[1]<<a[2]<<endl;
        int ans=0;
        for(int i=0;i<(n)/2;i++){
            ans+=(a[n-1-i]-a[i]);
        }
        cout<<ans<<endl;
    }
}
