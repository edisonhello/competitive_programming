#include<bits/stdc++.h>
using namespace std;

int cnt[333],ccnt[30],exceed;

void add(char c){
    if(c=='?')return;
    --ccnt[cnt[c]];
    ++cnt[c];
    ++ccnt[cnt[c]];
    if(cnt[c]==2)++exceed;
}
void sub(char c){
    if(c=='?')return;
    --ccnt[cnt[c]];
    --cnt[c];
    ++ccnt[cnt[c]];
    if(cnt[c]==1)--exceed;
}

int main(){
    string s; cin>>s;
    ccnt[0]=26;
    if(s.size()<26u)exit((cout<<-1<<endl,0));
    for(int i=0;i<25;++i){
        add(s[i]);
    }
    for(int i=25;i<s.size();++i){
        add(s[i]);
        // cout<<"exceed: "<<exceed<<endl;
        if(!exceed){
            // cout<<"no exceed at "<<i<<endl;
            bitset<300> app;
            for(int j=i-25;j<=i;++j)app[s[j]]=1;
            for(int j=i-25;j<=i;++j){
                if(s[j]=='?'){
                    for(int z='A';z<='Z';++z){
                        if(!app[z]){
                            app[z]=1;
                            s[j]=z;
                            break;
                        }
                    }
                }
            }
            for(char &c:s)if(c=='?')c='A';
            cout<<s<<endl;
            exit(0);
        }
        sub(s[i-25]);
    }
    cout<<-1<<endl;
}
