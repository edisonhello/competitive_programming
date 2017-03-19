#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;while(cin>>n){
        string sa,sb;cin>>sa>>sb;
        int aa=0,bb=0;
        while(n--){
            int v,a,b;cin>>v>>a>>b;
            if(a>b)aa+=v;
            else bb+=v;
        }
        if(aa>bb)cout<<sa<<endl;
        else if(aa<bb)cout<<sb<<endl;
        else cout<<"Tie\n";
    }
}
