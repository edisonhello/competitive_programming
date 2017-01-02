#include<string>
#include<iostream>
using namespace std;

int main(){
    int pos=0;
    int M;cin>>M;while(M--){
        int d;string s;
        cin>>d>>s;
        if((s[0]=='E' || s[0]=='W')&&(pos==0 || pos==20000)){
            cout<<"NO\n";
            return 0;
        }
        if(s[0]=='E' || s[0]=='W')continue;
        if(s[0]=='S'){
            if(pos+d>20000){
                cout<<"NO\n";
                return 0;
            }
            pos+=d;
        }
        else{
            if(pos-d<0){
                cout<<"NO\n";
                return 0;
            }
            pos-=d;
        }
    }
    if(pos)cout<<"NO\n";
    else cout<<"YES\n";
}
