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
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
};

int n,m,l,q;
vector<int> s[10002];
bool jizz[10002];

bool track(int y){
    if(jizz[y])return 1;
    for(int i=0;i<(int)s[y].size();i++){
        if(track(s[y][i])){return 1;}
    }
    return 0;
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    n=rit(),m=rit(),l=rit(),q=rit();
    for(int i=0;i<m;i++){
        int a=rit(),b=rit();
        s[b].PB(a);
    }
    for(int i=0;i<l;i++){
        int x=rit();
        jizz[x]=1;
    }
    for(int i=0;i<q;i++){
        int y=rit();
        if(track(y)){
            cout<<"TUIHUOOOOOO\n";
        }
        else{
            cout<<"YA~~\n";
        }
    }
}
