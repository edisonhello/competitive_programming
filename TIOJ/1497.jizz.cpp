#include<bits/stdc++.h>
using namespace std;
string s;
struct jizz{
    string s;
    int num;
};
jizz a[1000009];
bool operator < (const jizz &a,const jizz &b){
    return a.s<b.s;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    for(int i=s.length(),j=0;i>=1;i--,j++){
        a[j]={s.substr(j,i),j};
    }
    sort(a,a+s.length());
    for(int i=0;i<s.length();i++)cout<<a[i].num<<'\n';
}
