#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
#define ll long long
ll ary[66],n;
string s;
int main(){
    cin>>n>>s;
    ll idx=0,pos=(ll)s.length();--pos;
    ll now=0,ans=0,bs=1;
    while(pos>=0){
        // cout<<"pos"<<pos<<" "<<idx<<" "<<now<<" "<<now+bs*(s[pos]-'0')<<endl;
        if(now+bs*(s[pos]-'0')<n){
            now=now+bs*(s[pos--]-'0');
            bs*=10;
        }
        else{
            while(s[pos+1]=='0')++pos;
            if(now==0){
                s[pos]='_';
                ++idx;--pos;
                bs=1;
            }
            else{
                ary[idx++]=now;
                now=0;
                bs=1;
            }
        }
    }
    if(now){
        while(s[pos+1]=='0')++pos;
        ary[idx++]=now;
    }

    // cout<<ary[0]<<" "<<ary[1]<<" "<<ary[2]<<endl;
    for(ll i=0,j=1;i<idx;++i,j*=n){
        ans+=j*ary[i];
    }
    cout<<ans<<endl;
}
