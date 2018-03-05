#include<bits/stdc++.h>
using namespace std;


void go(deque<int> &dq,int &pos,vector<int> &v,int &ptr){
    if(v[ptr]==-1){
        ++ptr;
        return;
    }
    if(pos==-1)dq.push_front(v[ptr]),++pos;
    else if(pos==dq.size())dq.push_back(v[ptr]);
    else dq[pos]+=v[ptr];
    ++ptr;
    --pos;
    go(dq,pos,v,ptr);
    pos+=2;
    go(dq,pos,v,ptr);
    --pos;
}

void solve(vector<int> &v){
    deque<int> dq;
    int pos=-1,ptr=0;
    go(dq,pos,v,ptr);
    for(int i=0;i<dq.size();++i){
        cout<<dq[i];
        if(i!=dq.size()-1)cout<<" ";
        else cout<<endl;
    }
}

int main(){
    vector<int> v;
    int ks=0,t,empty=1; while(cin>>t){
        v.push_back(t);
        if(t==-1){
            --empty;
            if(!empty){
                if(v.size()==1u)return 0;
                cout<<"Case "<<(++ks)<<":"<<endl;
                solve(v);
                empty=1;
                v.clear();
                cout<<endl;
            }
        }
        else ++empty;
    }
}
