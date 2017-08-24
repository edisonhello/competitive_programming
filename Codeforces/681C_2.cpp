#include<bits/stdc++.h>
using namespace std;
vector<string> o;
struct node{
    node *l,*r;
    int val,size,weight;
    bool init;
    
    node(){
        val = 0;
        size = 1;
        weight = 1;
        l = r = NULL;
        init = false;
    }
} *root;

void insert_(node *now,int m){
    if(now==NULL){
        now = new node();
        now->val = m;
        now->init = true;
        now->l = new node();
        now->r = new node();
        return;
    }
    if(m==now->val){
        now->weight++;
        now->size++;
        return;
    }
    if(m<now->val){
        insert_(now->l,m);
        now->size++;
        return;
    }
    if(now->val<m){
        insert_(now->r,m);
        now->size++;
        return;
    }
}

bool removeMin(node *now){
    if(now->l->init){
        if(removeMin(now->l)){
            now->l = new node();
        }
        now->size--;
        return 0;
    }
    else{
        now->weight--;
        now->size--;
        if(now->weight<1){
            delete now;
            return 1;
        }
    }
}

void getMin(node *now,int m,int rank){
    if(now->val==m){
        rank += now->l->init ? now->l->size : 0;
        for(int i=0;i<rank;i++){
            o.push_back("removeMin");
            removeMin(root);
        }
        return;
    }
    if(m<now->val){
        if(now->l->init){
            getMin(now->l,m,rank);
            return;
        }
        else{
            for(int i=0;i<rank;i++){
                o.push_back("removeMin");
                removeMin(root);
            }
            insert_(root,m);
            return;
        }
    }
    if(now->val<m){
        if(now->r->init){
            getMin(now->r,m,rank+now->l->size+now->weight);
            return;
        }
        else{
            rank+=now->l->size+now->weight;
            for(int i=0;i<rank;i++){
                o.push_back("removeMin");
                removeMin(root);
            }
            insert_(now,m);
            return;
        }
    }
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string com;cin>>com;

        if(com[0]=='i'){
            int m;cin>>m;
            insert_(root,m);
            stringstream s;
            string sm;
            s<<m;
            s>>sm;
            o.push_back("insert "+sm);
        }
        if(com[0]=='r'){
            removeMin(root);
            o.push_back("removeMin");
        }
        if(com[0]=='g'){
            int m;cin>>m;
            getMin(root,m,0);
            stringstream s;
            string sm;
            s<<m;
            s>>sm;
            o.push_back("getMin "+sm);
        }
    }

    cout<<o.size()<<'\n';
    for(int i=0;i<(int)o.size();i++){
        cout<<o[i]<<'\n';
    }
}
