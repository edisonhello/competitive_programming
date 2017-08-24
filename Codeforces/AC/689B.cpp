#include<bits/stdc++.h>
using namespace std;


int n;
vector<int> path[200005];
vector<int> rec;
vector<bool> gone;

queue<pair<int/*now*/,int/*length*/> > bfsq;

void solve(){
    gone[1] = 1;
    rec[1] = 0;
    for(int i=0;i<(int)path[1].size();i++){
        if(!gone[path[1][i]]){
            gone[path[1][i]] = 1;
            // cout<<"bfs go "<<1<<"->"<<path[1][i]<<endl;
            bfsq.push(make_pair(path[1][i],1));
        }
    }

    while(bfsq.size()){
        int now = bfsq.front().first;
        int lng = bfsq.front().second;

        // cout<<"walking "<<now<<endl;

        rec[now] = lng;

        for(int i=0;i<(int)path[now].size();i++){
            // cout<<"trying "<<path[now][i]<<endl;
            // cout<<gone[7]<<endl;
            if(!gone[path[now][i]]){
                gone[path[now][i]] = 1;
                // cout<<"bfs go "<<now<<"->"<<path[now][i]<<endl;
                bfsq.push(make_pair(path[now][i],lng+1));
            }
        }

        bfsq.pop();
    }
}

void print(){
    for(int i=1;i<=n;i++){
        if(i-1)cout<<" ";
        cout<<rec[i];
    }
    cout<<endl;
}

int main(){
    cin>>n;

    rec.resize(n+5);
    rec.clear();
    gone.resize(n+5);
    gone.clear();
    // cout<<gone[7]<<endl;
    for(int i=1;i<=n;i++){
        int t;cin>>t;
        path[i].push_back(t);
        if(i-1)path[i].push_back(i-1);
        if(i<n)path[i].push_back(i+1);
    }

// cout<<"de";
// for(int i=0;i<3;i++)cout<<path[5][i]<<" ";cout<<endl;

    solve();

    print();
}
