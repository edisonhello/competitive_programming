#include<bits/stdc++.h>
using namespace std;
int main(){
    map<char,int> m;
    m['A']=1;
    m['B']=10;
    m['C']=19;
    m['D']=28;
    m['E']=37;
    m['F']=46;
    m['G']=55;
    m['H']=64;
    m['I']=39;
    m['J']=73;
    m['K']=82;
    m['L']=2;
    m['M']=11;
    m['N']=20;
    m['O']=48;
    m['P']=29;
    m['Q']=38;
    m['R']=47;
    m['S']=56;
    m['T']=65;
    m['U']=74;
    m['V']=83;
    m['W']=21;
    m['X']=3;
    m['Y']=12;
    m['Z']=30;
    string s; while(cin>>s){
        int check=s[8]-'0',meow=0;
        for(int i=0;i<8;++i)meow+=(s[i]-'0')*(8-i);
        for(int i='A';i<='Z';++i){
            if((m[i]+meow)%10==check)cout<<(char)i;
        } cout<<endl;
    }
}
