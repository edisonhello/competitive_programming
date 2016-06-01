#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<int> a;a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<i;j++){
            if(a[j]>a[i]){
                cnt++;
            }
        }
        if(cnt>m){
            cout<<"no"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;


}
