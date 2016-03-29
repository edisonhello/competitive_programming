#include<bits/stdc++.h>

using namespace std;

int main(){
    string a;cin>>a;

    if(a.find("0000000")<250 || a.find("1111111")<656){
        cout<<"YES"<<endl;
    }else{cout<<"NO"<<endl;}

}
