#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin>>n;
    if(n<=7){
        cout<<n<<endl;
        while(n--){
            cout<<0;
        }
        cout<<endl;
    }
    else if(n==8){
        cout<<7<<endl;
        cout<<"00110100"<<endl;
    }
    else{
        cout<<8<<endl;
        string s="001011";
        while(s.size()<n)s=s+s;
        reverse(s.begin(),s.end());
        s=s.substr(0,n);
        cout<<s<<endl;
    }
}
