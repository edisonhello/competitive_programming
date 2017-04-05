#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include<algorithm>

#define ll long long

const ll p=648945221;
ll hsh;
string s;
map<ll,int> m,tp;
ll mxpw;
int k;
vector<string> ans;

ll _pw(ll b,int n){
    ll a=1;
    while(n){
        if(n&1)a=a*b%p;
        b=b*b%p;
        n>>=1;
    }
    return a;
}

bool tryLen(int len){
    // cout<<"try len "<<len<<endl;
    mxpw=_pw(7122,len-1);
    m.clear();
    tp.clear();
    ll bs=1,nhs=0;
    for(auto i=len-1;i>=0;--i){
        nhs+=bs*s[i];
        nhs%=p;
        bs=bs*7122%p;
    }
    ++m[nhs];
    tp[nhs]=0;
    // cout<<nhs<<endl;
    for(auto i=len;i<(int)s.length();++i){
        nhs-=s[i-len]*mxpw%p;
        nhs=nhs%p+p;nhs%=p;
        nhs*=7122;nhs%=p;
        nhs+=s[i];
        ++m[nhs];
        tp[nhs]=i-len+1;
        // cout<<nhs<<endl;
    }
    for(auto it:m){
        if(it.second==k){
            string str="";
            int pos=tp[it.first];
            for(int i=pos;i<pos+len;++i){
                str+=s[i];
            }
            ans.push_back(str);
        }
    }
    if(ans.size())return 1;
    return 0;
}

int main(){
    cin>>s;cin>>k;

    // mxpw=_pw(7122,(int)s.length());
    /* TLE+WA 75 */
    for(auto i=s.length()-k+1;i>=1;--i){
        if(tryLen(i)){
            sort(ans.begin(),ans.end());
            for(auto &s:ans)cout<<s<<endl;
            break;
        }
    }
    /* after cheat */
    // int l=1,r=s.length()-k+1;
    // while(r>l){
    //     int m=(l+r)/2;
    //     if(tryLen(m)){
    //         ans.clear();
    //         l=m;
    //     }
    //     else r=m-1;
    //     // cout<<l<<" "<<r<<endl;
    // }
    // tryLen(r);
    // sort(ans.begin(),ans.end());
    // for(auto &s:ans)cout<<s<<endl;
}
