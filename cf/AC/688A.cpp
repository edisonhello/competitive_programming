#include<bits/stdc++.h>
using namespace std;
int main(){
    int o,d;cin>>o>>d;
    int mx=0,now=0;
    for(int i=0;i<d;i++){
        string s;cin>>s;
        bool find0 = false;
        for(int j=0;j<o;j++){
            if(s[j]=='0')find0 = true;
        }
        if(find0){
            now++;
            mx = max(mx,now);
        }
        else{
            now = 0;
        }
    }
    cout<<mx<<endl;
}
