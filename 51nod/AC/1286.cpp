#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

const ull p=131;

int fail[1000006];
ull pp[1000006],hsh[1000006];

ull hh(int l,int r){
    return (hsh[r]-hsh[l-1])*pp[1000002-r];
}

void BF(string s,int n){
    for(int i=n/3;i>=1;--i){
        int lll=i,rrr=n-i+1;
        if(hh(1,lll)==hh(rrr,n)){
            for(int j=lll+1;j+i-1<rrr;++j){
                if(hh(1,lll)==hh(j,j+i-1)){
                    cout<<i<<endl;
                    exit(0);
                }
            }
        }
    }
    cout<<0<<endl;
    exit(0);
}

int main(){
    pp[0]=1;
    for(int i=1;i<1000006;++i)pp[i]=pp[i-1]*p;
    string s; cin>>s;
    int n=s.size();
    s="."+s;
    for(int i=1;i<=n;++i)hsh[i]=(i?hsh[i-1]:0)+s[i]*pp[i];
    if(n<=100)BF(s,n);
    for(int i=2;i<=n;++i){
        int j=i;
        while(j && s[j]!=s[fail[j-1]+1])j=fail[j];
        // cout<<i<<" "<<j<<endl;
        fail[i]=fail[j-1]+(s[i]==s[fail[j-1]+1]);
    }
    // for(int i=1;i<=n;++i)cout<<fail[i]<<" "; cout<<endl;
    multiset<int> st;
    int L=1,R=0;
    for(int i=n/3;i>=1;--i){
        // cout<<i<<" "<<hh(1,i)<<" "<<hh(n-i+1,n)<<endl;
        if(hh(1,i)==hh(n-i+1,n)){
            int ll=i+1,rr=n-i;
            while(R<rr)st.insert(fail[++R]);
            while(L<ll)st.erase(st.find(fail[L])),++L;
            while(L>ll)st.insert(fail[--L]);
            if(st.find(i)!=st.end()){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    cout<<0<<endl;
}

