#include<iostream>
#include"lib1945.h"
#include<algorithm>
#include<cstring>
#define M ((L+R)>>1)
using namespace std;
const int MX=(1<<17);

bool ans[MX+17];
int pre[MX+17];
int Q[MX+17];

int main(){
    // while(1){
        memset(ans,0,sizeof(ans));
        memset(pre,0,sizeof(pre));
        memset(Q,0,sizeof(Q));
        Init();
        for(int i=0;i<MX;++i){
            Q[0]=i;
            ans[i]=Query(1,Q);
            if(i)pre[i]+=pre[i-1];
            pre[i]+=ans[i];
            pre[i]&=1;
        }
        // cout<<"pre :";for(int i=0;i<MX;++i)cout<<" "<<pre[i];cout<<endl;

        int L=0,R=MX-1;
        while(L<R){
            // cout<<L<<" "<<M<<" "<<R<<endl;
            int rng=M-L;
            for(int i=L,j=0;i<=M;++i,++j){
                Q[j]=i;
            }
            int rt=Query(rng+1,Q);
            // cout<<((L?pre[L-1]:0)&1)<<" "<<(pre[M]&1)<<endl;
            if(rt!=(((L?pre[L-1]:0)&1)^(pre[M]&1))){
                R=M;
            }
            else L=M+1;
        }
        Q[0]=L;
        int o[3]={ans[L],Query(1,Q),Query(1,Q)};
        sort(o,o+3);
        ans[L]=o[1];
        for(int i=0;i<MX;++i){
            if(i)cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;
        // if(Give(ans))return 0;
    // }
}
