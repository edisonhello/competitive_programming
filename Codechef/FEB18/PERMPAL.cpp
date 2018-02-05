#include<bits/stdc++.h>
using namespace std;

int cnt[1234];
int pptr[100005],rev[100005];
int main(){
    int t; cin>>t; while(t--){
        string s; cin>>s;
        memset(cnt,0,sizeof(cnt));
        for(char c:s)++cnt[c];
        int odd=0;
        for(int i=0;i<333;++i)if(cnt[i]&1)++odd;
        if(odd>1){
            cout<<-1<<endl;
            continue;
        }
        if(odd==0)odd=-1;
        else for(int i=0;i<333;++i)if(cnt[i]&1)odd=i;
        vector<int> pos[333]; int ptr=0;
        int oddpos;
        for(int i=0;i<333;++i)for(int j=0;j<cnt[i]/2;++j)pos[i].push_back(++ptr);
        if(odd!=-1)oddpos=++ptr;
        for(int i=321;i>=0;--i)for(int j=0;j<cnt[i]/2;++j)pos[i].push_back(++ptr);
        int now[333]={0};
        int pppp=0;
        for(char c:s){
            if(c==odd){pptr[++pppp]=oddpos,odd=-1;continue;}
            pptr[++pppp]=pos[c][now[c]];
            ++now[c];
            // if(now[c]>=pos[c].size())now[c]=0;
        }
        for(int i=1;i<=s.size();++i)rev[pptr[i]]=i;
        for(int i=1;i<=s.size();++i)cout<<rev[i]<<" \n"[i==s.size()];
    }
}
