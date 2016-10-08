#include<iostream>
#include<cstring>
using namespace std;
#define S0(x) memset((x),0,sizeof(x))

int n,i,in,j,ed,cnt[26],mnst,mned;
string s;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(cin>>n && n){
        cin>>s;
        S0(cnt);
        in=0;
        mnst=-7122;
        mned=1000001;
        for(i=0,ed=0;i<s.length();++i){
            // cout<<"doing "<<s[i]<<endl;
            // cout<<"cnt:";for(int asdf=0;asdf<26;asdf++)cout<<cnt[asdf]<<' ';cout<<endl;
            ++cnt[s[i]-'a'];
            if(cnt[s[i]-'a']==1){
                ++in;
                if(in==26){
                    while(cnt[s[ed]-'a']>1){
                        --cnt[s[ed]-'a'];
                        ++ed;
                    }
                    if(i-ed<mned-mnst){
                        mned=i;
                        mnst=ed;
                    }
                    --cnt[s[ed]-'a'];
                    --in;
                    ++ed;
                }
            }
        }
        if(mnst==-7122){
            cout<<"not found\n";
        }
        else{
            for(i=mnst;i<=mned;++i){
                cout<<s[i];
            }
            cout<<'\n';
            // cout<<s.substr(mnst,mned-mnst+1)<<'\n';
        }
    }
}
