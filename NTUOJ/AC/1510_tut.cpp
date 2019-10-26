#include<bits/stdc++.h>
using namespace std;

double pre[50000007];

double get(int x){
    if(x<=50000000)return pre[x];
    else return log(x)-log(50000001)+pre[50000000];
}

int main(){
    for(int i=1;i<=50000000;++i)pre[i]=pre[i-1]+double(1)/i;
    int w,l,k=0; while(cin>>w>>l,w+l){
        cout<<"Case "<<(++k)<<":\n";
        if(l==0){
            if(w%8)cout<<"Situation Impossible."<<endl;
            else cout<<"On Average Bob Reaches Round 8.00"<<endl;
            continue;
        }
        // int L=max(l,(w+l+1)/8);
        // int R=(w+8*l)/8;
        // cout<<"L, R: "<<L<<" "<<R<<endl;
        int L=[&](){
            int usew=l*7;
            int wleft=w-usew;
            if(wleft<=0)return l;
            return (wleft+7)/8+l;
        }();
        int R=[&](){
            return l+(w/8);
        }();
        // cout<<L<<" "<<R<<endl;
        double ans=double(w+l)/(R-L+1);
        ans*=(get(R)-get(L-1));
        cout<<"On Average Bob Reaches Round ";
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
}

#ifdef MATH

p tourments
L losses
W wins

p >= L
8(p-L) <= W
p <= (W+8L) / 8

avg: (W+L)/p 
(W+L)/8 <= p

=> L <= p <= (W+8L)/8

#endif
