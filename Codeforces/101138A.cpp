#pragma GCC optimize("no-stack-protector,Ofast")
#include<bits/stdc++.h>
using namespace std;

struct node{
    node *ch[26],*fail;
    int fin;
    node(){
        memset(ch,0,sizeof(ch));
        fail=0; fin=0;
    }
} *root,*tail[200005];

void build(node *&now,string &s,int ptr,int i){
    if(!now)now=new node();
    cout<<"build "<<s<<" [ "<<ptr<<" ] "<<" , add: "<<now<<endl;
    if(ptr==s.size()){
        tail[i]=now;
        ++now->fin;
        return;
    }
    build(now->ch[s[ptr]-'a'],s,ptr+1,i);
}
void AC(){
    queue<node*> q;
    root->fail=root;
    for(int i=0;i<26;++i){
        if(root->ch[i]){
            root->ch[i]->fail=root;
            q.push(root->ch[i]);
        }
        else root->ch[i]=root;
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
bool query(node *now,string &s,int ptr){
    cout<<"query "<<s<<" [ "<<ptr<<" ] , add: "<<now<<endl;
    if(!now)exit(7122);
    if(now->fin)return 1;
    if(ptr>=s.size())return 0;
    return query(now->ch[s[ptr]-'a'],s,ptr+1);
}
void addchar(node *now,char c,int i){
    now->ch[c-'a']=new node();
    --now->fin; ++now->ch[c-'a']->fin;
    now->ch[c-'a']->fail=now->fail->ch[c-'a'];
    for(int i=0;i<26;++i)if(!now->ch[c-'a']->ch[i])now->ch[c-'a']->ch[i]=now->ch[c-'a']->fail->ch[i];
    tail[i]=now->ch[c-'a'];
}

int main(){
    int n,q; cin>>n>>q;
    for(int i=0;i<n;++i){
        string s; cin>>s;
        build(root,s,0,i);
    }
    AC();
    int LAST_YES=0;
    for(int i=0;i<q;++i){
        int type; cin>>type;
        if(type==1){
            string s; cin>>s;
            for(char &c:s)c=(c-'a'+LAST_YES)%26+'a';
            if(query(root,s,0)){
                LAST_YES=i;
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else{
            int num,alp; cin>>num>>alp;
            num=(num+LAST_YES)%n;
            alp=(alp+LAST_YES)%26+'a';
            addchar(tail[num],alp,num);
        }
    }
}
