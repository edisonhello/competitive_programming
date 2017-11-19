#include<bits/stdc++.h>
using namespace std;

int a[1000006];
bool dth[1000006];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    for(int i=n-1,plft=0;i>=0;--i){
        if(plft>0){
            --plft;
            dth[i]=1;
        }
        plft=max(plft,a[i]);
    }
    int cnt=0;
    for(int i=0;i<n;++i)if(!dth[i])++cnt;
    cout<<cnt<<endl;
}
