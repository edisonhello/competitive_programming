#include<bits/stdc++.h>
using namespace std;

int n,m;
string mp[1111];

void tryvtx(){
    set<int> odd,even;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mp[i][j]=='0')continue;
            (i&1?odd:even).insert(mp[i][j]-'0');
        }
    }
    if(odd.size()>2u || even.size()>2u)return;
    for(int i=1;i<=4;++i)if(odd.find(i)!=odd.end() && even.find(i)!=even.end())return;
    for(int i=1;i<=4;++i){
        if(odd.size()==2u)break;
        if(even.find(i)==even.end())odd.insert(i);
    }
    for(int i=1;i<=4;++i){
        if(even.size()==2u)break;
        if(odd.find(i)==odd.end())even.insert(i);
    }
    for(int i=0;i<n;++i){
        set<int> odd,even;
        for(int j=0;j<m;++j){
            if(mp[i][j]=='0')continue;
            (j&1?odd:even).insert(mp[i][j]-'0');
        }
        if(odd.size()>1u || even.size()>1u)return;
        for(int i=1;i<=4;++i)if(odd.find(i)!=odd.end() && even.find(i)!=even.end())return;
    }
    for(int i=0;i<n;++i){
        set<int> _odd,_even;
        for(int j=0;j<m;++j){
            if(mp[i][j]=='0')continue;
            (j&1?_odd:_even).insert(mp[i][j]-'0');
        }
        set<int> &fset=(i&1?odd:even);
        if(_odd.size()){for(int i:fset)if(_odd.find(i)==_odd.end())_even.insert(i);}
        else if(_even.size()){for(int i:fset)if(_even.find(i)==_even.end())_odd.insert(i);}
        else{
            for(int i:fset){
                if(_odd.empty())_odd.insert(i);
                else _even.insert(i);
            }
        }
        for(int j=0;j<m;++j)if(mp[i][j]=='0')mp[i][j]=(*((j&1?_odd:_even).begin()))+'0';
    }
    for(int i=0;i<n;++i)cout<<mp[i]<<endl;
    exit(0);
}
void tryhrz(){
    string mp2[1111];
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)mp2[j]+=mp[i][j];
    swap(n,m);
#define mp mp2
    set<int> odd,even;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mp[i][j]=='0')continue;
            (i&1?odd:even).insert(mp[i][j]-'0');
        }
    }
    if(odd.size()>2u || even.size()>2u)return;
    for(int i=1;i<=4;++i)if(odd.find(i)!=odd.end() && even.find(i)!=even.end())return;
    for(int i=1;i<=4;++i){
        if(odd.size()==2u)break;
        if(even.find(i)==even.end())odd.insert(i);
    }
    for(int i=1;i<=4;++i){
        if(even.size()==2u)break;
        if(odd.find(i)==odd.end())even.insert(i);
    }
    for(int i=0;i<n;++i){
        set<int> odd,even;
        for(int j=0;j<m;++j){
            if(mp[i][j]=='0')continue;
            (j&1?odd:even).insert(mp[i][j]-'0');
        }
        if(odd.size()>1u || even.size()>1u)return;
        for(int i=1;i<=4;++i)if(odd.find(i)!=odd.end() && even.find(i)!=even.end())return;
    }
    for(int i=0;i<n;++i){
        set<int> _odd,_even;
        for(int j=0;j<m;++j){
            if(mp[i][j]=='0')continue;
            (j&1?_odd:_even).insert(mp[i][j]-'0');
        }
        set<int> &fset=(i&1?odd:even);
        if(_odd.size()){for(int i:fset)if(_odd.find(i)==_odd.end())_even.insert(i);}
        else if(_even.size()){for(int i:fset)if(_even.find(i)==_even.end())_odd.insert(i);}
        else{
            for(int i:fset){
                if(_odd.empty())_odd.insert(i);
                else _even.insert(i);
            }
        }
        for(int j=0;j<m;++j)if(mp[i][j]=='0')mp[i][j]=(*((j&1?_odd:_even).begin()))+'0';
    }
#undef mp
    string mp3[1111];
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)mp3[j]+=mp2[i][j];
    swap(n,m);
    for(int i=0;i<n;++i)cout<<mp3[i]<<endl;
    exit(0);
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>mp[i];
    tryvtx();
    tryhrz();
    cout<<0<<endl;
}
