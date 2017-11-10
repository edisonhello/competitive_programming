#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s; 
    int n=s.length();
    int has0=0;
    for(int i=0;i<n;++i){
        if(s[i]=='0'){has0=1; continue;}
        for(int j=i+1;j<n;++j){
            for(int k=j+1;k<n;++k){
                int val=(s[i]-'0')*100+(s[j]-'0')*10+s[k]-'0';
                if(val%8==0){
                    cout<<"YES\n"<<s[i]<<s[j]<<s[k]<<endl;
                    exit(0);
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        if(s[i]=='0'){has0=1; continue;}
        for(int j=i+1;j<n;++j){
                int val=(s[i]-'0')*10+s[j]-'0';
                if(val%8==0){
                    cout<<"YES\n"<<s[i]<<s[j]<<endl;
                    exit(0);
                }
        }
    }
    for(int i=0;i<n;++i){
                int val=s[i]-'0';
                if(val%8==0){
                    cout<<"YES\n"<<s[i]<<endl;
                    exit(0);
                }
    }
    cout<<"NO"<<endl;
}
