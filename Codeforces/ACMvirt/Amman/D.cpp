#include<bits/stdc++.h>
using namespace std;



int main(){
    int t; cin>>t; while(t--){
        long long x,y; cin>>x>>y;
        long long ans=LLONG_MAX;

        auto meow=[&](long long x,long long y)->long long{
            if(y&1){
                long long a,b;
                if(x&1)a=b=(x+1)/2;
                else a=x/2,b=x/2+1;
                return a*(y/2+1)+b*(y/2);
            }
            else{
                long long a,b;
                if(x&1)a=b=(x+1)/2;
                else a=x/2,b=x/2+1;
                return (a+b)*(y/2);
            }
        };
        ans=min(ans,meow(x,y));
        ans=min(ans,meow(y,x));
        cout<<ans<<endl;
    }
}
