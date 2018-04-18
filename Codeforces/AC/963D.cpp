#include<bits/stdc++.h>
using namespace std;

int le[100005];
int sz[100005];
int ans[100005];
deque<int> pos[100005];

struct node{
    node *ch[26],*fail;
    vector<int> ids;
    node():fail(0){memset(ch,0,sizeof(ch));}
} *root;

void add(node *&now,string &s,int ptr,int qid){
    if(!now)now=new node();
    if(ptr>=s.size()){
        now->ids.push_back(qid);
        return;
    }
    add(now->ch[s[ptr]-'a'],s,ptr+1,qid);
}

void go(){
    queue<node*> q;
    for(int i=0;i<26;++i){
        if(root->ch[i]){
            root->ch[i]->fail=root;
            q.push(root->ch[i]);
        }
        else root->ch[i]=root;
    }
    while(q.size()){
        node *now=q.front(); q.pop();
        for(int i=0;i<26;++i){
            if(now->ch[i]){
                now->ch[i]->fail=now->fail->ch[i];
                for(int id:now->fail->ch[i]->ids)now->ch[i]->ids.push_back(id);
                q.push(now->ch[i]);
            }
            else now->ch[i]=now->fail->ch[i];
        }
    }
}

void match(node *now,string &s,int ptr){
    for(int id:now->ids){
        pos[id].push_back(ptr);
        if(pos[id].size()>=sz[id]){
            ans[id]=min(ans[id],pos[id].back()-pos[id].front()+le[id]);
            pos[id].pop_front();
        }
        // match(root,s,ptr+1);
    }
    if(ptr>=s.size())return;
    match(now->ch[s[ptr]-'a'],s,ptr+1);
}

int main(){
    string s; cin>>s;
    int q; cin>>q;
    for(int i=1;i<=q;++i){
        cin>>sz[i];
        string s; cin>>s;
        add(root,s,0,i);
        le[i]=s.size();
    }
    go();
    memset(ans,0x3f,sizeof(ans));
    match(root,s,0);
    for(int i=1;i<=q;++i){
        // cout<<"pos of "<<i<<" is "; for(int j:pos[i])cout<<j<<" "; cout<<endl;
        if(ans[i]==0x3f3f3f3f)ans[i]=-1;
        cout<<ans[i]<<'\n';
    }
}
