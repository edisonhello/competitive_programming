#include<bits/stdc++.h>
using namespace std;

vector<string> v;
set<char> ban;
int mtint[10],tab[222];

#define _(a,b) if(c==a)return mtint[b];
int g(char c){
    _('a',0)
    _('b',1)
    _('c',2)
    _('d',3)
    _('e',4)
    _('f',5)
    _('g',6)
    _('h',7)
    _('i',8)
    _('j',9)
}
#undef _
void build(){
    for(char i='a';i<='j';++i){
        tab[i]=g(i);
    }
}
inline sol(string &s){
    
}

int main(){
    int n; cin>>n;
    v.resize(n);
    // pre process the dig of each char
    for(auto &s:v)cin>>s,ban.insert(s[0]);
    for(int i=0;i<10;++i)mtint[i]=i;
    long long ans=0;
    do{
        bool ok=1;
        for(char c:ban)if(g(c)==0){ok=0; break;}
        if(!ok)continue;
        build();
        long long now=0;
        for(auto &s:v){
            now+=sol(s);
        }
        ans=min(ans,now);
    }while(next_permutation(mtint,mtint+10));
    cout<<ans<<endl;
}
