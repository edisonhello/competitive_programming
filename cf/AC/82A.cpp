#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int now=1;

    //for(int n=1;n<=1802;n++){
    now=1;
    for(int i=0;;){
        i+=now;if(i>=n){cout/*<<i<<" "<<n*/<<"Sheldon"<<endl;break;}
        i+=now;if(i>=n){cout/*<<i<<" "<<n*/<<"Leonard"<<endl;break;}
        i+=now;if(i>=n){cout/*<<i<<" "<<n*/<<"Penny"<<endl;break;}
        i+=now;if(i>=n){cout/*<<i<<" "<<n*/<<"Rajesh"<<endl;break;}
        i+=now;if(i>=n){cout/*<<i<<" "<<n*/<<"Howard"<<endl;break;}
        now*=2;
    }//}
}
