#include<bits/stdc++.h>
using namespace std;

int n,cnt;
vector<char> op;

/* struct node{
    node *ch[26];
    int mx;
    bool end;
    node():mx(0),end(0){ memset(ch,0,sizeof(ch)); }
} *root,pool[25000*21]; */
int ch[25000*18][26],mx[25000*18];
bitset<25000*18> ed;
int _ptr=1;
string s;

void ins(int &now,int ptr){
    if(!now)now=++_ptr;
    mx[now]=max(mx[now],(int)s.size());
    if(ptr>=s.size()){
        ed[now]=1;
        return;
    }
    ins(ch[now][s[ptr]-'a'],ptr+1);
}

void go(int now){
    if(!now)return;
    if(ed[now]){
        op.push_back('P');
        ++cnt;
    }
    int tmx=0;
    for(int i=0;i<26;++i)if(ch[now][i])tmx=max(tmx,mx[ch[now][i]]);
    int stay=-1;
    for(int i=0;i<26;++i)if(ch[now][i] && mx[ch[now][i]]==tmx)stay=i;
    for(int i=0;i<26;++i){
        if(ch[now][i]){
            if(i==stay)continue;
            op.push_back(i+'a');
            go(ch[now][i]);
            if(cnt!=n)op.push_back('-');
        }
    }
    if(stay!=-1){
        op.push_back(stay+'a');
        go(ch[now][stay]);
        if(cnt!=n)op.push_back('-');
    }
}

int main(){
    int root=1;
    cin>>n; 
    for(int i=0;i<n;++i){
        cin>>s;
        ins(root,0);
    }
    go(root);
    cout<<op.size()<<endl;
    for(char c:op)cout<<c<<'\n';
}
// in virtual AC
