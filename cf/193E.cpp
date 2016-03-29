#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull mod=10000000000000;
int main(){
    ull n;cin>>n;

    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    if(n==2){
        cout<<3<<endl;
        return 0;
    }



    vector<ull> f;
    f.push_back(0);
    f.push_back(1);
    for(int i=2;;i++){
        ull fibi = f[i-1]+f[i-2];
        if(fibi==n){
            cout<<i<<endl;cout<<f.back()<<endl;
            return 0;
        }
        /*if(fibi>n){
            cout<<-1<<endl;cout<<i<<" "<<f.back()<<endl;
            return 0;
        }*/
        if(i>=mod){
            cout<<-1<<endl;
            return 0;
        }
        f.push_back(fibi%mod);
    }cout<<f.back()<<endl;
}
