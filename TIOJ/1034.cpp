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

int n,mp[22][22],rdp[22][22][22][22][22][22],ldp[22][22][22][22][22][22];

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);
    n=rit();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mp[i][j]=rit();
        }
    }
    for(int i=0;i<=n+1;i++){
        mp[0][i]=mp[i][0]=0x7f7f7f7f;
    }
    for(int jx=1;jx<=n;jx++){
        for(int jy=1;jy<=n;jy++){
            for(int sx=1;sx<=n;sx++){
                for(int sy=1;sy<=n;sy++){
                    for(int ex=sx;ex<=n;ex++){
                        for(int ey=sy;ey<=n;ey++){
                            if(ex==sx&&ey==sy)continue;
                            if(jx==ex&&jy==ey){
                                if(ex>sx&&ey>sy)rdp[jx][jy][sx][sy][ex][ey]=min(rdp[jx][jy][sx][sy][ex-1][ey],rdp[jx][jy][sx][sy][ex][ey-1]);
                                else if(ex>sx)rdp[jx][jy][sx][sy][ex][ey]=rdp[jx][jy][sx][sy][ex-1][ey];
                                else if(ey>sy)rdp[jx][jy][sx][sy][ex][ey]=rdp[jx][jy][sx][sy][ex][ey-1];
                            }
                            else{
                                if(ex>sx&&ey>sy)rdp[jx][jy][sx][sy][ex][ey]=min(rdp[jx][jy][sx][sy][ex-1][ey]+mp[ex][ey],rdp[jx][jy][sx][sy][ex][ey-1]+mp[ex][ey]);
                                else if(ex>sx)rdp[jx][jy][sx][sy][ex][ey]=rdp[jx][jy][sx][sy][ex-1][ey]+mp[ex][ey];
                                else if(ey>sy)rdp[jx][jy][sx][sy][ex][ey]=rdp[jx][jy][sx][sy][ex][ey-1]+mp[ex][ey];
                            }
                            // printf("rdp[%d][%d][%d][%d][%d][%d]=%d\n",jx,jy,sx,sy,ex,ey,rdp[jx][jy][sx][sy][ex][ey]);
                        }
                    }
                    for(int ex=sx;ex<=n;ex++){
                        for(int ey=sy;ey>0;ey--){
                            if(ex==sx&&ey==sy)continue;
                            if(jx==ex&&jy==ey){
                                if(ex>sx&&ey<sy)ldp[jx][jy][sx][sy][ex][ey]=min(ldp[jx][jy][sx][sy][ex-1][ey],ldp[jx][jy][sx][sy][ex][ey+1]);
                                else if(ex>sx)ldp[jx][jy][sx][sy][ex][ey]=ldp[jx][jy][sx][sy][ex-1][ey];
                                else if(ey<sy)ldp[jx][jy][sx][sy][ex][ey]=ldp[jx][jy][sx][sy][ex][ey+1];
                            }
                            else{
                                if(ex>sx&&ey<sy)ldp[jx][jy][sx][sy][ex][ey]=min(ldp[jx][jy][sx][sy][ex-1][ey]+mp[ex][ey],ldp[jx][jy][sx][sy][ex][ey+1]+mp[ex][ey]);
                                else if(ex>sx)ldp[jx][jy][sx][sy][ex][ey]=ldp[jx][jy][sx][sy][ex-1][ey]+mp[ex][ey];
                                else if(ey<sy)ldp[jx][jy][sx][sy][ex][ey]=ldp[jx][jy][sx][sy][ex][ey+1]+mp[ex][ey];
                            }
                            // printf("ldp[%d][%d][%d][%d][%d][%d]=%d\n",jx,jy,sx,sy,ex,ey,rdp[jx][jy][sx][sy][ex][ey]);
                        }
                    }
                }
            }
        }
    }
    int q=rit();
    while(q--){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        if(x1>x2){swap(x1,x2);swap(y1,y2);}
        int mn=0x7fffffff;
        if(y1<y2){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    mn=min(mn,rdp[i][j][x1][y1][x2][y2]+((i==x1&&j==y1)?0:mp[x1][y1]));
                    // cout<<x1<<" "<<y1<<" "<<rdp[i][j][x1][y1][x2][y2]<<" "<<((i==x1&&j==y1)?0:mp[x1][y1])<<" "<<i<<" "<<j<<" "<<mn<<endl;
                }
            }
        }
        else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    mn=min(mn,ldp[i][j][x1][y1][x2][y2]+((i==x1&&j==y1)?0:mp[x1][y1]));
                    // cout<<x1<<" "<<y1<<" "<<ldp[i][j][x1][y1][x2][y2]<<" "<<((i==x1&&j==y1)?0:mp[x1][y1])<<" "<<i<<" "<<j<<" "<<mn<<endl;
                }
            }
        }
        printf("%d\n",mn);
    }
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
