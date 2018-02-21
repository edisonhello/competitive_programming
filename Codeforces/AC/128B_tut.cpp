#include<bits/stdc++.h>
using namespace std;

struct meow{
    int x,y,r,i;
} a[100009];
int pos[100009],lcpa[100009],st[19][100009],lg2[100009];

int query(int L,int R){
    // cout<<"Q: "<<L<<" "<<R<<" : ";
    if(L==R)return st[0][L];
    int D=R-L+1,i=0; while(D)D>>=1,++i; --i;
    // cout<<min(st[i][L],st[i][R-(1<<(i))+1])<<endl;
    return min(st[i][L],st[i][R-(1<<(i))+1]);
}

int main(){
    string s; cin>>s;
    // int n=s.size(),k; cin>>k;
    int n=s.size();
    for(int i=0;i<n;++i)a[i].x=s[i],a[i].i=i;
    sort(a,a+n,[](const meow &a,const meow &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
    // for(int i=0;i<n;++i)cout<<sa[i]<<" "; cout<<endl;
    for(int D=1;D<n;D<<=1){
        for(int i=0,r=1;i<n;++i)pos[a[i].i]=i,a[i].r=(r+=(a[i].x!=a[i-1].x || a[i].y!=a[i-1].y));
        for(int i=0;i<n;++i)a[i].x=a[i].r,a[i].y=(a[i].i+D>=n?0:a[pos[a[i].i+D]].r);
        sort(a,a+n,[](const meow &a,const meow &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
    }
    // for(int i=0;i<n;++i)cout<<a[i].i<<endl;
    int lcpl=0;
    for(int i=0;i<n;++i)pos[a[i].i]=i;
    for(int i=0;i<n;++i,--lcpl){
        if(pos[i]==n-1)continue;
        lcpl=max(0,lcpl);
        while(lcpl>0 && (i+lcpl>=n || a[pos[i]+1].i+lcpl>=n))--lcpl;
        while(i+lcpl<n && a[pos[i]+1].i+lcpl<n && s[i+lcpl]==s[a[pos[i]+1].i+lcpl])++lcpl;
        lcpa[i]=lcpl;
    }
    // cout<<"lcpa: "; for(int i=0;i<n;++i)cout<<lcpa[i]<<" "; cout<<endl;

    for(int i=0;i<n;++i)st[0][i]=lcpa[a[i].i];
    for(int i=1,D=1;D<n;++i,D<<=1){
        for(int j=0;j+2*D<n;++j){
            st[i][j]=min(st[i-1][j],st[i-1][j+D]);
        }
    }
    /* cout<<"st0 : "; for(int i=0;i<n;++i)cout<<st[0][i]<<" "; cout<<endl;
    cout<<"st1 : "; for(int i=0;i<n;++i)cout<<st[1][i]<<" "; cout<<endl;
    cout<<"st2 : "; for(int i=0;i<n;++i)cout<<st[2][i]<<" "; cout<<endl;
    cout<<"st3 : "; for(int i=0;i<n;++i)cout<<st[3][i]<<" "; cout<<endl; */
    lg2[1]=0; for(int i=2;i<100009;++i)lg2[i]=lg2[i/2]+1;
    int lcpn=0;
    int k; cin>>k;
    for(int i=0;i<n;++i){
        // cout<<"i: "<<i<<endl;
        while(lcpn<=n-a[i].i){
            ++lcpn;
            if(lcpn>n-a[i].i)break;
            int L=1,R=n;
            while(R>L){
                int M=(L+R+1)/2;
                // cout<<"LMR: "<<L<<" "<<M<<" "<<R<<endl;
                if(i+M-1<n && query(i,i+M-1)>=lcpn)L=M;
                else R=M-1;
            }
            // cout<<"L   : "<<L<<endl;
            if(lcpn<=lcpa[a[i].i])++L;
            // cout<<"L-> : "<<L<<endl;
            if(k<=L){
                for(int _=0;_<lcpn;++_){
                    cout<<s[a[i].i+_];
                }
                cout<<endl;
                exit(0);
            }
            else k-=L;
        }
        lcpn=lcpa[a[i].i];
    }
    cout<<"No such line."<<endl;
}
