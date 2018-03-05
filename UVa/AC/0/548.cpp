#include<bits/stdc++.h>
using namespace std;

int mn,nno;

void go(vector<int> &ino,int l1,int r1,vector<int> &poso,int l2,int r2,int tot){
    if(l1>r1)return;
    // cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
    int rt=poso[r2];
    tot+=rt;
    if(l1==r1){
        assert(l2==r2);
        if(tot<mn || (tot==mn && poso[r2]<nno)){
            mn=tot;
            nno=poso[r2];
        }
        return;
    }
    assert(l2!=r2);
    int pos=-1;
    for(int i=l1;i<=r1;++i){
        if(ino[i]==rt){
            pos=i;
            break;
        }
    }
    go(ino,l1,pos-1,poso,l2,l2+pos-l1-1,tot);
    go(ino,pos+1,r1,poso,l2+pos-l1,r2-1,tot);
}

int main(){
    string s,t; while(getline(cin,s)){
        getline(cin,t);
        vector<int> ino,poso;
        stringstream ss(s),tt(t);
        int tmp;
        while(ss>>tmp)ino.push_back(tmp);
        while(tt>>tmp)poso.push_back(tmp);
        mn=999999999;
        go(ino,0,ino.size()-1,poso,0,ino.size()-1,0);
        cout<<nno<<endl;
    }
}
