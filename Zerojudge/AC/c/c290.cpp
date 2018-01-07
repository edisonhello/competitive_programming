#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int ans=0,sgn=1;
    for(char c:s){
        ans+=(c-'0')*sgn;
        sgn*=-1;
    }
    cout<<abs(ans)<<endl;
}
