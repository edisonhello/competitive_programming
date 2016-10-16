#include<bits/stdc++.h>
#include"lib1088.h"
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

int pl[3],cp,cn;
int main(){
    Initialize(&pl[0],&pl[1],&pl[2]);
    while(1){
        int _xor=0;
        for(int i=1;i<=max(pl[0],max(pl[1],pl[2]));i<<=1){
            _xor+=i*(pl[0]^pl[1]^pl[2]);
        }
        if(_xor==0){
            for(int i=0;i<3;++i){
                if(pl[i]>0){
                    --pl[i];
                    Take_Stone(i,1,&cp,&cn);
                    pl[cp-1]-=cn;
                    break;
                }
            }
        }
        else{
            int new_xor=0;
            for(int i=1;i<=max(pl[0]-_xor,max(pl[1],pl[2]));i<<=1){
                new_xor+=i*((pl[0]-_xor)^pl[1]^pl[2]);
            }
            if(new_xor==0){
                Take_Stone(1,_xor,&cp,&cn);
                pl[cp-1]-=cn;
                continue;
            }
            new_xor=0;
            for(int i=1;i<=max(pl[0],max(pl[1]-_xor,pl[2]));i<<=1){
                new_xor+=i*(pl[0]^(pl[1]-_xor)^pl[2]);
            }
            if(new_xor==0){
                Take_Stone(2,_xor,&cp,&cn);
                pl[cp-1]-=cn;
                continue;
            }
            new_xor=0;
            for(int i=1;i<=max(pl[0],max(pl[1],pl[2]-_xor));i<<=1){
                new_xor+=i*(pl[0]^pl[1]^(pl[2]-_xor));
            }
            if(new_xor==0){
                Take_Stone(3,_xor,&cp,&cn);
                pl[cp-1]-=cn;
                continue;
            }
        }
    }
}
