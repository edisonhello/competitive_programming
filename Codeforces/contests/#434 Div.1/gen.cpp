#include<bits/stdc++.h>
using namespace std;

string g6s(){
    string s;
    for(int i=0;i<6;++i){
        s+=(char)(rand()%26+'a');
    } return s;
}
set<string> app;
int main(){
    freopen("in","w",stdout);
    srand(time(NULL));
    cout<<100000<<endl;
    for(int i=0;i<100000;++i){
            string s=g6s();
            while(app.find(s)!=app.end())s=g6s();
            cout<<s<<" "<<(rand()&1)<<endl;
    }
}
