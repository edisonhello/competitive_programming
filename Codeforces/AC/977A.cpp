#include<bits/stdc++.h>
using namespace std;


int main(){
    string n; int k; cin>>n>>k;
    while(k--){
        if(n.back()=='0')n.pop_back();
        else --n.back();
    }
    cout<<n<<endl;
}
