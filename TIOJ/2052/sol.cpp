#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod;

ll C[1111][1111];

void init(){
    C[0][0]=1;
    for(int i=1;i<1111;++i){
        for(int j=0;j<=i;++j){
            C[i][j]=C[i-1][j];
            if(i)C[i][j]=(C[i][j]+C[i-1][j-1])%mod;
        }
    }
}

int jec[222];
inline int id(char c){return jec[c];}

ll get(int *cnt){
    int tot=0;
    for(int i=0;i<55;++i)tot+=cnt[i];
    ll rt=1;
    for(int i=0;i<55;++i){
        rt=rt*C[tot][cnt[i]]%mod;
        tot-=cnt[i];
    }
    return rt;
}

ll process(string s,int ptr){
    if(ptr>=s.size())return 0;
    int cnt[55]={0};
    for(int i=ptr;i<s.size();++i){
        ++cnt[id(s[i])];
    }
    ll pre=0;
    for(int i=0;i<id(s[ptr]);++i){
        if(cnt[i]){
            // if(ptr==1 && i==1)cout<<"mepw"<<endl;
            --cnt[i];
            pre=(pre+get(cnt))%mod;
            ++cnt[i];
        }
    }
    return (pre+process(s,ptr+1))%mod;
}

int main(){
    string s;
    cin>>mod>>s;

    init();

    for(int i='A';i<='Z';++i)jec[i]=i-'A';
    for(int i='a';i<='z';++i)jec[i]=i-'a'+26;

    cout<<process(s,0)%mod<<endl;
}
