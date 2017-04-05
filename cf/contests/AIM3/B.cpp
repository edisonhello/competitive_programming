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
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2

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

int n,a;
// int x[100005];
vector<int> x,xl,xr;

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    cin>>n>>a;
    for(int i=0;i<n;i++){
        // cin>>x[i];
        int t;cin>>t;
        x.PB(t-a);
    }
    sort(x.begin(),x.end());


    int rd=100000009;

    // case 1
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    if(n==2){
        cout<<min(abs(x[0]),abs(x[1]))<<endl;
        return 0;
    }

    if((!(x[0]>0 || x[n-1]<0))){
        if(1){
            int mx=x[n-1],mn=x[1];
            mx=abs(mx);
            mn=abs(mn);
            // cout<<min(mn,mx)*2+max(mn,mx)<<endl;
            // cout<<rd<<endl;
            rd=min(rd,min(mn,mx)*2+max(mn,mx));
        }
        if(1){
            int mx=x[n-2],mn=x[0];
            mx=abs(mx);
            mn=abs(mn);
            // cout<<min(mn,mx)*2+max(mn,mx)<<endl;
            // cout<<rd<<endl;
            rd=min(rd,min(mn,mx)*2+max(mn,mx));
        }
        if((x[0]<0&&x[1]>0))goto aa;
        if((x[n-1]>0&&x[n-2]<0))goto bb;
    }
    else if((x[0]<0&&x[1]>0)){
        aa:
        rd=min(rd,x[n-1]);
    }
    else if((x[n-1]>0&&x[n-2]<0)){
        bb:
        rd=min(rd,abs(x[0]));
    }
    else{
        for(int i=0;i<n;i++)x[i]=abs(x[i]);
        sort(x.begin(),x.end());
        rd=min(rd,x[n-2]);
    }
    cout<<rd<<endl;
/*

    for(int i=0;i<n;i++){
        int mx=-1000009,mn=1000009;
        int s=0,e=n-1;
        while(s==i)s++;
        mn=min(mn,x[i]);
        // x.erase(x.begin()+i);
        while(e==i)e--;
        mx=max(mx,x[i]);
        mx=abs(mx);
        mn=abs(mn);
        cout<<min(mn,mx)*2+max(mn,mx)<<endl;
        // cout<<rd<<endl;
        rd=min(rd,min(mn,mx)*2+max(mn,mx));
    }*/



}
