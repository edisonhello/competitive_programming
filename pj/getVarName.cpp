#include<bits/stdc++.h>
using namespace std;

string getVarName_int(string command){
    command.assign(command,4,command.length()-4);
    int i=0;
    while(command.length() && command[0]==' '){
        command.assign(command,1,command.length()-1);
    }
    while((i<(int)command.length())&&((command[i]>='0'&&command[i]<='9')||(command[i]>='a'&&command[i]<='z')||(command[i]>='A'&&command[i]<='Z')||command[i]==' '||command[i]=='_')){
        i++;
    }

    if(i==(int)command.length()){
        return command;
    }
    else{
        string tmp = command.assign(command,0,i);
        while(tmp.length() && tmp[tmp.length()-1]==' '){
            tmp.assign(tmp,0,tmp.length()-1);
        }
        return tmp;
    }

    return "";
}

string getVarName_float(string command){
    command.assign(command,6,command.length()-6);
    int i=0;
    while(command.length() && command[0]==' '){
        command.assign(command,1,command.length()-1);
    }
    while((i<(int)command.length())&&((command[i]>='0'&&command[i]<='9')||(command[i]>='a'&&command[i]<='z')||(command[i]>='A'&&command[i]<='Z')||command[i]==' '||command[i]=='_')){
        i++;
    }

    if(i==(int)command.length()){
        return command;
    }
    else{
        string tmp = command.assign(command,0,i);
        while(tmp.length() && tmp[tmp.length()-1]==' '){
            tmp.assign(tmp,0,tmp.length()-1);
        }
        return tmp;
    }

    return "";
}
