#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    int n;
    bool app[300]={0};
    bool jizz=0;
    string sssss;
    getline(cin,sssss);
    while(cin>>n){
        if(app[n] || n<=0){
            cout<<"jizzed:\n";
            jizz=1;
        }
        v.push_back(n);
        app[n]=1;
    }
    if(jizz){
        cout<<sssss<<endl;
        for(int i:v)cout<<i<<" ";
        cout<<endl;
    }
}
