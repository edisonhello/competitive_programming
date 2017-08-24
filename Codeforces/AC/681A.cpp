#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        int f,b;cin>>f>>b;
        if(f>=2400 && b>f){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
}
