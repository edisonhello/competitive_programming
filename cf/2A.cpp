#include<bits/stdc++.h>
using namespace std;

map<string,int> h;

int getn(string n){
    if(h.find(n)==h.end()){
        h[n] = h.size();
    }
    return h[n];
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string name;int pt;
        cin>>name>>pt;
        int namen = getn(name);

        vector<int>
    }
}
