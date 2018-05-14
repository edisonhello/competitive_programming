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
int bdel[300005],nxt[300005],prv[300005],per[300005];

int32_t main(){
    int n; cin>>n;
    vector<int> nums;
    for(int i=1;i<=n;++i){
        cin>>c[i].x>>c[i].y>>c[i].r;
        c[i].i=i;
    }
    sort(c+1,c+1+n,[](const cc &a,const cc &b){return a.x<b.x;});
    for(int i=1;i<=n;++i)nxt[i]=i+1,prv[i]=i-1,per[i]=i;
    sort(per+1,per+1+n,[&](const int &a,const int &b){return c[a].r==c[b].r?c[a].i<c[b].i:c[a].r>c[b].r;});
    for(int p=1;p<=n;++p){
        int i=per[p];
        if(del[c[i].i])continue;
        int le=prv[i];
        while(le>0 && c[le].x>=c[i].x-2*c[i].r){
            if(c[le].x+c[le].r>=c[i].x-c[i].r){
                bdel[c[le].i]=c[i].i;
                del[c[le].i]=1;
                nxt[prv[le]]=nxt[le];
                prv[nxt[le]]=prv[le];
            }
            le=prv[le];
        }
        int ri=nxt[i];
        while(ri<=n && c[ri].x<=c[i].x+2*c[i].r){
            if(c[ri].x-c[ri].r<=c[i].x+c[i].r){
                bdel[c[ri].i]=c[i].i;
                del[c[ri].i]=1;
                nxt[prv[ri]]=nxt[ri];
                prv[nxt[ri]]=prv[ri];
            }
            ri=nxt[ri];
        }
        bdel[c[i].i]=c[i].i;
        del[c[i].i]=1;
        nxt[prv[i]]=nxt[i];
        prv[nxt[i]]=prv[i];
    }

    for(int i=1;i<=n;++i)cout<<bdel[i]<<" ";
    cout<<endl;
}
