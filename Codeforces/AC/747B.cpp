#include<iostream>
using namespace std;


int main(){
    int n,a,c,g,t,e;cin>>n;
    a=c=g=t=0;
    if(n%4){
        cout<<"===\n";
        return 0;
    }
    e=n>>2;
    string s;cin>>s;
    for(char ch:s){
        if(ch=='?')continue;
        if(ch=='A')++a;
        if(ch=='C')++c;
        if(ch=='G')++g;
        if(ch=='T')++t;
    }
    if(a>e||c>e||g>e||t>e){
        cout<<"===\n";
        return 0;
    }
    for(char &ch:s){
        if(ch=='?'){
            if(a<e){
                ch='A';++a;
            }
            else if(c<e){
                ch='C';++c;
            }
            else if(g<e){
                ch='G';++g;
            }
            else if(t<e){
                ch='T';++t;
            }
        }
    }
    cout<<s<<endl;
}
