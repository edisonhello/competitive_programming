#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    ll n; while(cin>>s,s!="0"){
        if(s.size()<=19u){
            n=0;
            for(char c:s){
                n=n*10+c-'0';
            }
            int pt=(n%2?2:1);
            ll t; while(cin>>t,t){
                n-=t;
            }
            if(n==0)cout<<pt<<endl;
            else cout<<0<<endl;
        }
        else{
            ll t,tot=0; while(cin>>t,t){
                tot+=t;
            }
            stack<char> st;
            while(tot){
                st.push(tot%10+'0');
                tot/=10;
            }
            string ans;
            while(st.size())ans+=st.top(),st.pop();
            bool mth=1;
            for(int i=0;i<ans.size();++i){
                if(ans[ans.size()-1-i]!=s[s.size()-1-i])mth=0;
            }
            if(!mth)cout<<0<<endl;
            else cout<<(ans.back()&1?2:1)<<endl;
        }
    }
}
