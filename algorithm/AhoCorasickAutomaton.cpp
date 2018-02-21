// modify from 856B
#include<bits/stdc++.h>
using namespace std;

struct node{
    node *ch[26],*fail;
    node(){
        fail=0;
        memset(ch,0,sizeof(ch));
    }
} *root;

void build(node *&now,int ptr,string &s){
    if(!now)now=new node();
    if(ptr>=s.size())return;
    build(now->ch[s[ptr]-'a'],ptr+1,s);
}

void buildAC(){
    queue<node*> q;
    root->fail=root;
    for(int i=0;i<26;++i){
        if(!root->ch[i])root->ch[i]=root;
        else root->ch[i]->fail=root,q.push(root->ch[i]);
    }
    while(q.size()){
        for(int i=0;i<26;++i){
            if(q.front()->ch[i]){
                q.front()->ch[i]->fail=q.front()->fail->ch[i];
                q.push(q.front()->ch[i]);
            }
            else q.front()->ch[i]=q.front()->fail->ch[i];
        }
        q.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ts; cin>>ts; while(ts--){
        root=new node();
        int n; cin>>n;
        while(n--){
            string s; cin>>s;
            build(root,0,s);
        }
        buildAC();
    }
}
