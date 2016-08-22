#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second

struct command{
    int a,b,c;
    command(){
        a = b = c = 0;
    }
};

struct shelF{
    int sit[1003][1003];
    int cnt[1003];
    int book;
    bool inv[1003];
    shelF(){
        memset(this->sit,0,sizeof(this->sit));
        memset(this->inv,0,sizeof(this->inv));
        memset(this->cnt,0,sizeof(this->cnt));
        book = 0;
    }
};

inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
};

struct node{
    vector<int> connect;
};


int n,m,q;
command Q[100005];
int shelf[1003][1003];
int ans[100005];
int cnt[1003];
int book;
bool inv[1003];
node nodes[100005];

void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<shelf[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dfs(int index){
    int d = 0;
    if(Q[index].a==1){
        if(shelf[Q[index].b][Q[index].c]==inv[Q[index].b]){
            shelf[Q[index].b][Q[index].c] = !shelf[Q[index].b][Q[index].c];
            cnt[Q[index].b]++;
            book++;
            d++;
        }
    }
    else if(Q[index].a==2){
        if(shelf[Q[index].b][Q[index].c]!=inv[Q[index].b]){
            shelf[Q[index].b][Q[index].c] = !shelf[Q[index].b][Q[index].c];
            cnt[Q[index].b]--;
            book--;
            d++;
        }
    }
    else if(Q[index].a==3){
        inv[Q[index].b]=!inv[Q[index].b];
        book += m-cnt[Q[index].b]-cnt[Q[index].b];
        cnt[Q[index].b] = m-cnt[Q[index].b];
        d++;
    }

    ans[index] = book;
    // print();

    for(int i=0;i<(int)nodes[index].connect.size();i++){
        // cout<<"index = "<<index<<", book = "<<book<<", go "<<nodes[index].connect[i]<<endl;
        dfs(nodes[index].connect[i]);
    }

    if(d){
        if(Q[index].a==2){
            if(shelf[Q[index].b][Q[index].c]==inv[Q[index].b]){
                shelf[Q[index].b][Q[index].c] = !shelf[Q[index].b][Q[index].c];
                cnt[Q[index].b]++;
                book++;
            }
        }
        else if(Q[index].a==1){
            if(shelf[Q[index].b][Q[index].c]!=inv[Q[index].b]){
                shelf[Q[index].b][Q[index].c] = !shelf[Q[index].b][Q[index].c];
                cnt[Q[index].b]--;
                book--;
            }
        }
        else if(Q[index].a==3){
            inv[Q[index].b]=!inv[Q[index].b];
            book += m-cnt[Q[index].b]-cnt[Q[index].b];
            cnt[Q[index].b] = m-cnt[Q[index].b];
        }
    }
}

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    n=rit();
    m=rit();
    q=rit();

    for(int i=1;i<=q;i++){
        Q[i].a=rit();
        Q[i].b=rit();
        if(Q[i].a<=2)Q[i].c=rit();
        if(Q[i].a==4){
            nodes[Q[i].b].connect.PB(i);
        }
        else{
            nodes[i-1].connect.PB(i);
        }
    }

    dfs(0);

    for(int i=1;i<=q;i++){
        cout<<ans[i]<<endl;
    }
}
