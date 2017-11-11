#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<long long> v;
    int n; cin>>n; long long in,tot=0;
    while(n--){
        cin>>in;
        if(in&1)v.push_back(in);
        else tot+=in;
    }
    sort(v.begin(),v.end(),greater<long long>());
    v.resize(v.size()/2*2);
    for(long long &i:v)tot+=i;
    cout<<tot<<endl;
}
