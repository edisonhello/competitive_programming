
#include<bits/stdc++.h>
using namespace std;

void no(){
    cout<<"NO"<<endl;
    exit(0);
}

int main(){
    int n; cin>>n;
    int c25=0,c50=0,c100=0;
    while(n--){
        int t; cin>>t;
        if(t==25){
            ++c25;
        }
        else if(t==50){
            if(c25==0)no();
            --c25;
            ++c50;
        }
        else{
            if(c50 && c25){
                --c50; --c25; ++c100;
            }
            else if(c25>=3){
                c25-=3; ++c100;
            }
            else no();
        }
    }
    cout<<"YES"<<endl;
}
