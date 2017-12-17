#include<bits/stdc++.h>
using namespace std;

int cnt(int x,int y,int z,int a,int b){
    int mn=1000000009;
    if(z>=x+y){
        mn=min(mn,(x+y)*b+(z-x-y)*a);
    }
    else{
        mn=min(mn,((x+y+z)&1?a+(x+y+z)/2*b:(x+y+z)/2*b));
    }
    mn=min(mn,(x+y+z)*a);
    return x>=0?mn:1000000009;
}
int _[3];
int main(){
    int t; cin>>t; while(t--){
        int &x=_[0],&y=_[1],&z=_[2],a,b,c; cin>>x>>y>>z>>a>>b>>c;
        sort(_,_+3);
        int mn=1000000009;
        mn=min(mn,cnt(x,y,z,a,b));
        mn=min(mn,x>=1?cnt(x-1,y-1,z-1,a,b)+c:1000000009);
        mn=min(mn,cnt(0,y-x,z-x,a,b)+c*x);
        mn=min(mn,x>=1?cnt(1,y-x+1,z-x+1,a,b)+c*(x-1):1000000009);
        mn=min(mn,(x+y-z>=0?cnt(z-y,z-x,z*2-x-y,a,b)+c*(x+y-z):1000000009));
        mn=min(mn,(x+y-z-1>=0?cnt(z-y+1,z-x+1,z*2-x-y+1,a,b)+c*(x+y-z-1):1000000009));
        cout<<mn<<endl;
    }
}
// TLE 400
// WA 400
// WA 400
// tutorial: AC
