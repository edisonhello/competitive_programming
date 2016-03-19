#include<bits/stdc++.h>
using namespace std;

struct d{
    int pos,val;
};

struct e{
    int pos,val;
};

bool operator < (const d &a,const d &b){
return a.val<b.val;
}

bool operator < (const e &a,const e &b){
return a.pos<b.pos;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    vector<d> a;
    for(int i=0;i<n;i++){
        int j;cin>>j;
        d t;t.val=j;t.pos=i;
        a.push_back(t);
    }
    sort(a.begin(),a.end());

    int now=0;
    vector<e> b;
    for(int i=0;i<a.size();i++){
        if(now>=a[i].val){
            a[i].val=++now;
            e t;t.val=a[i].val;t.pos=a[i].pos;
            b.push_back(t);
        }
        else{
            now=a[i].val;
            e t;t.val=a[i].val;t.pos=a[i].pos;
            b.push_back(t);
        }
    }sort(b.begin(),b.end());

    for(int i=0;i<b.size();i++){
        cout<<b[i].val;
        if(i!=b.size()-1)cout<<" ";
    }cout<<endl;
}
