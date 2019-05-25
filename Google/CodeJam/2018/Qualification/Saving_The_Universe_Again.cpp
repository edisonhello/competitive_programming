#include<bits/stdc++.h>
using namespace std;

int main(){
    int ts,ks=0; cin>>ts; while(ts--){
        int d; cin>>d;
        string s; cin>>s;
        int cnt=0;
        while(1){
            int nd=1,dd=0;
            for(char c:s){
                if(c=='C')nd<<=1;
                else dd+=nd;
            }
            if(dd<=d)break;
            bool done=0;
            for(int i=s.size()-1;i>0;--i){
                if(s[i]=='S' && s[i-1]=='C'){
                    done=1;
                    ++cnt;
                    swap(s[i],s[i-1]);
                    break;
                }
            }
            if(!done){
                cnt=-1;
                break;
            }
        }
        cout<<"Case #"<<(++ks)<<": ";
        if(cnt==-1)cout<<"IMPOSSIBLE"<<endl;
        else cout<<cnt<<endl;
    }
}
