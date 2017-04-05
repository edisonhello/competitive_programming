#include<bits/stdc++.h>
#include"op.cpp"
#include"getVarName.cpp"
#include"declearVar.cpp"
using namespace std;

struct var{
    string name,type;
    var(){
        name = type = "";
    }
};

map<string,string> nameToType;
map<string,int> varToVal_int;

inline void parse(string command){
    while(command.length() && command[0]==' '){
        command.assign(command,1,command.length()-1);
    }
    while(command.length() && command[command.length()-1]==' '){
        command.assign(command,0,command.length()-1);
    }
    
    if(command.find("int ")==0){
        string varName = getVarName_int(command);
        int done = declearVar_int(varName);
        if(done==1){
            op("done");
        }
        else if(done==0){
            op(varName+" has been used!");
        }
    }
    if(command.find("float ")==0){
        string varName = getVarName_float(command);
    }
}

int main(){
    string command;
    while(1){
        cout<<". ";
        getline(cin,command);
        if(command=="/*jizz*/") break;
        parse(command);
    }
}
