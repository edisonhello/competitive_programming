#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second

int n,m;
int st[100005];
vector<int> mp[100005];
int D;
int ans;
bool gone[100005];

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
}

void dfs(int cur,int dis){
    // cout<<"cur"<<cur<<" dis="<<dis<<endl;
    ans+=st[cur];
    st[cur]=0;
    if(dis==D)return;
    gone[cur]=1;
    for(int i=0;i<mp[cur].size();i++){
        if(!gone[mp[cur][i]]){
            dfs(mp[cur][i],dis+1);
        }
    }
    gone[cur]=0;
}

int main(){
	n=rit();
	m=rit();
	for(int i=0;i<n;i++)st[i]=rit();
	for(int i=0;i<m;i++){
		int a=rit();
		int b=rit();
        mp[a].PB(b);
        mp[b].PB(a);
	}
    D=rit();
    ans+=st[0];
    st[0]=0;
    dfs(0,0);
    cout<<ans<<endl;
}
