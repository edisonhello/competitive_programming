#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;

    while(s.find("WUB")<98989){
        int sit = s.find("WUB");
        s[sit] = s[sit+1] = s[sit+2] = ' ';
    }



    bool sp = false;
    bool spp = true;
    for(int i=0;i<(int)s.length();i++){
        if(s[i]!=' '){
            if(sp){
                if(!spp){
                    cout<<' ';
                    sp = false;
                }
            }
            spp = false;
            sp = false;
            cout<<s[i];
        }
        else{
            sp = true;
        }
    }
    cout<<endl;
}
