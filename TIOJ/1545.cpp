#include<bits/stdc++.h>
using namespace std;
#define ld long double

/*
[n-m][m][m-1]

(1/2)^(k)
((((1/2)^(k))^(m-1))-(((1/2)^(k-1)^(m-1))))
((((1/2)^(k-1))^(n-m))-(((1/2)^(k-2)^(n-m))))

0.5 + 0.5^2 + 0.5^3 + ... +0.5^k
0.5*(1 - 0.5^k)/0.5 ( dead in <= k round)
*/

ld pw(ld b,int n,ld a=1){
    if(n<0)return 0;
    while(n){
        if(n&1)a*=b;
        b*=b; n>>=1;
    }
    return a;
}

int main(){
    int n,m; cin>>n>>m;
    ld ans=0;
    for(int k=(n==m?1:2);;++k){
        ld add=1;
        
        add*=pw(0.5,k);
	    // add*=m-1?pw(1-pw(0.5,k),m-1)-pw(1-pw(0.5,k-1),m-1):1;
	    // add*=n-m?pw(1-pw(0.5,k-1),n-m)-pw(1-pw(0.5,k-2),n-m):1;
        ld p1v=pw(1-pw(0.5,k),m-1),p1x=pw(1-pw(0.5,k-1),m-1);
	    ld p2v=pw(1-pw(0.5,k-1),n-m),p2x=pw(1-pw(0.5,k-2),n-m);
        add*=(p1v-p1x)*p2v+(p2v-p2x)*p1v-p1v*p2v;
        // add*=p2v-p2x;
        // add*=(pw(pw(0.5,k),m-1)-pw(pw(0.5,k-1),m-1));
        // add*=(pw(pw(0.5,k-1),n-m)-pw(pw(0.5,k-2),n-m));

        ans+=add;
        if(add<1e-18)break;
    }
    cout<<fixed<<setprecision(20)<<ans<<endl;
}
