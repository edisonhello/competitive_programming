#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int ts;cin>>ts;while(ts--){
        string s;cin>>s;
        int l=(int)s.length();
        for(int i=1;i<=(l>>1);++i){
            if(l%i)continue;
            for(int j=0;j<i;++j){
                for(int k=j;k<l;k+=i){
                    if(s[k]!=s[j])goto nextTry;
                }
            }
            cout<<i<<endl;
            goto nextTs;
            nextTry:;
        }
        cout<<l<<endl;
        nextTs:;
    }
}
