#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
using namespace std;
bool cnt[123];
int main(){
    int n;cin>>n;
    string s;cin>>s;
    for(char c:s){
        if(c>='a')c-=32;
        cnt[c]++;
    }
    for(int i='A';i<='Z';++i){
        if(!cnt[i]){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
}
