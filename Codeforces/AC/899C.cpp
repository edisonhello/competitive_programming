#include<bits/stdc++.h>
using namespace std;

int main(){
    int diff=0;
    vector<int> a;
    int n; cin>>n; while(n){
        if(n<4){
            if(n==3)a.push_back(1),a.push_back(2);
            if(n==2)a.push_back(1),diff=1;
            if(n==1)a.push_back(1),diff=1;
            break;
        }
        a.push_back(n-1);
        a.push_back(n-2);
        n-=4;
    }
    cout<<diff<<endl;
    cout<<a.size();
    for(int i:a)cout<<" "<<i; cout<<endl;
}
