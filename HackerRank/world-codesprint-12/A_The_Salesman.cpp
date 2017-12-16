#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n; int mx=-1,mn=1001; while(n--){
            int t; cin>>t; mx=max(mx,t); mn=min(mn,t);
        }
        cout<<mx-mn<<endl;
    }
}
