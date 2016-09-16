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
};

int n;
int a[1000009];
int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    n=rit();
    for(int i=0;i<n;i++)a[i]=rit();
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(i)putchar_unlocked(' ');
        printf("%d",a[i]);
    }
    putchar_unlocked('\n');
}
