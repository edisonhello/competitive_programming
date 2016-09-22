#include<bits/stdc++.h>
using namespace std;

map<string,bitset<3> > ina;
map<string,int> inf;

int main(){
    for(int i=0;i<32;i++){
        bitset<5> bs(i);
        bitset<4> o;
        bitset<3> f;
        o[3]=!(bs[4]&bs[3]);
        o[2]=!(bs[3]&bs[2]);
        o[1]=!(bs[2]&bs[1]);
        o[0]=!(bs[1]&bs[0]);
        f[2]=!(o[3]&o[2]);
        f[1]=!(o[2]&o[1]);
        f[0]=!(o[1]&o[0]);
        // cout<<bs<<"->"<<f<<endl;
        stringstream ss;
        ss<<bs;
        string s;
        ss>>s;
        // cout<<bs[0]<<endl;
        ina[s]=f;
        stringstream sss;
        sss<<f;
        string ssss;
        sss>>ssss;
        inf[ssss]++;
    }
    string s;
    while(cin>>s){
        if(s.length()==5){
            cout<<ina[s]<<endl;
        }
        else{
            cout<<inf[s]<<endl;
        }
    }
}
