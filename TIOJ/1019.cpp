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

int d[1005],dp[1005];

int main(){
    int t=rit();
    while(t--){
        memset(d,0,sizeof(d));
        int n=rit();
        for(int i=1;i<=n;i++){
            int t=rit();
            d[t]=i;
        }

        for(int i=1;i<=n;i++)cout<<d[i]<<" ";cout<<endl;

        dp[2]=abs(d[2]-d[1]);
        for(int i=3;i<=n;i++){
            dp[i]=min(dp[i-1]+abs(d[i-1]-d[i]),dp[i-2]+abs(d[i-2]-d[i]));
        }
        cout<<dp[n]<<endl;
    }
}
