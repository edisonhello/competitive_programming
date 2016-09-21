#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue

struct node{
    int v;
    node *next;
    node():v(0),next(NULL){};
    node(int v):v(v),next(NULL){};
    node(int v,node* n):v(v),next(n){};
} *first, *last;

vector<string> ans;

void record(){
    node *now=first;
    string tmp;
    while(now!=NULL){
        if(now!=first)tmp+=' ';
        stringstream ss;
        ss<<now->v;
        string s;
        ss>>s;
        tmp+=s;
        now=now->next;
    }
    ans.PB(tmp);
}

void ins(int n,int fin){
    if(n>fin){
        record();
        return;
    }
    node *now=first;
    while(now->next != NULL){
        if(n%(now->v+now->next->v)==0){
            node *tmp = new node(n,now->next);
            now->next = tmp;
            ins(n+1,fin);
            now->next = tmp->next;
            delete tmp;
        }
        now = now->next;
    }
}

void sol(int n){
    ins(4,n);
    sort(ans.begin(),ans.end());
    // cout<<ans.size()<<endl;
    // cout<<ans[ans.size()-1]<<endl;
    cout<<"cout<<\""<<ans.size()<<"\\n"<<ans[ans.size()-1]<<"\\n\";"<<endl;
}

void in(){
    int n;cin>>n;
    if(n==1){
        cout<<"1\n0 1\n";
        return;
    }
    else if(n==2){
        cout<<"1\n0 2 1\n";
        return;
    }
    else if(n==3){
        cout<<"1\n0 2 3 1\n";
        return;
    }
    sol(n);
}

void init(){
    first = new node(0);
    last = new node(1);
    node *t = new node(2);
    node *tt = new node(3);
    first->next = t;
    t->next = tt;
    tt->next = last;
}

int main(){
    init();
    in();
}
