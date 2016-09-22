#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int Z=1e9+7;

inline ll gcd(ll a,ll b){
    if(b>a)swap(a,b);
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

map<ll,ll> f;
ll F(ll n){
    if(f.count(n)) return f[n];
    ll k=n/2;
    if(n%2==0)
		return f[n]=(F(k)*F(k)%Z+F(k-1)*F(k-1)%Z) % Z;
	else
		return f[n]=(F(k)*F(k+1)%Z+F(k-1)*F(k)%Z) % Z;
}

int main(){
    f[1]=1;f[2]=2;

    /*for(int i=1;i<80;i++){
        printf("%2d:: ",i);
        for(int j=1;j<=50;j++){
            if(gcd(f[j],f[j+i])==1)printf("%d:XXXXX ",j);
            else printf("%d:%3lld   ",j,gcd(f[j],f[j+i]));
        }
        cout<<endl;
    }*/
    /*for(int i=6;i<1000002;i++){
        if(f[i]==f[5])cout<<i<<endl;
    }*/
    // cout<<"asd"<<endl;
    ll a,b;
    cin>>a>>b;
    ll g=gcd(a+1,b+1)-1;
    f[0]=1;
    f[1]=1;
    f[2]=2;

    /*for(ll i=3;i<=g;i++){
        f[i%3] = (f[(i+1)%3]+f[(i+2)%3])%Z;
    }*/

    // cout<<F(1)<<" "<<F(2)<<endl;
    cout<<F(g)<<endl;

}
