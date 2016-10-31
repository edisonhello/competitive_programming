#include<bitset>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,st[30005],ed[10005],org;
bitset<30005> v;
int main(){
    ios_base::sync_with_stdio(0);
    while(cin>>n>>m){
        v.reset();
        memset(st,0,sizeof(st));
        memset(ed,0,sizeof(ed));
        org=0;
        for(int i=0;i<m;++i){
            cin>>st[i]>>ed[i];
            if(st[i]>ed[i])org+=(ed[i]-st[i]+n);
            else org+=(ed[i]-st[i]);
        }
        sort(st,st+m);
        sort(ed,ed+m);
        cout<<"st:";for(int i=0;i<m;++i)cout<<st[i]<<" ";cout<<endl;
        cout<<"ed:";for(int i=0;i<m;++i)cout<<ed[i]<<" ";cout<<endl;
        int i=0,j=0,cst=0;
        for(;i<m&&j<m;++i,++j){
            if(st[i]<ed[j])++i;
            if(i>=m)break;
            v[i]=1;
            cst+=(ed[j]-st[i]);
        }
        if(j==0){

        }
        i=0;
        for(;i<m&&j<m;++i,++j){
            while(v[i])++i;
            if(i>=m)break;
            cst+=(ed[j]-st[i]+n);
        }
        cout<<org<<" "<<cst<<endl;
    }
}
