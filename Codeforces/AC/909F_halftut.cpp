#include<bits/stdc++.h>
using namespace std;

int match[100005];

bool solve0(int n,bool outside=1){
    // cout<<"solve0 "<<n<<endl;
    if(!n)return 1;
    int nn=n+1;
    if(nn^((nn)&(-nn))); else return 0;
    while(nn^((nn)&(-nn)))nn+=((nn)&(-nn));
    // cout<<"nn is "<<nn<<endl;
    --nn;
    for(int j=n,i=nn-n;i<j;++i,--j)match[i]=j,match[j]=i;
    if(!solve0(nn-n-1,0))return 0;
    if(outside){
        cout<<"YES"<<endl;
        for(int i=1;i<=n;++i)cout<<match[i]<<" ";
        cout<<endl;
        for(int i=1;i<=n;++i)if(match[i]&i)exit(71220);
    }
    return 1;
}
void solve1(int n){
/* tutorial */
    if(n<6 || (((n)&(-n))==n))return cout<<"NO\n",void();
    if(n==6)return cout<<"YES\n3 6 2 5 1 4\n",void();
    cout<<"YES\n3 6 7 5 4 2 1";
    if(n==7)return cout<<endl,void();
    for(int i=8,j=15;;i<<=1,j=(j<<1)+1){
        j=min(j,n);
        for(int a=i;a<j;++a)cout<<" "<<a+1; cout<<" "<<i;
        if(j==n)break;
    }
    return cout<<endl,void();
}

int main(){
    int n; cin>>n;
    if(!solve0(n))cout<<"NO"<<endl;
    solve1(n);
    /* for(int i=1;i<=12;++i){
        printf("%2d : ",i);
        cout<<bitset<10>(i)<<endl;
    } */
}
