#include<bits/stdc++.h>
using namespace std;

int n,i,a[100005];
bitset<100005> v;
int main(){
    vector<vector<int>> c;
    for(cin>>n,i=1;i<=n;cin>>a[i],++i);
    for(int i=1;i<=n;++i){
        if(v[i])continue;
        vector<int> ve(1,i);
        v[i]=1;
        int j=a[i];
        while(j!=i){
            v[j]=1;
            ve.push_back(j);
            j=a[j];
        }
        c.push_back(ve);
    }
    sort(c.begin(),c.end(),[](const vector<int> &a,const vector<int> &b){return a.size()<b.size();});
    /* for(auto v:c){
        for(int i:v)cout<<i<<" ";
        cout<<endl;
    } */
    if(c[0].size()>2u)exit((cout<<"NO"<<endl,0));
    for(int i=1;i<c.size();++i)if(c[i].size()%c[0].size())exit((cout<<"NO"<<endl,0));
    cout<<"YES"<<endl;
    for(int i=1;i<c.size();++i)for(int j=0;j<c[i].size();++j)cout<<c[i][j]<<" "<<c[0][j%c[0].size()]<<'\n';
    if(c[0].size()>1u)cout<<c[0][0]<<" "<<c[0][1]<<endl;
}
