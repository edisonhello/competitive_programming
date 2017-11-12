#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    string lw,hi;
    for(int i=0;i<s.size()-1;++i){
        if((s[i]-'0')%2==0){
            if(s.back()>s[i]){
                if(hi==""){
                    hi=s;
                    swap(hi[i],hi[hi.size()-1]);
                }
            }
            else{
                if(hi==""){
                    lw=s;
                    swap(lw[i],lw[lw.size()-1]);
                }
            }
        }
    }
    if(hi.size())cout<<hi<<endl;
    else if(lw.size())cout<<lw<<endl;
    else cout<<"-1"<<endl;
}
