#include<bits/stdc++.h>
#define ll long long
using namespace std;

int line,word,chr;
int main(){
    ios_base::sync_with_stdio(0);
    int ts;cin>>ts;
    string s;
    getline(cin,s);
    while(ts--){
        while(getline(cin,s)){
            if(s=="====="){
                // cout<<line<<" "<<word<<" "<<chr<<'\n';
                break;
            }
            ++line;
            chr+=(int)s.length();
            stringstream ss(s);
            while(ss>>s)++word;
        }
        cout<<line<<" "<<word<<" "<<chr<<'\n';
        line=word=chr=0;
    }
}
