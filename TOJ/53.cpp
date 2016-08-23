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
    while(getline(cin,inp)){
        istringstream iss(inp);
        ull ans = 0;

        string s;
        while(iss>>s){
            istringstream isss(s);
            ull i;
            isss>>i;
            ans+=i;
            ans %= 1000000007;
        }
        cout<<ans<<endl;
    }
}
