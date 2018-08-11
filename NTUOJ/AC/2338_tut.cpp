#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define prev dgji

pii ch[1<<21];
int tree[1<<21];

int main(){
    int root=2;
    ch[2]=pii(1,3);
    ch[1]=pii(6,7);
    ch[3]=pii(4,5);

    ch[4]=pii(9,15);
    ch[6]=pii(11,13);
    ch[5]=pii(8,14);
    ch[7]=pii(10,12);

    for(int i=8;i<(1<<20);++i){
        if(i&1){
            int t=(i>>1)&1;
            if(t==0)ch[i]=make_pair(i*2-2,i*2+4);
            else ch[i]=make_pair(i*2-2,i*2-4);
        }
        else{
            if((i&-i)==i)ch[i]=make_pair(i*2+1,i*4-1);
            else ch[i]=make_pair(i*2-1,i*2+1);
        }
    }

    tree[1]=2;
    tree[2]=1;
    tree[3]=3;
    for(int i=1;i<(1<<20);++i){
        tree[i*2]=ch[tree[i]].first;
        tree[i*2+1]=ch[tree[i]].second;
    }

    // cout<<"builded ok"<<endl;

    int t; cin>>t; while(t--){
        int n; cin>>n; 
        if(n==1){ cout<<"1"<<endl; }
        else for(int i=1;i<(1<<n);++i)cout<<tree[i]<<" "; cout<<endl;
    }
}
