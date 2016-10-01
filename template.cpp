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
#define S0(x) memset((x),0,sizeof(x))
#define SB(x) memset((x),0x7f,sizeof(x))

inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar_unlocked();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar_unlocked();
    }while(c>='0'&&c<='9');
    return t*k;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
}
