#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second

int main(){
    string inp;
    ll ans = 1;
    while(getline(cin,inp)){
        istringstream iss(inp);
        string s;
        while(iss>>s){
            if(s=="%"){
                cout<<ans<<endl;
                ans=1;
            }
            else{
                istringstream isss(s);
                ll l;isss>>l;
                ans*=l;
                ans%=479001599;
            }
        }
    }
}
