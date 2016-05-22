#include<bits/stdc++.h>

using namespace std;



int main(){
    int n,m;cin>>n>>m;
    int tmp,src=0;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        if(i==m)src=tmp;
        if(src && tmp<src){
            cout<<i-1<<endl;
            return 0;
        }
        if(tmp==0){
            cout<<i-1<<endl;
            return 0;
        }
    }
    cout<<n<<endl;
}
