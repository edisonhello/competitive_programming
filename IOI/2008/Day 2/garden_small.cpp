#include<bits/stdc++.h>
using namespace std;
#define lock _my_lock

int n,m;
string s;
map<int,pair<int,int>> mp1,*mp;

void dfs1(int now,int bnd,int val,int pre,int pmx,int pmn){
    if(now>=bnd){ ++(*mp)[val].first; return; }
    if(pre+1-pmn<=2){
        dfs1(now+1,bnd,val,pre+1,max(pmx,pre+1),pmn); // go L
    }
    if(pmx-pre+1<=2){
        dfs1(now+1,bnd,val+(1<<now),pre-1,pmx,min(pmn,pre-1)); // go P
    }
}
void do_once(){
    mp=&mp1;
    dfs1(0,n,0,0,0,0);
    int pre=0;
    for(auto &p:*mp){
        pre+=p.second.first;
        if(pre>=m)pre-=m;
        p.second.second=pre;
    }
    int val=0;
    for(int i=n-1,j=0;i>=0;--i,++j){
        if(s[i]=='P')val+=(1<<j);
    }
    cout<<mp->find(val)->second.second<<endl;
}

int mp2[1<<20][5][5][5];
map<tuple<int,int,int>,int> mp3;
map<tuple<int,int,int>,map<int,pair<int,int>>> mp4;


void dfs2(int now,int bnd,int val,int pre,int pmx,int pmn){
    // cout<<now<<" "<<val<<" "<<pre<<" "<<pmx<<" "<<pmn<<endl;
    if(now>=bnd){ ++mp2[make_tuple(val,pre,pmx,pmn)]; return; }
    if(pre+1-pmn<=2){
        dfs2(now+1,bnd,val,pre+1,max(pmx,pre+1),pmn); // go L
    }
    if(pmx-pre+1<=2){
        dfs2(now+1,bnd,val+(1<<now),pre-1,pmx,min(pmn,pre-1)); // go P
    }
}
void dfs3(int now,int bnd,int val,int pre,int pmx,int pmn){
    if(now>=bnd){ ++mp3[make_tuple(pre,pmx,pmn)]; ++mp4[make_tuple(pre,pmx,pmn)][val].first; return; }
    if(pre+1-pmn<=2){
        dfs3(now+1,bnd,val,pre+1,max(pmx,pre+1),pmn); // go L
    }
    if(pmx-pre+1<=2){
        dfs3(now+1,bnd,val+(1<<now),pre-1,pmx,min(pmn,pre-1)); // go P
    }
}

void do_twice(){
    dfs2(0,20,0,0,0,0);
    dfs3(0,n-20,0,0,0,0);
    int spval=0;
    for(int i=19,j=0;i>=0;--i,++j){
        if(s[i]=='P')spval+=(1<<j);
    }
    int ans=0;
    vector<pair<tuple<int,int,int,int>,int>> mp2c;
    for(auto &p1:mp2){
        int pval,ppre,ppmx,ppmn,spre,spmx,spmn;
        tie(pval,ppre,ppmx,ppmn)=p1.first;
        // cout<<"iting mp2, "<<pval<<" "<<ppre<<" "<<ppmx<<" "<<ppmn<<" "<<spval<<endl;
        if(pval==spval){
            mp2c.push_back(p1);
            continue;
        }
        if(pval>spval)break;
        for(auto &p2:mp3){
            tie(spre,spmx,spmn)=p2.first;
            if(max(spmx+ppre,ppmx)-min(spmn+ppre,ppmn)>2)continue;
            ans=(ans+1ll*p1.second*p2.second%m)%m;
        }
    }
    int ssval=0;
    for(int i=n-1,j=0;i>=20;--i,++j){
        if(s[i]=='P')ssval+=(1<<j);
    }
    for(auto &mpp:mp4){
        int pre=0;
        for(auto &p:mpp.second){
            pre+=p.second.first;
            if(pre>=m)pre-=m;
            p.second.second=pre;
        }
    }
    for(auto &p1:mp2c){
        int pval,ppre,ppmx,ppmn,spre,spmx,spmn;
        tie(pval,ppre,ppmx,ppmn)=p1.first;
        for(auto &p2:mp4){
            tie(spre,spmx,spmn)=p2.first;
            if(max(spmx+ppre,ppmx)-min(spmn+ppre,ppmn)>2)continue;
            auto it=p2.second.upper_bound(ssval);
            if(it!=p2.second.begin())ans=(ans+1ll*p1.second*it->second.second%m)%m;
        }
    }
    cout<<ans+1<<endl;
}

int main(){
    cin>>n>>m;
    cin>>s;
    if(n<=20){
        do_once();
    }
    else{
        do_twice();
    }
}
