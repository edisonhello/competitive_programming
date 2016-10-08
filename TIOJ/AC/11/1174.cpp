#include<bits/stdc++.h>
using namespace std;
int N[100005],M[100005],n,m,dis;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>N[i];
    }
    for(int i=0;i<m;i++){
        cin>>M[i];
    }
    sort(N,N+n);
    sort(M,M+m);
    dis=(1<<30);
    for(int i=0,j=0;i<n&&j<m;){
        dis=min(dis,abs(N[i]-M[j]));
        if(dis==0)break;
        if(N[i]<M[j])i++;
        else j++;
    }
    cout<<dis<<'\n';
}
