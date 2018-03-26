#include<bits/stdc++.h>
using namespace std;


int cnt[12434];
int main(){
    string s; cin>>s>>s;
    if(s.size()>26)return cout<<-1<<endl,0;
    for(char c:s)++cnt[c];
    int ans=0;
    for(int i='a';i<='z';++i){
        if(cnt[i])ans+=cnt[i]-1;
    }
    cout<<ans;
}
