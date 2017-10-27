#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int a[4];
        cin>>a[0]>>a[1]>>a[2]>>a[3];
        cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" ";
        if(a[1]-a[0]==a[2]-a[1]){
            cout<<a[3]*2-a[2]<<endl;
            continue;
        }
        cout<<a[3]*a[3]/a[2]<<endl;
    }
}
