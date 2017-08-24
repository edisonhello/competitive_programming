#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> a;
    a.resize(n);
    int mx=-989,mn=989;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx = max(mx,a[i]);
        mn = min(mn,a[i]);
    }
    // int cnt=0;
// cout<<mx<<" "<<mn<<endl;
    int mxs,mns;
    bool xonce = false;
    for(int i=0;i<n;i++){
        if(a[i]==mx && !xonce){
            mxs = i;
            xonce = 1;
        }
        if(a[i]==mn){
            mns = i;
        }
    }
// cout<<mxs<<" "<<mns<<endl;
    if(mxs>mns){
        cout<<mxs+n-2-mns<<endl;
    }
    else{
        cout<<mxs+n-1-mns<<endl;
    }
}
