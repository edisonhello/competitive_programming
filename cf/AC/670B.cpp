#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int t;cin>>t;
        a.push_back(t);
        if(cnt+i<k){
            cnt+=i;
        }
        else{
            cout<<a[k-cnt-1]<<endl;
            //cout<<k-cnt-1<<endl;
            return 0;
        }
    }
}
