#include<bits/stdc++.h>
using namespace std;
#define stack vector
#define emplace emplace_back

string s[111];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i){
        cin>>s[i];
    }
    {
        stack<pair<int,int>> ans;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(s[i][j]=='.'){
                    ans.emplace(i,j);
                    break;
                }
            }
        }
        if(ans.size()==n){
            for(auto i:ans){
                cout<<i.first+1<<" "<<i.second+1<<endl;
            }
            exit(0);
        }
    }
    {
        stack<pair<int,int>> ans;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(s[j][i]=='.'){
                    ans.emplace(j,i);
                    break;
                }
            }
        }
        if(ans.size()==n){
            for(auto i:ans){
                cout<<i.first+1<<" "<<i.second+1<<endl;
            }
            exit(0);
        }
    }
    cout<<-1<<endl;
}
