#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>

char wrd[30][15][15];

int main(){
    // freopen("pTA.in.1","r",stdin);
    int l,h;string s,ip;
    cin>>l>>h;
    getline(cin,s);
    getline(cin,s);
    for(int k=0;k<h;++k){
        getline(cin,ip);int ptr=0;
        for(int i=0;i<27;++i){
            for(int j=0;j<l;++j){
                wrd[i][j][k]=ip[ptr++];
            }
        }
        // getchar();
    }

    for(int k=0;k<h;++k){
        for(char i:s){
            if(i>='a' && i<='z')i-='a';
            else if(i>='A' && i<='Z')i-='A';
            else i=26;
            for(int j=0;j<l;++j){
                cout<<wrd[i][j][k];
            }
        }
        cout<<endl;
    }
}
