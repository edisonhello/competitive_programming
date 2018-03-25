#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b; cin>>n>>a>>b;
    int c=0;
    for(int i=1;i<=n;++i){
        int fr=i-1,bk=n-i;
        if(fr>=a && bk<=b)++c;
    }
    cout<<c<<endl;
}
