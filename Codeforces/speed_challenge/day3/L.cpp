#include<bits/stdc++.h>
using namespace std;
#define ld long double

int on=0;
ld tos[4];

int main(){
    int n; cin>>n;
    ld tot=0;
    while(n--){
        int c,p; cin>>c>>p;
        if(c==1){
            tot+=tos[p];
            tos[p]=1;
            ++on;
        }
        else{
            if(on==1){
                tos[1]=tos[2]=0;
            }
            else if(on==2){
                tos[1]*=(ld)p/100;
                tos[2]*=(ld)(100-p)/100;                
                --on;
            }
        }
    }
    cout<<fixed<<setprecision(30)<<tot<<endl;
}
