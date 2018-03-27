
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sq(x) ((x)*(x))

struct flight{
    ll x,y;
    int id;
} a[100005];


inline ll dis(const flight &a,const flight &b){
    return sq(a.y-b.y)+sq(a.x-b.x);
}

int n,idx[100005],mn_id1,mn_id2;
// int to_id[100005];
ll k,sq_d;

bitset<1000> u[1000];

int main(){
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("in.txt","w",stdout);
    // cin>>n>>k;
    int n=(double)rand()/RAND_MAX*5000,k=1; cout<<n<<" "<<k<<endl;
    for(int i=0;i<n;++i){
        cout<<i;
        int x=rand()%201,y=rand()%201;
        while(u[x][y]){
            x=rand()%201;
            y=rand()%201;
        }
        cout<<" "<<x-100<<" "<<y-100<<endl;
        u[x][y]=1;
    }
    // cout<<a[mn_id1].id<<" "<<a[mn_id2].id<<" "<<sq_d<<endl;
}
