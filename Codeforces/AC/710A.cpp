#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2

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

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    string s;

    cin>>s;
    char c=s[0];
    int i=s[1]-'0';

    bool _=0,__=0;
    if(c=='a'||c=='h')_=1;
    if(i==1||i==8)__=1;

    if(_&&__)cout<<3;
    else if(_^__)cout<<5;
    else cout<<8;
    cout<<endl;
}
