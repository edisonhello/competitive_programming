#include<bits/stdc++.h>
using namespace std;
string st[1000];
int main(){
    string s,name; cin>>s; int ptr=0,top=-1,ans=0;
    while(ptr<s.size()){
        if(s[ptr]>='A' and s[ptr]<='Z'){
            name+=s[ptr];
        }
        else{
            if(s[ptr]=='.'){
                if(name!="")for(int i=0;i<=top;++i){
                    if(st[i]==name)++ans;
                }
                else --top;
            }
            else if(s[ptr]==',');
            else if(s[ptr]==':'){
                for(int i=0;i<=top;++i){
                    if(st[i]==name)++ans;
                }
                st[++top]=name;
            }
            name="";
        }
        ++ptr;
    }
    cout<<ans<<endl;
}
