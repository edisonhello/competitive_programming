#include<bits/stdc++.h>
#include"getVarName.cpp"
using namespace std;

struct var{
    string name,type;
    var(){
        name = type = "";
    }
};

map<string,string> nameToType;

inline void parse(string command){
    while(command.length() && command[0]==' '){
        command.assign(command,1,command.length()-1);
    }
    while(command.length() && command[command.length()-1]==' '){
        command.assign(command,0,command.length()-1);
    }
    cout<<command<<endl;
    
    if(command.find("int ")==0){
        string varName = getVarName_int(command);
        cout<<varName<<endl;
    }
}

int main(){
    string command;
    while(1){
        getline(cin,command);
        if(command=="/*jizz*/") break;
        parse(command);
    }
}
