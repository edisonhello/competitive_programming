#include<bits/stdc++.h>
using namespace std;

bool isbig(char c){return c>='A' && c<='Z';}
bool issmall(char c){return c>='a' && c<='z';}
bool isdig(char c){return c>='0' && c<='9';}

map<string,int> process(string s){
    // cout<<"process "<<s<<endl;
    map<string,int> rt;
    for(int i=0;i<s.size();){
        // cout<<"index: "<<i<<endl;
        if(s[i]=='('){
            int j=i+1;
            for(int cnt=1;j<s.size();++j){
                if(s[j]=='(')++cnt;
                if(s[j]==')')--cnt;
                if(cnt==0)break;
            }
            ++i,--j;
            map<string,int> sub=process(s.substr(i,j-i+1));
            ++j; ++j;
            int cnt=0;
            for(;j<s.size() && isdig(s[j]);++j){
                cnt=cnt*10+s[j]-'0';
            }
            cnt=max(cnt,1);
            for(auto i:sub)rt[i.first]+=i.second*cnt;
            i=j;
        }
        else if(isbig(s[i])){
            if(i+1<s.size() && issmall(s[i+1])){
                string name=s.substr(i,2);
                int cnt=0,j=i+2;
                for(;j<s.size() && isdig(s[j]);++j){
                    cnt=cnt*10+s[j]-'0';
                }
                cnt=max(cnt,1);
                rt[name]+=cnt;
                i=j;
            }
            else{
                string name=s.substr(i,1);
                int cnt=0,j=i+1;
                for(;j<s.size() && isdig(s[j]);++j){
                    cnt=cnt*10+s[j]-'0';
                }
                cnt=max(cnt,1);
                rt[name]+=cnt;
                i=j;
            }
        }
        else if(isdig(s[i])){
            assert(0);
        }
    }
    return rt;
}

int main(){
    string s; cin>>s;
    auto ans=process(s);
    cout<<s<<endl;
    for(auto i:ans){
        cout<<i.first<<":"<<i.second<<endl;
    }
}
