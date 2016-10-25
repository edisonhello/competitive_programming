#include<bits/stdc++.h>
#include"lib1088.h"
using namespace std;

int pl[3],cp,cn;
int main(){
    Initialize(&pl[0],&pl[1],&pl[2]);
    while(1){
        if(pl[0]==0&&pl[1]==0&&pl[2]==0)assert(1==0);
        int _xor=0;
        for(int i=1;i<=max({pl[0],pl[1],pl[2]});i<<=1){
            _xor+=i&(pl[0]^pl[1]^pl[2]);
        }
        if(_xor==0){
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
            int new_xor=0;
            for(int i=1;i<=max({pl[0]-_xor,pl[1],pl[2]});i<<=1){
                new_xor+=i&((pl[0]-_xor)^pl[1]^pl[2]);
            }
            if(new_xor==0&&pl[0]-_xor>=0){
                pl[0]-=_xor;
                Take_Stone(1,_xor,&cp,&cn);
                pl[cp-1]-=cn;
                continue;
            }
            new_xor=0;
            for(int i=1;i<=max({pl[0],pl[1]-_xor,pl[2]});i<<=1){
                new_xor+=i&(pl[0]^(pl[1]-_xor)^pl[2]);
            }
            if(new_xor==0&&pl[1]-_xor>=0){
                pl[1]-=_xor;
                Take_Stone(2,_xor,&cp,&cn);
                pl[cp-1]-=cn;
                continue;
            }
            new_xor=0;
            for(int i=1;i<=max({pl[0],pl[1],pl[2]-_xor});i<<=1){
                new_xor+=i&(pl[0]^pl[1]^(pl[2]-_xor));
            }
            if(new_xor==0&&pl[2]-_xor>=0){
                pl[2]-=_xor;
                Take_Stone(3,_xor,&cp,&cn);
                pl[cp-1]-=cn;
                continue;
            }
        }
    }
}
