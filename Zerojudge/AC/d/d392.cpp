#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string s; while(getline(cin,s)){
        stringstream ss(s);
        ll ans=0,t;
        while(ss>>t){
            ans+=t;
        }
        cout<<ans<<endl;
    }
}
