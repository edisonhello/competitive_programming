#include<iostream>
#include<algorithm>
using namespace std;
string a,b;
int main(){
    cin>>a>>b;
    if(a==b)cout<<-1<<endl;
    else cout<<max(a.length(),b.length())<<endl;
}
