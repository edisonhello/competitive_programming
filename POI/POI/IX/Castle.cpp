/* complexity inspiration(?) by waynetu */

#pragma GCC optimize("Ofast")
#include<cstdio>
#include<bitset>
#include<stack>
#include<vector>
using namespace std;

short cf[102][1003];
short c[102],b,n,t;
bitset<102> v[1003];
vector<short> G[102];

void dfs(short now,short cost){
    // if(cost>b)return;
    // if(v[now][cost])return;
    v[now][cost]=1;
    for(short i:G[now]){
        if(cf[t][b])return;
        cf[i][cost+c[i]]=now;
        if(cost+c[i]>b)continue;
        if(v[i][cost+c[i]])continue;
        dfs(i,cost+c[i]);
    }
}
int main(){
    short m,s; 
    scanf("%hd%hd%hd%hd%hd",&n,&m,&s,&t,&b);
    for(short i=1;i<=n;++i)scanf("%hd",&c[i]);
    short u,v;
    do{
        scanf("%hd%hd",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }while(--m);
    dfs(s,c[s]);
    stack<short> st;
    st.push(t);
    while(b>c[s]){
        short co=c[t];
        t=cf[t][b];
        b-=co;
        st.push(t);
    }
    while(st.size()){
        printf("%hd ",st.top());
        st.pop();
    }
    puts("");
}
