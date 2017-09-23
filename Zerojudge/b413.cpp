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
#define PAR(x,n) for(int ___=1;___<=(n);___++)cout<<x[___]<<" ";cout<<endl;

int rit_t,rit_k;
char rit_c;
inline int rit();

int n,m;
vint gr[50003];
int djs[50003],sz[50003];
map<int,int> mp;
int F(int a){
    if(djs[a]==a)return a;
    else return djs[a]=F(djs[a]);
}
void U(int a,int b){
    a=F(a),b=F(b);
    if(a==b)return;
    if(sz[b]>sz[a])swap(a,b);
    djs[b]=a;
    sz[a]+=sz[b];
    return;
}
void init(){
    for(int i=1;i<=n;++i){
        djs[i]=i;
        sz[i]=1;
        gr[i].clear();
    }
}
int C(){
    int ans=0;
    for(int i=1;i<=n;++i){
        mp.clear();
        for(int j=0;j<S(gr[i]);++j){
            ++mp[F(gr[i][j])];
        }
        for(auto it:mp){
            // cout<<"checking map: "<<it.X<<" "<<it.Y<<endl;
            ans+=(it.Y)*(it.Y-1)/2;
        }
    }
    return ans;
}
int main(){
    int ts=rit();
    while(ts--){
        n=rit(),m=rit();
        init();
        for(int i=1,t;i<=n;++i){
            t=rit();
            gr[t].PB(i);
        }
        while(m--){
            // cout<<"time left: "<<m<<endl;
            int a=rit(),b=rit();
            U(a,b);
            // PAR(djs,n);
            printf("%d\n",C());
        }
    }
}

inline int rit(){
    rit_t=0,rit_k=1;
    do{
        rit_c=getchar();
        if(rit_c=='-')rit_k=-1;
    }while(rit_c<'0'||rit_c>'9');
    do{
        rit_t=rit_t*10+rit_c-'0';
        rit_c=getchar();
    }while(rit_c>='0'&&rit_c<='9');
    return rit_t*rit_k;
}
