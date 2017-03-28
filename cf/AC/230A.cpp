#include<bits/stdc++.h>
using namespace std;

pair<int,int> a[1009];
int main(){
    int s,n;cin>>s>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n);
    for(int i=0;i<n;++i){
        if(a[i].first>=s){
            cout<<"NO"<<endl;
            return 0;
        }
        s+=a[i].second;
    }
    cout<<"YES\n";
}
