#include<bits/stdc++.h>
using namespace std;
int main(){
    int d;
    while(cin>>d){
        if(d<0){cout<<"stupid\n";continue;}
        if(d==0){cout<<"0\n";continue;}
        int res = (int)(((long double)d)*100/101)-2;
        for(;res<1026;res++){
            if((int)(((long double)res)*101/100)==d) break;
        }
        if(res<0 || res>1024)cout<<"stupid\n";
        else cout<<res<<'\n';
    }
}
