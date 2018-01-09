#include<bits/stdc++.h>
using namespace std;

string ans[44];

int main(){
    ans[1]="1";
    ans[2]="11";
    for(int i=3;i<=40;++i){
        for(int j=0,k;j<ans[i-1].size();j=k){
            for(k=j;ans[i-1][j]==ans[i-1][k];++k){
                
            }
            ans[i]+=(char)(k-j+'0');
            ans[i]+=ans[i-1][j];
        }
    }
    int n; while(cin>>n){
        cout<<ans[n]<<endl;
    }
}
