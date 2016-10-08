#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        int mx=0;
        for(int i=0;i<(int)s.length();i++){
            for(int j=0;i-j>=0 && i+j<(int)s.length();j++){
                // cout<<"tring i:"<<i<<",j:"<<j;
                if(s[i-j]==s[i+j]){
                    // cout<<" jizzed.\n";
                    mx=max(mx,2*j+1);
                    continue;
                }
                else{
                    // cout<<" yay\n";
                    mx=max(mx,2*j-1);
                    break;
                }
            }
        }
        for(int i=0;i<(int)s.length();i++){
            for(int j=0;i-j>=0 && i+1+j<(int)s.length();j++){
                // cout<<"tring i:"<<i<<",j:"<<j;
                if(s[i-j]==s[i+1+j]){
                    // cout<<" jizzed.\n";
                    mx=max(mx,2*j+2);
                    continue;
                }
                else{
                    // cout<<" yay\n";
                    mx=max(mx,2*j);
                    break;
                }
            }
        }
        cout<<mx<<'\n';
    }
}
