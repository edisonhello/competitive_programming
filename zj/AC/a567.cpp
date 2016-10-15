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

struct w{
    int d,p;
};
bool operator<(const w &a,const w &b){
    return a.p<b.p;
}
bool operator>(const w &a,const w &b){
    return a.p>b.p;
}
int n,fullto;
PQ<w,vector<w>,less<w>> pq;
bitset<10005> us;
ll ans;
bool PUT(int da){
    for(int i=da;i>=0&&i>fullto;i--){
        if(us[i]==0){
            us[i]=1;
            return 1;
        }
    }
    fullto=max(fullto,da);
    return 0;
}
int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin>>n){
        while(pq.size())pq.pop();
        us.reset();
        ans=0;
        fullto=0;
        for(int i=0;i<n;i++){
            int d,p;
            cin>>d>>p;
            pq.push({d,p});
        }
        while(pq.size()){
            w now=pq.top();pq.pop();
            // cout<<"work: "<<now.d<<" "<<now.p<<endl;
            if(PUT(now.d)){
                ans+=now.p;
                // cout<<"puted\n";
            }
        }
        cout<<ans<<endl;
    }
}
