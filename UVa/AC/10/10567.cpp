#include<bits/stdc++.h>
using namespace std;

int nxt[1000006][57],id[555];

int main(){
    for(int i='A';i<='Z';++i)id[i]=i-'A';
    for(int i='a';i<='z';++i)id[i]=i-'a'+26;
    string s; cin>>s;
    int n=s.size();
    s="."+s;
    for(int i=0;i<52;++i)nxt[n][i]=n+1;
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<52;++j){
            nxt[i][j]=nxt[i+1][j];
        }
        nxt[i][id[s[i+1]]]=i+1;
    }
    int q; cin>>q; while(q--){
        string s; cin>>s;
        int ptr=0;
        bool ok=1;
        for(char c:s){
            ptr=nxt[ptr][id[c]];
            if(ptr>n){ok=0; break;}
        }
        if(!ok)cout<<"Not matched"<<endl;
        else cout<<"Matched "<<nxt[0][id[s[0]]]-1<<" "<<ptr-1<<endl;
    }
}
