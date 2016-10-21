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

char __c;bool __m;int __t;
inline int rit();
template<typename varType>
inline bool rit(varType &inp);
template<typename varType,typename ...Args>
inline bool rit(varType &inp,Args &...args);
int a,b,n,m[10005][10005];
bool v[10005][10005];

void bfs(int stx,int sty){
    queue<pii> q;
    q.push({stx,sty});
    while(q.size()){
        pii top=q.front();q.pop();
        if(m[top.X+1][top.Y-1]>1&&!v[top.X+1][top.Y-1]){q.push({top.X+1,top.Y-1});v[top.X+1][top.Y-1]=1;}
        if(m[top.X  ][top.Y-1]>1&&!v[top.X  ][top.Y-1]){q.push({top.X  ,top.Y-1});v[top.X  ][top.Y-1]=1;}
        if(m[top.X-1][top.Y-1]>1&&!v[top.X-1][top.Y-1]){q.push({top.X-1,top.Y-1});v[top.X-1][top.Y-1]=1;}
        if(m[top.X-1][top.Y  ]>1&&!v[top.X-1][top.Y  ]){q.push({top.X-1,top.Y  });v[top.X-1][top.Y  ]=1;}
        if(m[top.X-1][top.Y+1]>1&&!v[top.X-1][top.Y+1]){q.push({top.X-1,top.Y+1});v[top.X-1][top.Y+1]=1;}
        if(m[top.X  ][top.Y+1]>1&&!v[top.X  ][top.Y+1]){q.push({top.X  ,top.Y+1});v[top.X  ][top.Y+1]=1;}
        if(m[top.X+1][top.Y+1]>1&&!v[top.X+1][top.Y+1]){q.push({top.X+1,top.Y+1});v[top.X+1][top.Y+1]=1;}
        if(m[top.X+1][top.Y  ]>1&&!v[top.X+1][top.Y  ]){q.push({top.X+1,top.Y  });v[top.X+1][top.Y  ]=1;}
    }
}

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);
    a=rit(),b=rit(),n=rit();
    for(int i=0;i<n;++i){
        int r,c;rit(r,c);
        m[r][c]+=2;
        m[r+1][c-1]++;
        m[r][c-1]++;
        m[r-1][c-1]++;
        m[r-1][c]++;
        m[r-1][c+1]++;
        m[r][c+1]++;
        m[r+1][c+1]++;
        m[r+1][c]++;
    }
    int cnt=0;
    for(int i=1;i<=a;++i){
        for(int j=1;j<=b;++j){
            if(m[i][j]>1&!v[i][j]){
                v[i][j]=1;
                // cout<<"bfs "<<i<<" "<<j<<endl;
                bfs(i,j);
                cnt++;
            }
            // cout<<m[i][j]<<" ";
        }
        // cout<<endl;
    }
    printf("%d\n",cnt);
}


inline int rit(){
    __t=0,__m=0;
    do{
        __c=getchar();
        if(__c=='-')__m=1;
    }while((__c<'0'||__c>'9'));
    do{
        __t=__t*10+__c-'0';
        __c=getchar();
    }while(__c>='0'&&__c<='9');
    if(__m)__t=-__t;
    return __t;
}

template<typename varType,typename ...Args>
inline bool rit(varType &inp,Args &...args){
    return rit(inp)&&rit(args...);
}

template<typename varType>
inline bool rit(varType &inp){
    inp=0;__m=0;
    do{
        __c=getchar();
        if(__c==-1)return false;
        if(__c=='-')__m=1;
    }while((__c<'0'||__c>'9'));
    if(__c=='-')__m=1;
    do{
        inp=inp*10+__c-'0';
        __c=getchar();
    }while(__c>='0'&&__c<='9');
    if(__m)inp=-inp;
    return true;
}
