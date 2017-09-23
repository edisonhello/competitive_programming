#include<iostream>
#include<algorithm>
using namespace std;
string a,b,c;

bool cmp(const string &a,const string &b){
    if(a.length()<b.length())return 1;
    if(a.length()>b.length())return 0;
    for(int i=0;i<(int)a.length();++i){
        if(a[i]!=b[i])return a[i]<b[i];
    }
}

int main(){
    int ts;cin>>ts;while(ts--){
        cin>>a>>b>>c;
        cout<<max({a,b,c},cmp)<<endl;
    }
}
