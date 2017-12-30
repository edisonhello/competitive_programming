#include<bits/stdc++.h>
using namespace std;

unordered_map<string,unordered_set<string>> mp;
int main(){
    int n; cin>>n;
    while(n--){
        string nam; cin>>nam;
        auto &it=mp[nam];
        int cnt; cin>>cnt; while(cnt--){
            string num; cin>>num;
            it.insert(num);
        }
    }
    cout<<mp.size()<<endl;
    for(auto it=mp.begin();it!=mp.end();++it){
        unordered_set<string> suff,numb;
        // cout<<it->first<<endl;
        for(auto str:it->second){
            // cout<<"meow"<<endl;
            if(suff.find(str)!=suff.end())continue;
            // cout<<"insert new str "<<str<<endl;
            numb.insert(str);
            while(str.size()){
                str=str.substr(1,str.size()-1);
                numb.erase(str);
                suff.insert(str);
            }
        }
        cout<<it->first<<" "<<numb.size();
        for(auto &str:numb)cout<<" "<<str;
        cout<<endl;
    }
}
