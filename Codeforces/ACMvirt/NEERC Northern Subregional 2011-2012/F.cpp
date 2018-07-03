#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("flat.in","r",stdin);
    freopen("flat.out","w",stdout);
    int n,c; cin>>n>>c;
    int all=0,bed=0,bal=0;
    for(int i=0;i<n;++i){
        int t; cin>>t;
        string s; cin>>s;
        all+=t;
        if(s=="bedroom")bed+=t;
        if(s=="balcony")bal+=t;
    }
    cout<<all<<endl<<bed<<endl;
    cout<<fixed<<setprecision(15)<<(all-(double)bal/2)*c<<endl;
}
