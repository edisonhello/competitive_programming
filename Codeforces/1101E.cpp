#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a=0,b=0;
    int n; cin>>n; while(n--){
        char c; int x,y; cin>>c>>x>>y;
        if(x>y)swap(x,y);
        if(c=='+')a=max(a,x),b=max(b,y);
        else cout<<(x>=a&&y>=b?"YES":"NO")<<'\n';
    }
}
