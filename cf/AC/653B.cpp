#include<bits/stdc++.h>

using namespace std;

int length,q    ;
vector<string> c[6];
vector<string> ma;

void go(int len,string now){
    if(len==length){
        ma.push_back(now);
        return ;
    }

    int res=0;

    int w = now[0]-97;
    for(int j=0;j<c[w].size();j++){
        string t=now;
        t.replace(0,0,c[w][j]);
        go(len+1,t);
    }

    return;

}

int main(){
    cin>>length>>q;
    for(int i=0;i<q;i++){
        string a;char b;cin>>a>>b;
        int where = b-97;
        c[where].push_back(a);
    }

    go(1 , "a");
    if(ma.size()){
        sort(ma.begin(),ma.end());
        int ans = ma.size();
        for(int i=0;i<ma.size()-1;i++){
            if(ma[i]==ma[i+1]){
                ans--;
            }
        }
        cout<<ans<<endl;
    }
    else{
        cout<<0<<endl;
    }

}
