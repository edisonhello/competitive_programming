#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;

    while(n--){
        int tmp;cin>>tmp;
        while(tmp--){
            cout<<"P";
            if(n!=0)cout<<"RL";
            else cout<<"LR";
        }
        if(n!=0)cout<<"R";
    }cout<<endl;
}
