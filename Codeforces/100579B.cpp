#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

const ll p=47017;

int main(){
    int ts,ks=0; cin>>ts; while(ts--){
        unordered_set<ll> st;
        int type=0;
        int n; cin>>n; while(n--){
            string s; cin>>s;
            ll nowp=1,sum=0;
            bool ok=0;
            for(char c:s){
                sum+=c*nowp; if(!ok)++type; nowp*=p;
                if(st.find(sum)==st.end())st.insert(sum),ok=1;
            }
        }
        cout<<"Case #"<<(++ks)<<": "<<type<<endl;
    }
}
