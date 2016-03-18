#include<bits/stdc++.h>
#include"lib1885.h"

using namespace std;

int main(){
    int t=Init();
    while(t--){
        void orderCoins();
        int _[6]={0,0,0,0,0,0};

        int a1 = getHeaviest(1,2,3);
        int a2 = getMedian(1,2,3);
        int a3;for(int i=1;i<=3;i++){if(a1!=i && a2!=i){a3=i;break;}}

        int b3 = getLightest(4,5,6);
        int b2;for(int i=4;i<=6;i++){if(b3!=i){b2=i;break;}}
        int b1;for(int i=4;i<=6;i++){if(b1!=i && b2!=i){b3=i;break;}}

        int __ = getHeaviest(a1,b1,b2);
        if(__==a1){
            _[0]=a1;
            int ___ = getHeaviest(a2,b1,b2);
            if(___==a2){
                _[1]=a2;
                int ____ = getHeaviest(a3,b1,b2);
                if(____==a3){
                    _[2]=a3;
                    int n_b2 = getMedian(b1,b2,b3);
                    int n_b1;for(int i=4;i<=6;i++){if(b3!=i&&n_b2!=i)n_b1=i;break;}
                    _[3]=n_b1;
                    _[4]=n_b2;
                    _[5]=b3;
                }
                else if(____==b1){
                    _[2]=b1;
                    int _____ = getMedian(a3,b2,b3);
                    int o0o0;for(int i=1;i<=6;i++){if(a1!=i&&a2!=i&&b1!=i&&b3!=i&&_____!=i){o0o0=i;break;}}
                    _[3]=o0o0;
                    _[4]=_____;
                    _[5]=b3;
                }
                else if(____==b2){
                    _[2]=b2;
                    int _____ = getMedian(a3,b1,b3);
                    int o0o0;for(int i=1;i<=6;i++){if(a1!=i&&a2!=i&&b2!=i&&b3!=i&&_____!=i){o0o0=i;break;}}
                    _[3]=o0o0;
                    _[4]=_____;
                    _[5]=b3;
                }
            }
            else if(___==b1){

            }
            else if(___==b2){

            }
        }
        else if(__==b1){

        }
        else if(__==b2){

        }
    }
}
