#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int p[5],q[5],c[5];
int dpp[880009],dpq[880009];

int main(){
    ios_base::sync_with_stdio(0);
    c[0]=1,c[1]=5,c[2]=10,c[3]=20,c[4]=50;
    int ts;cin>>ts;while(ts--){
        int C;cin>>C;
        for(int i=0;i<5;++i)cin>>p[i];
        for(int i=0;i<5;++i)cin>>q[i];
        int MXM=p[0]*c[0]+p[1]*c[1]+p[2]*c[2]+p[3]*c[3]+p[4]*c[4];
        int coins=p[0]+p[1]+p[2]+p[3]+p[4],mincoin=coins;
        memset(dpp,0xff,sizeof(dpp));
        memset(dpq,0x77,sizeof(dpq));
        dpq[0]=0;dpp[0]=0;
        for(int i=0;i<5;++i){
            for(int j=1;j<=p[i];++j){
                for(int k=MXM;k>=j*c[i];--k){
                    dpp[k]=max({dpp[k],dpp[k-c[i]]+1});
                }
                // cout<<"P: ";for(int i=0;i<=25;++i)cout<<dpp[i]<<" ";cout<<endl;
            }
            for(int j=1;j<=q[i];++j){
                for(int k=j*c[i];k<=MXM;++k){
                    dpq[k]=min({dpq[k],dpq[k-j*c[i]]+1});
                }
            }
        }

        // cout<<"P: ";for(int i=0;i<=25;++i)cout<<dpp[i]<<" ";cout<<endl;
        // cout<<"Q: ";for(int i=0;i<=25;++i)cout<<dpq[i]<<" ";cout<<endl;

        for(int i=C;i<=MXM;++i){
            mincoin=min(mincoin,coins-dpp[i]+dpq[i-C]);
        }
        cout<<mincoin<<endl;
    }
}
