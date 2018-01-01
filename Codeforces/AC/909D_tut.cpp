#include<bits/stdc++.h>
using namespace std;

struct seg{
    int len;
    char c;
};
vector<seg> v;

int main(){
    string s; cin>>s;
    for(int i=0,j;i<s.size();i=j){
        for(j=i;j<s.size() && s[j]==s[i];++j);
        v.push_back({j-i,s[i]});
    }
    vector<seg> *now=&v,*p=new vector<seg>;
    int ans=0;
    while(now->size()>1){
        p->clear();
        int fast=9999999;
        for(int i=0;i<now->size();++i){
            fast=min(fast,int(i==0 || i==now->size()-1?(*now)[i].len:((*now)[i].len+1)/2));
        }
        for(int i=0;i<now->size();++i){
            if(int(i==0 || i==now->size()-1?(*now)[i].len:((*now)[i].len+1)/2)<=fast){
                
            }
            else p->push_back({(*now)[i].len-fast*(i==0 || i==now->size()-1?1:2),(*now)[i].c});
        }
        now->clear();
        for(int i=0,j;i<p->size();i=j){
            int len=0;
            for(j=i;j<p->size() && (*p)[i].c==(*p)[j].c;++j)len+=(*p)[j].len;
            now->push_back({len,(*p)[i].c});
        }
        ans+=fast;
    }
    cout<<ans<<endl;
}
