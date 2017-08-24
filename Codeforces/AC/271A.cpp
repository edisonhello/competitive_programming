#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;

    for(int i=n+1;;i++){
        int _=i%10;
        int __=i%100/10;
        int ___=i%1000/100;
        int ____=i/1000;
        if(_!=__&&_!=___&&_!=____&&__!=___&&__!=____&&___!=____){
            cout<<i<<endl;
            return 0;
        }
    }
}
