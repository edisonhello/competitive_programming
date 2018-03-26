#include<bits/stdc++.h>
using namespace std;

string mp[333]; 

void no(){
    cout<<"NO"<<endl;
    exit(0);
}

int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>mp[i];
    char sd=mp[0][0],sn=mp[0][1];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i==j || i+j==n-1){
                if(mp[i][j]!=sd)no();
            }
            else if(mp[i][j]!=sn)no();
        }
    }
    if(sd==sn)no();
    cout<<"YES"<<endl;
}
