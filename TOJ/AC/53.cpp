#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        stringstream ss(s);
        long long ans=0,tmp;
        while(ss>>tmp)ans+=tmp;
        cout<<ans%1000000007<<endl;
    }
}
