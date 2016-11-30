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

ull _gcd(ull a,ull b){
    if(a<b)swap(a,b);

    while(b){
        a -= a/b*b;
        swap(a,b);
    }
    return a;
}

int main(){
    string inp;
    while(getline(cin,inp)){
        istringstream iss(inp);
        ull ans = 1;
        ull but = 1;

        string s;
        while(iss>>s){
            int finds = s.find('/');
            // cout<<finds<<endl;
            if(finds!=(int)string::npos){
                string su=s;
                string sd=s;
                su.assign(su,0,finds);
                sd.assign(sd,finds+1,sd.length());
                // cout<<su<<endl<<sd<<endl;
                istringstream issu(su);
                istringstream issd(sd);
                ull u,d;
                issu >> u;
                issd >> d;
                ans *= u;
                but *= d;
            }
            else{
                istringstream isss(s);
                int add;
                isss >> add;
                ans *= (ull)add;
            }
        }
        if(ans % but==0)cout<<ans/but<<endl;
        else{
            ull gcd = _gcd(ans,but);
            cout<<ans/gcd<<'/'<<but/gcd<<endl;
        }
    }
}
