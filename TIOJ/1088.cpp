#include<bits/stdc++.h>
#include"lib1088.h"
using namespace std;

int pl[3],cp,cn;
int main(){
    Initialize(&pl[0],&pl[1],&pl[2]);
    while(1){
        if(pl[0]==0&&pl[1]==0&&pl[2]==0)assert(1==0);
        int _xor=pl[0]^pl[1]^pl[2];
        if(_xor==0){
            assert(2==1);
            for(int i=0;i<3;++i){
                if(pl[i]>0){
                    Take_Stone(i+1,pl[i],&cp,&cn);
                    pl[i]=0;
                    pl[cp-1]-=cn;
                    break;
                }
            }
        }
        else{
            for(int i=1;i<=pl[0];++i){
                if((pl[0]-i)^pl[1]^pl[2]==0){
                    pl[0]-=i;
                    Take_Stone(1,i,&cp,&cn);
                    pl[cp-1]-=cn;
                    goto nextRound;
                }
            }
            for(int i=1;i<=pl[1];++i){
                if((pl[1]-i)^pl[0]^pl[2]==0){
                    pl[1]-=i;
                    Take_Stone(2,i,&cp,&cn);
                    pl[cp-1]-=cn;
                    goto nextRound;
                }
            }
            for(int i=1;i<=pl[2];++i){
                if((pl[2]-i)^pl[1]^pl[0]==0){
                    pl[2]-=i;
                    Take_Stone(3,i,&cp,&cn);
                    pl[cp-1]-=cn;
                    goto nextRound;
                }
            }
        }
        nextRound:;
    }
}
