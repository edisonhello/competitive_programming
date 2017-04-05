#include<bits/stdc++.h>
#include"op.cpp"
using namespace std;

extern map<string,string> nameToType;
extern map<string,int> varToVal_int;

bool getAppend_name(string varName){
    auto finded = nameToType.find(varName);
    if(finded == nameToType.end()){
        return 0;
    }
    else{
        return 1;
    }
}
bool getAppend_int(string varName){
    auto finded = varToVal_int.find(varName);
    if(finded == varToVal_int.end()){
        return 0;
    }
    else{
        return 1;
    }
}

int declearVar_int(string varName){
    if(!getAppend_name(varName)){
        nameToType[varName] = "int";
        if(!getAppend_int(varName)){
            varToVal_int[varName] = 0;
        }
        else{
            op("Error: varName \""+varName+"\" has already in int list.\n");
            return -1;
        }
        return 1;
    }
    else{
        return 0;
    }
}
