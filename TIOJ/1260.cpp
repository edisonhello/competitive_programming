#include<omp.h>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void T(int n){
    for( int i = 0; i < 10000; ++ i )
 {

 }
 printf( "%d, ", omp_get_thread_num() );
}
int main(){
    // freopen("1260.out","w",stdout);
    // ll anss=4;
    // ll add=2ll+3ll+5ll+7ll;
    #pragma omp for
    for(int i=0;i<50;i++){
        T(i);
    }
    // for(ll i=9;i<300000000ll;++i){
    //     for(ll j=2;j*j<=i;++j){
    //         if(i%j==0){
    //             goto next;
    //         }
    //     }
    //     ++anss;
    //     add+=i;
    //     add%=(1ll<<32);
    //     next:;
    // }
    // cout<<anss<<endl<<add<<endl;
}
