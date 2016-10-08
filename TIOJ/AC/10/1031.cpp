#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    while(getline(cin,s)){
        if(s[0]=='0')break;
        stringstream ss;ss<<s;
        int ans=0,n;
        while(ss>>n && n){
            int i;
            for(i=1;i<=n;i<<=1){}
            ans+=(i>>1);
        }
        cout<<ans<<'\n';
    }
}
