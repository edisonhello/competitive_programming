#pragma GCC optimize("Ofast,no-stack-protector")
#pragma comment(linker,"/STACK:36777216")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<cstdio>
#include<vector>
#include<utility>
using namespace std;
#define X first
#define Y second

inline char gtx(){
    const int N=1048576;
    static char __buffer[N];
    static char *__p=__buffer,*__end=__buffer;
    if(__p==__end){
        if((__end=__buffer+fread(__buffer,1,N,stdin))==__buffer)return EOF;
        __p=__buffer;
    } return *__p++;
}

template<typename T>
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=getchar(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=getchar(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

int dp[202][202],smdp[202][202];
int req[202];
int main(){
    unsigned int t,n,m; rit(t); while(t--){
        rit(n,m);
        for(register unsigned int i=1;i<=n;++i)rit(req[i]);
        for(register unsigned int le=1,j,i,ii,jj,ll,rr,iii,slp;le<=n;++le){
            for(i=1,j=le;j<=n;++i,++j){
                if(le==1)dp[i][j]=1;
                else{
                    dp[i][j]=10101;
                    bool allsame=1;
                    for(ii=i+1;ii<=j;++ii)if(req[ii]!=req[ii-1]){allsame=0; break;}
                    if(allsame)dp[i][j]=1;
                    else{
                        {
                            ll=i+1; while(req[ll]==req[ll-1])++ll;
                            rr=j; while(req[rr]==req[i])--rr;
                            dp[i][j]=min(dp[i][j],dp[ll][rr]+1);
                        }
                        {
                            rr=j-1; while(req[rr]==req[rr+1])--rr;
                            ll=i; while(req[ll]==req[j])++ll;
                            dp[i][j]=min(dp[i][j],dp[ll][rr]+1);
                        }
                        {
                            for(slp=i;slp<j;++slp)dp[i][j]=min(dp[i][j],dp[i][slp]+dp[slp+1][j]);
                        }
                        if(req[i]==req[j]){
                            ii=i,jj=j; while(req[ii]==req[i])++ii; while(req[jj]==req[j])--jj;
                            vector<pair<int,int>> seg;
                            iii=ii; while(iii<=jj){
                                while(req[iii]!=req[i])++iii;
                                seg.emplace_back(ii,iii-1);
                                while(req[iii]==req[i] && iii<=jj)++iii;
                                ii=iii;
                            }
                            for(register unsigned int le=1,i,j,slp;le<=seg.size();++le){
                                for(i=0,j=le-1;j<seg.size();++i,++j){
                                    if(i==j)smdp[i][j]=dp[seg[i].X][seg[i].Y];
                                    else{
                                        smdp[i][j]=dp[seg[i].X][seg[j].Y];
                                        for(slp=i;slp<j;++slp){
                                            smdp[i][j]=min(smdp[i][j],smdp[i][slp]+smdp[slp+1][j]);
                                        }
                                    }
                                    // cout<<"smdp "<<i<<" "<<j<<" "<<smdp[i][j]<<endl;
                                }
                            }
                            dp[i][j]=min(dp[i][j],1+smdp[0][seg.size()-1]);
                        }
                    }
                }
                // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        printf("%d\n",dp[1][n]);
    }
}
