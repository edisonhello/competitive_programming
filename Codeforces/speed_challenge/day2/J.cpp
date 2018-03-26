#include<bits/stdc++.h>
using namespace std;

int cnt[44];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i){
        int t; cin>>t;
        cnt[i%3]+=t;
    }
    if(cnt[0]>cnt[1] && cnt[0]>cnt[2]){
        cout<<"chest"<<endl;
    }
    else if(cnt[1]>cnt[0] &&cnt[1]> cnt[2]){
        cout<<"biceps"<<endl;
    }
    else{
        cout<<"back"<<endl;
    }
}
