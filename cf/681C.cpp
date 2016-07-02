#include<bits/stdc++.h>
using namespace std;

vector<string> o;

struct node{
    int val,pri,size,weight;
    node *l,*r;

    node(int n){
        val = n;
        pri = rand();
        size = 1;
        weight = 1;
        l = r = NULL;
    }
} *root;

void turnR(node *now){
    node *tmp = now->l;
    now->l = tmp->r;
    tmp->r = now;
    now = tmp;

    tmp->size = (tmp->l?tmp->l->size:0)+(tmp->r?tmp->r->size:0)+tmp->weight;
    now->size = (now->l?now->l->size:0)+(now->r?now->r->size:0)+now->weight;
}
void turnL(node *now){
    node *tmp = now->r;
    now->r = tmp->l;
    tmp->l = now;
    now = tmp;
}

void insert(node *now,int n){
    // cout<<root->val<<"inins"<<endl;
    if(!now){
        // cout<<root->val<<"!now"<<endl;
        now = new node(n);
        // cout<<"now == root->l : "<<(now==root->l)<<endl;
        // cout<<root->val<<"newnode"<<endl;
        return;
    }
    if(n==now->val){
        now->weight++;
        now->size++;
    }
    if(n<now->val){
        // cout<<root->val<<"shdths"<<endl;
        // cout<<(now==root)<<endl;
        insert(now->l,n);
        now->size++;
        // cout<<root->val<<"sz++"<<endl;
        cout<<"!"<<endl;
        cout<<now->l->pri<<endl;
        cout<<"@"<<endl;
        cout<<now->pri<<endl;
        cout<<"#"<<endl;
        if(now->l->pri < now->pri){
            cout<<root->val<<"itturn"<<endl;
            turnR(now);
        }
        cout<<root->val<<"trned"<<endl;
        return;
    }
    if(now->val<n){
        insert(now->r,n);
        now->size++;
        if(now->r->pri < now->pri){
            turnL(now);
        }
        return;
    }
    return;
}

void removeMin(node *now){
    if(now->l){
        removeMin(now->l);
    }
    else{
        delete now;
    }
}

void delete_(node *now){
    if(now->l) delete_(now->l);
    if(now->r) delete_(now->r);
    delete now;
}
void getMin(node *now,int m,int rank){
    cout<<now->val<<endl;
    if(now->val==m){
        cout<<"here"<<endl;
        if(now->l){
            int sz = now->l->size;
            for(int i=0;i<sz+rank;i++){
                o.push_back("removeMin");
            }
            delete_(now->l);
        }
        return;
    }
    if(m<now->val){
        cout<<"there"<<endl;
        if(now->l){
            getMin(now->l,m,rank);
        }
        else{
            for(int i=0;i<rank;i++){
                o.push_back("removeMin");
            }
            insert(now,m);
            // insert(root,m);
            stringstream s;
            s<<m;
            string sm;
            s>>sm;
            o.push_back("insert "+sm);
        }
        return;
    }
    if(now->val<m){
        cout<<"sc\n";
        if(now->r){
            getMin(now->r,m,rank+(now->l?now->l->size:0)+now->weight);
        }
        else{
            for(int i=0;i<rank+now->size;i++){
                o.push_back("removeMin");
            }
            insert(now,m);
            // insert(root,m);
            stringstream s;
            s<<m;
            string sm;
            s>>sm;
            o.push_back("insert "+sm);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    srand(time(NULL));

    root = new node(1e9+5);

    int n;cin>>n;
    for(int i=0;i<n;i++){
        string c;cin>>c;

        if(c[0]=='i'){
            int m;cin>>m;
            // cout<<root->val<<"b4ins"<<endl;
            insert(root,m);
            cout<<root->val<<"afins"<<endl;
            stringstream s;
            s<<m;
            string sm;
            s>>sm;
            o.push_back("insert "+sm);
        }
        if(c[0]=='r'){
            removeMin(root);
            o.push_back("removeMin");
        }
        if(c[0]=='g'){
            int m;cin>>m;
            getMin(root,m,0);
            stringstream s;
            s<<m;
            string sm;
            s>>sm;
            o.push_back("getMin "+sm);
        }
    }

    cout<<o.size()<<endl;
    for(int i=0;i<(int)o.size();i++){
        cout<<o[i]<<'\n';
    }
}
