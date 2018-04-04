#include<bits/stdc++.h>
using namespace std;

int h[1111];
string s;
int main(){
    int n; cin>>n;
    cin>>s;
    for(int i=0;i<s.size();++i){
        if(s[i]=='R'){
            int j=i;
            while(j>0 && s[j-1]=='=')--j;
            h[i+1]=h[j]+1;
        }
    }
    for(int i=n-2;i>=0;--i){
        if(s[i]=='L'){
            int j=i+1;
            while(j<s.size() && s[j]=='=')++j;
            h[i]=max(h[i],h[j]+1);
        }
    }
    for(int i=0,j;i<n-1;i=j){
        for(j=i;j<n-1;++j){
            if(s[j]!='=')break;
        }
        if(s[i]!='='){
            ++j; continue;
        }
        if(s[i]=='='){
            int l=i,r=j;
            int v=max(h[l],h[r]);
            for(int i=l;i<=r;++i)h[i]=v;
        }
    }
    for(int i=0;i<n;++i)cout<<h[i]+1<<" ";
}
