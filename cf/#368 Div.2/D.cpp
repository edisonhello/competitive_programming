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

int n,m,q;
int shelf[1003][1003];
int cnt[1003];
command Q[100005];
bool rec[100005];
shelF *shelfrec[100005];
bool inv[1003];
int book;

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
        if(Q[i].a==4)rec[Q[i].b]=1;
    }

    for(int i=1;i<=q;i++){
        if(Q[i].a==3){
            inv[Q[i].b]=!inv[Q[i].b];
            book += m-cnt[Q[i].b]-cnt[Q[i].b];
            cnt[Q[i].b] = m-cnt[Q[i].b];
        }
        if(Q[i].a==1){
            if(shelf[Q[i].b][Q[i].c]==inv[Q[i].b]){
                shelf[Q[i].b][Q[i].c] = !shelf[Q[i].b][Q[i].c];
                cnt[Q[i].b]++;
                book++;
            }
        }
        if(Q[i].a==2){
            if(shelf[Q[i].b][Q[i].c]!=inv[Q[i].b]){
                shelf[Q[i].b][Q[i].c] = !shelf[Q[i].b][Q[i].c];
                cnt[Q[i].b]--;
                book--;
            }
        }
        if(rec[i]){
            shelfrec[i] = new shelF();
            for(int qq=0;qq<=n+1;qq++){
                for(int ww=0;ww<=m+1;ww++){
                    shelfrec[i]->sit[qq][ww] = shelf[qq][ww];
                }
                shelfrec[i]->inv[qq] = inv[qq];
                shelfrec[i]->cnt[qq] = cnt[qq];
            }
            shelfrec[i]->book = book;
        }
        if(Q[i].a==4){
            if(Q[i].b==0){
                memset(shelf,0,sizeof(shelf));
                memset(inv,0,sizeof(inv));
                memset(cnt,0,sizeof(cnt));
                book = 0;
            }
            else{
                for(int qq=0;qq<=n+1;qq++){
                    for(int ww=0;ww<=m+1;ww++){
                        shelf[qq][ww] = shelfrec[Q[i].b]->sit[qq][ww];
                    }
                    inv[qq] = shelfrec[Q[i].b]->inv[qq];
                    cnt[qq] = shelfrec[Q[i].b]->cnt[qq];
                }
                book = shelfrec[Q[i].b]->book;
            }
        }
        cout<<book<<endl;
    }
}
