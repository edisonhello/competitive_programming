#include<bits/stdc++.h>
using namespace std;

struct node{
    string s;
    node *l, *r;
    node(){
        s="";
        l = r = NULL;
    }
} *root;

bool FUCK = true;
bool ist(string in,node *now){
    if(in==now->s && now==root &&FUCK){
        FUCK = false;
        return 1;
    }
    if(in==now->s){
        return 0;
    }
    if(in<now->s){
        if(now->l!=NULL){
            return ist(in,now->l);
        }
        else{
            now->l = new node();
            now->l->s = in;
            return 1;
        }
    }
    if(in>now->s){
        if(now->r!=NULL){
            return ist(in,now->r);
        }
        else{
            now->r = new node();
            now->r->s = in;
            return 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    stack<string> name;

        string fst;cin>>fst;
        name.push(fst);

        root = new node();
        root->s = fst;

    for(int i=1;i<n;i++){
        string tmp;cin>>tmp;
        name.push(tmp);
        /*if(ist(tmp,root)){
            name.push(tmp);
        }*/
    }
    queue<string> out;
    //out.push(fst);
    for(;name.size();){
        if(ist(name.top(),root)){
            out.push(name.top());
        }

        name.pop();
    }

    for(;out.size();){
        cout<<out.front()<<endl;
        out.pop();
    }
    //cout<<fst<<endl;


}

