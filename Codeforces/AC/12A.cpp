#include<bits/stdc++.h>
using namespace std;

int main(){
    string mp[3]; cin>>mp[0]>>mp[1]>>mp[2];
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(mp[i][j]!=mp[2-i][2-j]){
                cout<<"NO\n"; exit(0);
            }
        }
    } cout<<"YES"<<endl;
}
