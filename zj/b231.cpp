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

inline ll rit(){
    ll t=0,k=1;
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

int a[1005],b[1005];
vector<pii> v;
int ov[1005];

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int n=rit();
    for(int i=0;i<n;i++){
        int q=rit(),qq=rit();
        v.push_back({q,qq});
    }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    int t=0;
    for(int i=0;i<n;i++){
        ov[i]=t+v[i].X+v[i].Y;
        t+=v[i].X;
    }
    int mx=-9;
    for(int i=0;i<n;i++){
        mx=max(ov[i],mx);
    }
    cout<<mx<<endl;
}
