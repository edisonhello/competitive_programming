#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 long long

int main(){
    ll nnn,hhh; cin>>nnn>>hhh;
    i128 n=nnn,h=hhh;
    i128 L=1,R=2e9;
    while(L<R){
        i128 mid=(L+R)>>1;
        if([&](i128 dis)->bool{
            bool topstyle=!((h&1)^(dis&1));
            i128 chendis=dis-h+1;
            if(dis<=h){
                i128 nn=(dis+1)*dis/2;
                return nn>=n;
            }
            else if(topstyle){
                i128 updis=chendis/2;
                i128 toph=h+updis;
                i128 ln=(toph+h)*(updis+1)/2;
                i128 rn=(toph+1)*toph/2;
                return ln+rn-toph>=n;
            }
            else{
                i128 updis=chendis/2-1;
                i128 toph=h+updis;
                i128 ln=(toph+h)*(updis+1)/2;
                i128 rn=(toph+1)*toph/2;
                return ln+rn>=n;
            }
        }(mid))R=mid;
        else L=mid+1;
    }
    cout<<(ll)L<<endl;
}
