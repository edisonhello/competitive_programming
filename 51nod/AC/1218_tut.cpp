#include<bits/stdc++.h>
using namespace std;
#define lb(x) ((x)&-(x))

int bit[50005];
void add(int x,int v){
    for(;x<50005;x+=lb(x))bit[x]=max(bit[x],v);
}
int query(int x,int v=0){
    for(;x;x-=lb(x))v=max(v,bit[x]);
    return v;
}

vector<int> vaild[50005],unq,dba;
int a[50005],pos[50005],ipos[50005];
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    vector<int> z;
    for(int i=1;i<=n;++i)z.push_back(a[i]);
    sort(z.begin(),z.end());
    for(int i=1;i<=n;++i)a[i]=lower_bound(z.begin(),z.end(),a[i])-z.begin()+1;
    int LIS=0;
    for(int i=1;i<=n;++i){
        int q=query(a[i]-1);
        pos[i]=++q;
        add(a[i],q);
        LIS=max(LIS,q);
    }
    memset(bit,0,sizeof(bit));
    for(int i=n;i>=1;--i){
        a[i]=50002-a[i];
        int q=query(a[i]-1);
        ipos[i]=++q;
        add(a[i],q);
        LIS=max(LIS,q);
    }
    for(int i=1;i<=n;++i){
        if(pos[i]+ipos[i]!=LIS+1)continue;
        vaild[pos[i]].push_back(i);
    }
    for(int i=1;i<50005;++i){
        if(vaild[i].size()==1){
            unq.push_back(vaild[i][0]);
        }
        else for(int ii:vaild[i]){
            dba.push_back(ii);
        }
    }
    sort(unq.begin(),unq.end());
    sort(dba.begin(),dba.end());
    cout<<"A:"; for(int i:dba)cout<<i<<" "; cout<<endl;
    cout<<"B:"; for(int i:unq)cout<<i<<" "; cout<<endl;
}
