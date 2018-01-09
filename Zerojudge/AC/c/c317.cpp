#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n; while(n--){
        int x,a,b; cin>>x>>a>>b;
        int mx=10101010;
        for(int i=0;i<=1000;++i){
            if(x-i*a>=0 && (x-i*a)%b==0){
                mx=min(mx,i+(x-i*a)/b);
            }
        }
        if(mx==10101010)cout<<-1<<endl;
        else cout<<mx<<endl;
    }
}
