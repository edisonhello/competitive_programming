#include<bits/stdc++.h>
using namespace std;
vector<int> mp[100005];
int clr[100005];

int n,m;


bool chkok(int fr,int ed){
    return clr[fr]!=clr[ed];
}

bool dfs(int st,int type){
    // cout<<"dfs st="<<st<<", type="<<type<<endl;

    clr[st] = type;

    for(int i=0;i<(int)mp[st].size();i++){
        if(clr[mp[st][i]]){
            // cout<<mp[st][i]<<" walked\n";
            if(chkok(st,mp[st][i])){
                // cout<<"chkok"<<endl;
                continue;
            }
            else{
                return false;
            }
        }
        else{
            // cout<<mp[st][i]<<" notgo\n";
            if(type==1){
                if(!dfs(mp[st][i],2)){
                    return false;
                }
            }
            else{
                if(!dfs(mp[st][i],1)){
                    return false;
                }
            }
        }
    }
    return true;
}

bool solve(int st){
    return dfs(st,1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    bool res = solve(v);

    if(!res){
        cout<<-1<<endl;
    }
    else{
        vector<int> grp1,grp2;
        for(int i=1;i<n;i++){
            if(clr[i]==1){
                grp1.push_back(i);
            }
            else if(clr[i]==2){
                grp2.push_back(i);
            }
        }

        cout<<"1\n";
        for(int i=0;i<(int)grp1.size();i++){
            if(i)cout<<" ";
            cout<<grp1[i];
        }
        cout<<"\n2\n";
        for(int i=0;i<(int)grp2.size();i++){
            if(i)cout<<" ";
            cout<<grp2[i];
        }
        cout<<"\n";
    }
}
