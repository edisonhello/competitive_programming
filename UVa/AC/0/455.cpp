#include<bits/stdc++.h>
using namespace std;

int main(){
    int ts; cin>>ts; while(ts--){
        string s; cin>>s;
        bool gans=0;
        for(int i=1;i<=s.size() && !gans;++i){
            if(i==s.size())cout<<i<<endl;
            else if(s.size()%i)continue;
            else{
                bool ok=1;
                for(int j=i;j<s.size() && ok;++j){
                    if(s[j]!=s[j%i])ok=0;
                }
                if(ok)cout<<i<<endl,gans=1;
            }
        }
        if(ts)cout<<endl;
    }
}
