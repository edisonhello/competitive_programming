#include<bits/stdc++.h>
using namespace std;
#define stack deque


struct folder{
    map<string,folder*> mp;
    int size;
    bool exp;
    folder():size(0),exp(0){}
} *root;

void upFolder(folder *&now,string &path,int fsz,int ptr){
    if(!now)now=new folder();
    string nw;
    while(ptr<path.size()){
        if(path[ptr]=='/')break;
        nw+=path[ptr];
        ++ptr;
    }
    now->size+=fsz;
    if(ptr>=path.size())return;
    else upFolder(now->mp[nw],path,fsz,ptr+1);
}

void viewFolder(folder *now,int lim,stack<string> &st){
    if(now->mp.empty()){
        cout<<"  ";
        stack<string> tmp=st;
        while(tmp.size()){
            cout<<"/"<<tmp.front();
            tmp.pop_front();
        }
        cout<<"/ "<<now->size;
        cout<<endl;
        return;
    }
    for(auto i:now->mp){
        if(i.second->size>=lim){now->exp=1; break;}
    }
    if(now->exp){
        cout<<"- ";
        stack<string> tmp=st;
        while(tmp.size()){
            cout<<"/"<<tmp.front();
            tmp.pop_front();
        }
        cout<<"/ "<<now->size;
        cout<<endl;
        for(auto i:now->mp){
            st.push_back(i.first);
            viewFolder(i.second,lim,st);
            st.pop_back();
        }
    }
    else{
        cout<<"+ ";
        stack<string> tmp=st;
        while(tmp.size()){
            cout<<"/"<<tmp.front();
            tmp.pop_front();
        }
        cout<<"/ "<<now->size;
        cout<<endl;
    }
}

int main(){
    int files; cin>>files; while(files--){
        string path; int size; cin>>path>>size;
        upFolder(root,path,size,1);
    }
    stack<string> st;
    int lim; cin>>lim;
    // checkLim(root,lim);
    viewFolder(root,lim,st);
}
