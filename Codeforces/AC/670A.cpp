#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int ans1=0,ans2=0;
    for(int i=0;i<n;i++){
        if(i%7==0||i%7==1){
            ans2++;
        }
        if(i%7==5||i%7==6){
            ans1++;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
}
