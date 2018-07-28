#include<bits/stdc++.h>
using namespace std;


int main(){
    int t=1; cin>>t; while(t--){
        string s; cin>>s;
        // for(int i=0;i<100000;++i)s+='9';
        reverse(s.begin(),s.end());
        for(int i=1;;++i){
            string tmp;
            int x=i;
            while(x){ tmp+=char(x%10+'0'); x/=10; }
            reverse(tmp.begin(),tmp.end());
            for(char c:tmp)if(s.size() && c==s.back())s.pop_back();

            if(s.empty()){ cout<<i<<endl; break; }
        }
    }
}
