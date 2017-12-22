#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; while(cin>>s){
        int ans=0;
        vector<int> pos;
        for(int i=0;i<s.size();++i)if(s[i]=='y')pos.push_back(i);
        for(int i=0,p=0;i<pos.size();++i,p+=3){
            ans+=abs(p-pos[i]);
        }
        cout<<ans<<endl;
    }
}
