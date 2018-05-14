#include<bits/stdc++.h>
using namespace std;
#define int long long

struct cc{
    int x,y,r,i;
} c[300005];
bool operator<(const cc &a,const cc &b){
    return a.r==b.r?a.i<b.i:a.r>b.r;
}
set<cc> cs;
bitset<300005> del;
int bdel[300005];

int32_t main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>c[i].x>>c[i].y>>c[i].r;
        c[i].i=i;
    }
    while(del.count()<n){
        int mxr=0,mxi;
        for(int i=1;i<=n;++i){
            if(del[i])continue;
            if(c[i].r>mxr){
                mxr=c[i].r;
                mxi=i;
            }
        }
//        cout<<"mxi: "<<mxi<<endl;
        for(int i=1;i<=n;++i){
            if(del[i])continue;
            #define sq(x) ((x)*(x))
//            cout<<i<<" "<<sq(c[i].x-c[mxi].x)+sq(c[i].y-c[mxi].y)<<endl;
            if(sq(c[i].x-c[mxi].x)+sq(c[i].y-c[mxi].y)<=sq(mxr+c[i].r)){
                del[i]=1;
                bdel[i]=mxi;
            }
        }
    }
    for(int i=1;i<=n;++i)cout<<bdel[i]<<" ";
    cout<<endl;
}
