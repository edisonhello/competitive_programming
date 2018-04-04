#include<bits/stdc++.h>
using namespace std;

int x[100005];
int vpos[1000006];
int val[1000006];

vector<int> xs[1000006];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(vpos,-1,sizeof(vpos));
    vpos[0]=0;

    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>x[i];
    int a,b; cin>>a>>b;
    /* int n=100000;
    for(int i=0;i<n;++i)x[i]=rand()+3;
    int a=100000000,b=99000000; */

    sort(x,x+n);
    n=unique(x,x+n)-x;
    reverse(x,x+n);
    for(int i=0,j;i<n;++i){
        j=((b-1)/x[i]+1)*x[i]-b;
        if(j<=1000000)xs[j].push_back(x[i]);
    }

    int nowv=0;
    for(int i=b;i<=a;++i){
        // if(query(i-b)>10000000)add(i-b,query(i-1-b)+1);
        // cout<<i-b<<" "<<nowv<<" "<<vpos[nowv]<<endl;
        while(i-b>vpos[nowv] && vpos[nowv]!=-1){
            ++nowv;
            // cout<<"nowv: "<<nowv<<endl;
        }
        if(vpos[nowv]==-1 && i!=b){
            // cout<<"now "<<i<<" , nowv "<<nowv<<" jizzed"<<endl;
            vpos[val[i-1-b]+1]=i-b;
            nowv=val[i-1-b]+1;
        }
        int to;
        for(int x:xs[i-b]){
            // cout<<"at "<<i<<" use "<<x<<endl;
            to=(i/x+1)*x;
            vpos[nowv+1]=max(vpos[nowv+1],to-1-b);
            // cout<<"vpos["<<nowv+1<<"]="<<vpos[nowv+1]<<endl;
            if(to<=vpos[nowv+1]){
                to=vpos[nowv+1]/x*x;
            }

            if(to-b<=1000000)xs[to-b].push_back(x);
        }
        xs[i-b].clear();
        val[i-b]=nowv;
        // cout<<i<<" val: "<<nowv<<endl;
    }
    cout<<nowv<<endl;
}
