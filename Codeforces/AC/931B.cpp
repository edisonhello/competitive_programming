#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b; cin>>n>>a>>b; --a, --b;
    int ans=0;
    for(int i=30;i>=0;--i){
        if(((1<<i)&a)^((1<<i)&b)){
            ans=i;break;
        }
    }
    if((1<<(ans+1))==n)cout<<"Final!"<<endl;
    else cout<<ans+1<<endl;
}
