#pragma GCC optimize ("Ofast,no-stack-protector")
#include<bits/stdc++.h>

using namespace std;

unordered_map<unsigned long long,int> mp;
vector<int> ans;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    // string s; for(int i=0;i<2100;++i)s+=(rand()&1?"a":"b");
    for(int i=0;i<s.size();++i){
        unsigned long long hhv=0;
        for(int j=i;j<s.size();++j){
            hhv=hhv*47017+s[j];
            mp[hhv]=(i<<15)|j;
        }
    }
    for(int i=s.size()-1;i>=0;--i){
        unsigned long long hhv=0;
        for(int j=i;j>=0;--j){
            hhv=hhv*47017+s[j];
            mp[hhv]=(i<<15)|j;
        }
    }
    cin>>s; unsigned long long nhh=0;
    // unsigned long long nhh=0; s=""; for(int i=0;i<2100;++i)s+=(rand()&1?"a":"b");
    unordered_map<unsigned long long,int>::iterator it=mp.end(),itt;
    unsigned long long hht[2102]={0};
    for(int i=0;i<s.size();){
        hht[i]=s[i]; it=mp.find(hht[i]);
        int L=i,R=s.size()-1,prog=i;
        while(R>L){
            int M=(L+R+1)>>1;
            while(prog<M)++prog,hht[prog]=hht[prog-1]*47017+s[prog];
            itt=mp.find(hht[M]);
            if(itt==mp.end())R=M-1;
            else L=M,it=itt;
        }
        if(it==mp.end()){cout<<-1<<endl; exit(0);}
        ans.push_back(it->second);
        i=L+1;
    }
    cout<<ans.size()<<'\n';
    for(int &i:ans)cout<<(i>>15)+1<<" "<<(i&((1<<15)-1))+1<<'\n';
}
