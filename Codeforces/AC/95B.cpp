#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    if([&](){bool rt=1; for(char c:s)if(c!='7')rt=0; return rt;}())exit(([&](){int l=s.size()+1; l+=l&1; for(int i=0;i<l/2;++i)cout<<'4'; for(int i=0;i<l/2;++i)cout<<'7'; cout<<endl;}(),0));
    auto solve=[&](bool same){
        for(char &c:s)if(same){if(c=='4' || c=='7')continue; else if(c<'4')c='4',same=0; else c='7',same=0;} else c='4';
        int c7=s.size()/2-count(s.begin(),s.end(),'7'),ptr=s.size()-1;
        // cout<<"c7: "<<c7<<endl;
        if(c7>0)while(c7>0){if(s[ptr]!='7')s[ptr]='7',--c7;--ptr;}
        else if(c7<0){--c7;while(c7<0){if(s[ptr]=='7')s[ptr]='4',++c7;--ptr;}if(s[ptr]=='4')s[ptr]='7';else{c7=0;while(ptr>=0 && s[ptr]=='7')s[ptr]='4',++c7,--ptr;if(ptr>=0)s[ptr]='7';else s="44"+s,c7+=2;ptr=s.size()-1;while(c7)s[ptr]='7',--c7,--ptr;}}
        // while(c7<0){if(s[ptr]=='7')s[ptr]='4',++c7;++ptr;}
        return cout<<s<<endl,0;
    };
    if(s.size()&1 || [&](){bool rt=1; for(char c:s)if(c!='7'){rt=c>'7'; break;} return rt;}())s="1"+s,s=(s.size()&1?"1"+s:s),exit(solve(0));
    int ptr=0; while(ptr<s.size()){if(s[ptr]>'7'){s[ptr]='0'; --ptr; while(1){if(s[ptr]=='7')s[ptr]='0'; else{++s[ptr]; break;}--ptr;}break;}++ptr;}
    solve(1);
}
