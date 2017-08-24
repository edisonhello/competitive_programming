#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> a;a.resize(n);

    for(int i=0;i<n;i++)cin>>a[i];

    int cnt=1,mx=1;
    for(int i=1;i<n;i++){
        if(a[i]>=a[i-1]){
            cnt++;
            mx = max(mx,cnt);
        }
        else{
            cnt = 1;
        }
    }

    cout<<mx<<endl;
}
