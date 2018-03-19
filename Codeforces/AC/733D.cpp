#include<bits/stdc++.h>
using namespace std;

int n,a[100005][3];


int get(int x,int y){
    // cout<<"get "<<x<<" "<<y<<endl;
    int mx=0;
    for(int ii=0;ii<3;++ii){
        for(int ij=ii+1;ij<3;++ij){
            for(int ji=0;ji<3;++ji){
                for(int jj=ji+1;jj<3;++jj){
                    if(a[x][ii]==a[y][ji] && a[x][ij]==a[y][jj]){
                        mx=min(min(a[x][ii],a[x][ij]),a[x][ii^ij^3]+a[y][ji^jj^3]);
                    }
                }
            }
        }
    }
    return mx;
}
int get(int x){
    return min(a[x][0],min(a[x][1],a[x][2]));
}

struct Ans{
    int dia;
    vector<int> mem;
    Ans():dia(0){}
    void set(int x){
        dia=get(x);
        mem.resize(1);
        mem[0]=x;
    }
    void set(int x,int y){
        dia=get(x,y);
        mem.resize(2);
        mem[0]=x;
        mem[1]=y;
    }
} ans;

map<pair<int,int>,vector<pair<int,int>>> mp;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        if(get(i)>ans.dia)ans.set(i);
        sort(a[i],a[i]+3);
        map<pair<int,int>,int> smp;
        smp[make_pair(a[i][0],a[i][1])]=a[i][2];
        smp[make_pair(a[i][1],a[i][2])]=a[i][0];
        smp[make_pair(a[i][0],a[i][2])]=a[i][1];
        for(auto it:smp){
            // cout<<it.first.first<<" "<<it.first.second<<" -> "<<it.second<<endl;
            auto &iit=mp[it.first];
            iit.emplace_back(it.second,i);
            if(iit.size()>2u){
                sort(iit.begin(),iit.end(),greater<pair<int,int>>());
                iit.resize(2);
            }
        }
    }
    // cout<<"search mp "<<endl;
    for(auto it:mp){
        if(it.second.size()>1u){
            // cout<<"head: "<<it.first.first<<" "<<it.first.second<<endl;
            if(get(it.second[0].second,it.second[1].second)>ans.dia){
                ans.set(it.second[0].second,it.second[1].second);
            }
        }
    }
    cout<<ans.mem.size()<<endl;
    for(int i:ans.mem)cout<<i<<" "; cout<<endl;
    
}
