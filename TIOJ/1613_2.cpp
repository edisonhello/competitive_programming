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

ll n,t,t1,t2;
ll ans;

priority_queue<ll,vector<ll>, greater<ll> > pq;

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    n=rit();
    for(int i=0;i<n;i++){
        t=rit();
        pq.push(t);
    }

    while(pq.size()>1){
        t1=pq.top();pq.pop();
        t2=pq.top();pq.pop();
        pq.push(t1+t2);
        ans+=t1+t2;
    }
    cout<<ans<<endl;
}
