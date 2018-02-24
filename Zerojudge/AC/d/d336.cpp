#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; while(t--){
        string s; cin>>s;
        int now=0;
        for(char c:s){
            now=(now<<1)+(c=='1');
            if(now>=3)now-=3;
        }
        if(now==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
