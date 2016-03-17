#include<bits/stdc++.h>

using namespace std;
vector<string> name;
vector<int> cnt;

string check(string s){
    bool fd = false;
    int pos;
    for(pos=0;pos<name.size();pos++){
        if(name[pos]==s){
            fd = true;
            break;
        }
    }

    if(!fd){
        name.push_back(s);
        cnt.push_back(1);
        return "";
    }
    if(fd){
        stringstream ss;
        ss << cnt[pos];
        string posstring;
        ss >> posstring;
        s = s+posstring;
        cnt[pos]++;
        return s;
    }
}

int main(){
    int n;cin>>n;

    while(n--){
        string s;cin>>s;
        s = check(s);
        if(s==""){
            printf("OK\n");
        }
        else{
            cout<<s<<endl;
        }
    }
}
