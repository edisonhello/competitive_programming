#include<bits/stdc++.h>
using namespace std;

char mp[123][123];

int main(){
    string s; 
    int t; cin>>t; 
    getline(cin,s);
    while(t--){
        getline(cin,s);
        int n; n=s.size();
        if(int(sqrt(n))*int(sqrt(n))!=n){
            cout<<"INVALID"<<endl;
            continue;
        }
        int ptr=0;
        n=int(sqrt(n));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                mp[i][j]=s[ptr++];
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cout<<mp[j][i];
            }
        }
        cout<<endl;
    }
}
