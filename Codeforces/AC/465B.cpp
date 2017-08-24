#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        a.push_back(t);
    }
    vector<int> b;
    int i,j,tot1=0;
    for(i=0;i<n;i=j+1){
        int cnt=0;
        for(j=i;j<n && a[j]==1;j++){
            cnt++;
            tot1++;
        }
        if(cnt!=0){
            b.push_back(cnt);
        }
    }
    int ans=0;
    for(int i=0;i<b.size();i++){
        ans++;
        ans+=b[i]-1;
        ans++;
    }
    if(b.size())ans--;
    cout<<ans<<endl;
}
