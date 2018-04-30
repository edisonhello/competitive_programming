#include<bits/stdc++.h>
using namespace std;

int rand(int l,int r){
    int val=rand()*rand()*rand(); val=abs(val);
    val%=r-l+1;
    return val+l;
}

int len;
string chem;

namespace subtask1{

void gen(){
    while(chem.size()<len){
        char name=rand('A','Z');
        chem+=name;
        int cnt=rand(1,1000000);
        if(cnt==1)continue;
        stringstream ss; ss<<cnt;
        string add; ss>>add;
        chem+=add;
        chem=chem.substr(0,255);
    }
}

}

namespace subtask2{

void gen(){
    while(chem.size()<len){
        char name=rand('A','Z');
        chem+=name;
        if(rand(0,1)){
            name=rand('a','z');
            chem+=name;
        }
        int cnt=rand(1,1000000);
        if(cnt==1)continue;
        stringstream ss; ss<<cnt;
        string add; ss>>add;
        chem+=add;
        chem=chem.substr(0,255);
    }
}

}

namespace subtask3{

void gen(){
    while(chem.size()<len){
        char name=rand('A','Z');
        chem+=name;
        if(rand(0,1)){
            name=rand('a','z');
            chem+=name;
        }
        int cnt=rand(1,100);
        if(cnt==1)continue;
        stringstream ss; ss<<cnt;
        string add; ss>>add;
        chem+=add;
        chem=chem.substr(0,255);
    }
}

}

int main(){
    srand(clock());
    len=rand(30,230);
    subtask3::gen();
    cout<<chem<<endl;
}
