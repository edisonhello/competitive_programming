#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define X first
#define Y second
#define S(x) (int)(x).size()
#define rz(x) reserve(x)
#define PB(x) push_back(x)
#define pii pair<int,int>
#define vint vector<int>
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define SS stringstream
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
// #define getchar getchar_unlocked
// #define putchar putchar_unlocked
#define PVC(x) for(auto ___:(x))cout<<___<<" ";cout<<endl;
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

int n;ll m;
ll _p[15];
bitset<15> ap;
int findN(int s){
    for(int i=0,now=1;i<n;i++){
        if(ap[i])continue;
        if(now==s){
            ap[i]=1;
            return i;
        }
        ++now;
    }
}
int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    _p[0]=1;
    for(int i=1;i<=12;++i){
        _p[i]=_p[i-1]*i;
    }
    while(cin>>n>>m,n){
        ap.reset();
        m%=_p[n];if(m==0)m+=_p[n];
        for(int i=0;i<n;i++){
            if(i)cout<<" ";
            int cnt=(int)(m/_p[n-1-i])+1;
            // cout<<cnt<<endl;
            m%=_p[n-1-i];if(m==0){m+=_p[n-1-i];cnt--;}
            cout<<(char)('A'+findN(cnt));
        }
        cout<<'\n';
    }
}
