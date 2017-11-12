#include<bits/stdc++.h>
using namespace std;

void jizz(){cout<<"NO\n"; exit(0);}
unordered_map<string,int> mp;

int gid(string s){
    auto it=mp.find(s);
    if(it==mp.end())return mp[s]=mp.size();
    else return it->second;
}
vector<pair<int,char>> G[200005];
vector<char> ans;
int ind[200005],oud[200005];

void dfs(int now,char come=0){
    for(;G[now].size();){
        auto rec=G[now].back();
        G[now].pop_back();
        dfs(rec.first,rec.second);
    }
    if(come)ans.push_back(come);
}

int main(){
    int n; cin>>n;
    int stp=-87;
    for(int i=0;i<n;++i){
        string str; cin>>str;
        int f=gid(string(1,str[0])+str[1]),b=gid(string(1,str[1])+str[2]);
        G[f].emplace_back(b,str[2]);
        // cout<<b<<" "<<f<<endl;
        ++oud[f]; ++ind[b];
        stp=b;
    }
    // for(auto i:mp)cout<<"["<<i.first<<","<<i.second<<"], "; cout<<endl;
    int sts=0;
    for(int i=0;i<200005;++i){
        if(abs(oud[i]-ind[i])>1)jizz();
        if(oud[i]>ind[i]){
            ++sts;
            if(sts>1)jizz();
            stp=i;
        }
    }
    string ststr;
    for(auto &i:mp)if(i.second==stp){ststr=i.first; break;}
    // cout<<"stp: "<<stp<<endl;
    // cout<<"ind: "; for(int i=1;i<=4;++i)cout<<ind[i]<<" "; cout<<endl;
    // cout<<"oud: "; for(int i=1;i<=4;++i)cout<<oud[i]<<" "; cout<<endl;
    dfs(stp);
    reverse(ans.begin(),ans.end());
    if(ans.size()!=n)jizz();
    cout<<"YES\n"<<ststr; for(char c:ans)cout<<c; cout<<endl;

}
