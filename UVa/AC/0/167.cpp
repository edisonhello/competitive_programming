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
}

int m[10][10],pos[10],mx;
bool s1[20],s2[20];

void rec(){
    int cur=0;
    for(int i=1;i<=8;i++){
        cur+=m[i][pos[i]];
    }
    mx=max(cur,mx);
    // cout<<", ans="<<cur<<endl;
}

void p(int n){
    if(n==9){
        // cout<<", pos=";
        // for(int i=1;i<=8;i++)cout<<pos[i]<<" ";
        rec();
        return;
    }
    for(int i=1;i<=8;i++){
        if(!pos[i] && !s1[i+n] && !s2[i-n+8]){
            pos[i]=n;
            s1[i+n]=1;
            s2[i-n+8]=1;
            p(n+1);
            pos[i]=0;
            s1[i+n]=0;
            s2[i-n+8]=0;
        }
    }
}

void sol(){
    for(int i=1;i<=8;i++){
        pos[i]=1;
        s1[i+1]=1;
        s2[i-1+8]=1;
        p(2);
        pos[i]=0;
        s1[i+1]=0;
        s2[i-1+8]=0;
    }
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int k=rit();
    while(k--){
        memset(m,0,sizeof(m));
        memset(pos,0,sizeof(pos));
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        mx=0;
        for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                m[i][j]=rit();
            }
        }
        sol();
        printf("%5d\n",mx);
        // cout<<mx<<endl;
    }
}
