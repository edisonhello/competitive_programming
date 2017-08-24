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

int main(){
    int x,y;
    cin>>x>>y;
    int a,b,c,tmp,t=0;
    a=b=c=y;

    while(!(a>=x&&b>=x&&c>=x)){
        a=b+c-1;
        t++;
        tmp=a;
        a=b;
        b=c;
        c=tmp;
    }
    cout<<t<<endl;
}
