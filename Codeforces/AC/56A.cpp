#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int ans=0;
    map<string,int> mp;
    mp["ABSINTH"]=1;
    mp["BEER"]=1;
    mp["BRANDY"]=1;
    mp["CHAMPAGNE"]=1;
    mp["GIN"]=1;
    mp["RUM"]=1;
    mp["SAKE"]=1;
    mp["TEQUILA"]=1;
    mp["VODKA"]=1;
    mp["WHISKEY"]=1;
    mp["WINE"]=1;
    while(n--){
        string s; cin>>s;
        if(s[0]>='0' and s[0]<='9'){
            int a=stoi(s);
            if(a<18)++ans;
        }
        else{
            ans+=mp[s];
        }
    }
    cout<<ans<<endl;
}
