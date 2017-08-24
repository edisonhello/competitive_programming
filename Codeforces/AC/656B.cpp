#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int m[20],r[20];
    memset(m,0,sizeof(m));
    memset(r,0,sizeof(r));
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    int cnt=0;
    for(int i=0;i<1000000;i++){
        for(int j=0;j<n;j++){
            if(i%m[j]==r[j]){
                cnt++;
                break;
            }
        }
    }
    float res=(float)cnt/(float)1000000;
    cout<<res<<endl;
}
