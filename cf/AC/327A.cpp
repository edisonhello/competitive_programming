#include<bits/stdc++.h>
using namespace std;
int a[105],n;//,dpa[105][105];
/*int dp(int l,int r){
    if(!dpa[l][r]){
        if()
    }
    return dpa[l][r];
}*/
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int mx=0;
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(l<=i && i<=r){
                    if(a[i]==0){
                        cnt++;
                    }
                }
                else{
                    if(a[i]){
                        cnt++;
                    }
                }
            }
            // cout<<l<<" "<<r<<" "<<cnt<<endl;
            mx=max(mx,cnt);
        }
    }
    cout<<mx<<endl;
}
