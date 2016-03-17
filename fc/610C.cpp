#include<bits/stdc++.h>

using namespace std;

int main(){
    //freopen("mkf5.txt","w",stdout);
    int n;cin>>n;
    int bign = (1<<n);

    bool r[(1<<n)][(1<<n)];
    int i;
    vector<int> in;
    in.push_back(0);

    for(int findEnableIn=(1<<(bign/2))-5;in.size()!=bign;findEnableIn++){
        bool canThisPushBack = true;
        for(int loopAllInIn=0;loopAllInIn<in.size();loopAllInIn++){
            int scalarProduct=0;
            for(int searchAllBits=0;searchAllBits<bign;searchAllBits++){
                        /**///printf("in loop,i %d,j %d,j=compare with %d,k %d,now SP %d. lhs %d,rhs %d,xor %d\n",findEnableIn,loopAllInIn,in[loopAllInIn],searchAllBits,scalarProduct,(in[loopAllInIn]>>searchAllBits),(findEnableIn>>searchAllBits),(in[loopAllInIn]>>searchAllBits)^(findEnableIn>>searchAllBits));

                if(((in[loopAllInIn]%(1<<(searchAllBits+1)))/(1<<searchAllBits))^((findEnableIn%(1<<(searchAllBits+1)))/(1<<searchAllBits))){
                    scalarProduct++;
                }
                else{
                    scalarProduct--;
                }
            }
            if(scalarProduct!=0){
                canThisPushBack = false;
                break;
            }
        }
        if(canThisPushBack){
                /**///printf("got pushed %d\n",findEnableIn);
            in.push_back(findEnableIn);
        }
    }




    for(int i=0;i<in.size();i++){
        for(int j=0;j<bign;j++){
            if(in[i] & (1<<j)){
                printf("+");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }

/*
    if(n==0){

    }
    if(n==1){
        printf("++\n+*\n");
    }
    if(n==2){
        printf("++++\n++**\n+*+*\n*++*\n");
    }
    if(n==3){
        printf("")
    }
*/
}
