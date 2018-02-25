#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the function below.
 */
int maximumPackages(vector<int> S, vector<int> K, vector<int> R, vector<int> C) {
    // Return the maximum number of packages that can be put in the containers.
    int n=S.size(),m=R.size();
    vector<pair<int,int>> SK,RC;
    for(int i=0;i<n;++i)SK.emplace_back(S[i],K[i]);
    sort(SK.begin(),SK.end());
    
    queue<int> q;
    for(auto i:SK)for(int j=0;j<i.second;++j)q.push(i.first);
    int ans=0;
    for(int i=0;i<m;++i)RC.emplace_back(R[i],C[i]);
    sort(RC.begin(),RC.end());
    for(auto i:RC)for(int j=0;j<i.second;++j){
        if(q.size() && i.first*sqrt(2)>q.front()){
            ++ans;
            q.pop();
        }
        else break;
    }
    return ans;
}


int main()
{
    int n,m; cin>>n>>m;
    vector<int> S,K,R,C;
    for(int i=0;i<n;++i){
        int t; cin>>t; S.push_back(t);
    }
    for(int i=0;i<n;++i){
        int t; cin>>t; K.push_back(t);
    }
    for(int i=0;i<m;++i){
        int t; cin>>t; R.push_back(t);
    }
    for(int i=0;i<m;++i){
        int t; cin>>t; C.push_back(t);
    }
    cout<<maximumPackages(S,K,R,C)<<endl;
    return 0;
}
