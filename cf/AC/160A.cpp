#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;int tot=0;
    vector<int>c;
    for(int i=0;i<n;i++){
        int t;cin>>t;tot+=t;
        c.push_back(t);
    }
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    int now=0;
    int i;
    for(i=0;i<c.size();i++){

        now+=c[i];
        if(now>tot/2){
            cout<<i+1<<endl;
            return 0;
        }
    }cout<<c.size()<<endl;
}
