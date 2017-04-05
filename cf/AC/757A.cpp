#include<iostream>
#include<algorithm>
using namespace std;

int cnt[6546];

int main(){
    string s;cin>>s;
    for(char i:s)cnt[i]++;
    cout<<min({cnt['B'],cnt['u']/2,cnt['l'],cnt['b'],cnt['a']/2,cnt['s'],cnt['r']})<<endl;
}
