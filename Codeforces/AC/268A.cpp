#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> a,b;
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]==b[j]){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
