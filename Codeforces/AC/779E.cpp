#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> op;
unordered_map<string,int> mp;
bitset<5005> st1,st0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m; 
    op.resize(n);
    cin.ignore();
    for(int i=0;i<n;++i){
        string s; getline(cin,s);
        stringstream ss(s);
        while(ss>>s)op[i].push_back(s);
        mp[op[i][0]]=i;
    }
    mp["?"]=n;
    string mn,mx;
    for(int i=0,id0,id1,id2;i<m;++i){
        st1.reset(); st0.reset();
        st1[n]=1;
        for(auto &v:op){
            if(v.size()==3u){
                id0=mp[v[0]];
                st0[id0]=st1[id0]=(v[2][i]=='1');
            }
            else{
                id0=mp[v[0]];
                id1=mp[v[2]];
                id2=mp[v[4]];
                if(v[3][0]=='X'){
                    st0[id0]=st0[id1]^st0[id2];
                    st1[id0]=st1[id1]^st1[id2];
                }
                else if(v[3][0]=='O'){
                    st0[id0]=st0[id1]|st0[id2];
                    st1[id0]=st1[id1]|st1[id2];
                }
                else{
                    st0[id0]=st0[id1]&st0[id2];
                    st1[id0]=st1[id1]&st1[id2];
                }
            }
        }
        int c1=st1.count()-1,c0=st0.count();
        if(c1==c0){
            mn+="0";
            mx+="0";
        }
        else if(c1>c0){
            mx+="1";
            mn+="0";
        }
        else{
            mx+="0";
            mn+="1";
        }
    }
    cout<<mn<<endl<<mx<<endl;
}
