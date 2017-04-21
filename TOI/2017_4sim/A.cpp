#include<bits/stdc++.h>
using namespace std;
bool ap[(1<<28)];
int main(){
    for(int i=21;i<=28;++i){
        // set<int> meow;
        memset(ap,0,sizeof(ap));
        int cnt=0;
        for(int lp=0;lp<(1<<i);++lp){
            int turn=lp;
            for(int t=0;t<i;++t){
                turn=(turn>>1)|((turn&1)<<(i-1));
                if(ap[turn]/*meow.find(turn)!=meow.end()*/){
                    goto jizz;
                }
            }
            ap[lp]=1;
            ++cnt;
            // meow.insert(lp);
            jizz:;
        }
        cout<<"i: "<<i<<" , "<<cnt<<endl;
    }
}
