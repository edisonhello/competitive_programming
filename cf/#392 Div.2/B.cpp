#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

string s;
char c[5];
int a[999];

int main(){
    cin>>s;
    for(int i=0;i<(int)s.length();++i){
        if(s[i]!='!'){
            c[i%4]=s[i];
        }
    }
    for(int i=0;i<(int)s.length();++i){
        if(s[i]=='!'){
            ++a[c[i%4]];
        }
    }
    cout<<a['R']<<" "<<a['B']<<" "<<a['Y']<<" "<<a['G']<<endl;
}
