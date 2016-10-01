#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<assert.h>

#define PB push_back
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    string ss;
    string s;
    getline(cin,ss);
    do{
        getline(cin,ss);
        stringstream sss;
        sss<<ss;
        sss>>s;
        assert(s=="IF");
        vector<string> P,Q;
        bool _=0;
        while(sss>>s){
            if(s=="THEN")break;
            if(s=="not"){
                _=!_;
            }
            else if(s=="and"){
                Q.PB("or");
            }
            else if(s=="or"){
                Q.PB("and");
            }
            else{
                assert(s[0]>='A'&&s[0]<='Z'&&s.length()==1);
                if(!_){
                    Q.PB("not");
                }
                _=0;
                Q.PB(s);
            }
        }
        while(sss>>s){
            if(s=="not"){
                _=!_;
            }
            else if(s=="and"){
                P.PB("or");
            }
            else if(s=="or"){
                P.PB("and");
            }
            else{
                assert(s[0]>='A'&&s[0]<='Z'&&s.length()==1);
                if(!_){
                    P.PB("not");
                }
                _=0;
                P.PB(s);
            }
        }
        cout<<"IF";
        for(string i:P){
            cout<<" "<<i;
        }
        cout<<" THEN";
        for(string i:Q){
            cout<<" "<<i;
        }
        cout<<'\n';
    }while(--n);
}
