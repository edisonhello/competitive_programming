#include<bits/stdc++.h>
using namespace std;

long long cnt[1233],ans;
int main(){
    string s; cin>>s;
    for(char c:s)++cnt[c];
    ans=s.size()*1ll*(s.size()-1)/2;
    for(int i=0;i<333;++i)ans-=cnt[i]*1ll*(cnt[i]-1)/2;
    cout<<ans+1<<endl;
}
