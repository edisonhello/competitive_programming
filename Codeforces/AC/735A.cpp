#include<iostream>
using namespace std;

int n,k;
string s;

int main(){
    cin>>n>>k>>s;
    for(int i=0;i<(int)s.length();++i){
        if(s[i]=='G'){
            while(i<(int)s.length()){
                if(s[i+k]=='#'){
                    cout<<"NO\n";
                    return 0;
                }
                i+=k;
                if(s[i]=='T'){
                    cout<<"YES\n";
                    return 0;
                }
            }
            cout<<"NO\n";
            return 0;
        }
        if(s[i]=='T'){
            while(i<(int)s.length()){
                if(s[i+k]=='#'){
                    cout<<"NO\n";
                    return 0;
                }
                i+=k;
                if(s[i]=='G'){
                    cout<<"YES\n";
                    return 0;
                }
            }
            cout<<"NO\n";
            return 0;
        }
    }
}
