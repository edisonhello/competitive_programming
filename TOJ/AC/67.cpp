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

ll tot;


int main(){
    string inp;
    while(getline(cin,inp)){
        istringstream iss(inp);
        int ans = 0;

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
                int u,d;
                issu >> u;
                issd >> d;
                if(u%d==0)ans+=(ll)(u/d);
            }
            else{
                istringstream isss(s);
                int add;
                isss >> add;
                ans += (ll)add;
            }
        }
        cout<<ans<<endl;
    }
}
