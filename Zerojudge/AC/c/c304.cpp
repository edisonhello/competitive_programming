#include<bits/stdc++.h>
using namespace std;

string rev(string s){
    reverse(s.begin(),s.end());
    return s;
}
int main(){
    string s; while(cin>>s){
        string ss=rev(s);
        long long a,b;
        stringstream sss(s); sss>>a;
        stringstream ssss(ss); ssss>>b;
        cout<<a+b<<endl;
    }
}
