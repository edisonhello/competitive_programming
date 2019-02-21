#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

struct str{int x,y,r,i;} sa[100005];
bool cmp_xy(const str &a,const str &b){return a.x==b.x?a.y<b.y:a.x<b.x;}
bool dif(const str &a,const str &b){return !(a.x==b.x&&a.y==b.y);}
string s;
int n,pos[100005],lcpa[100005];


int main(){
    ios_base::sync_with_stdio(0);
    int ts;cin>>ts;while(ts--){
        cin>>s; n=(int)s.length();
        for(int i=0;i<n;++i){
            sa[i].x=s[i];
            sa[i].y=0;
            sa[i].r=0;
            sa[i].i=i;
            lcpa[i]=0;
        }
        {
            sort(sa,sa+n,cmp_xy);
            sa[0].r=1; for(int i=1;i<n;++i)if(dif(sa[i-1],sa[i]))sa[i].r=sa[i-1].r+1;else sa[i].r=sa[i-1].r;
            for(int i=0;i<n;++i)pos[sa[i].i]=i,sa[i].x=sa[i].r;
            // for(int i=0;i<n;++i)cout<<sa[i].i<<"("<<sa[i].x<<","<<sa[i].y<<") ";cout<<endl;
            for(int D=1;D<n;D<<=1){
                for(int i=0;i<n;++i)sa[i].y=(sa[i].i+D<n?sa[pos[sa[i].i+D]].x:0);
                sort(sa,sa+n,cmp_xy);
                sa[0].r=1; for(int i=1;i<n;++i)if(dif(sa[i-1],sa[i]))sa[i].r=sa[i-1].r+1;else sa[i].r=sa[i-1].r;
                for(int i=0;i<n;++i)pos[sa[i].i]=i,sa[i].x=sa[i].r;
                // for(int i=0;i<n;++i)cout<<sa[i].i<<"("<<sa[i].x<<","<<sa[i].y<<") ";cout<<endl;
            }
            // cout<<"sa:";for(int i=0;i<n;++i)cout<<sa[i].i<<" ";cout<<endl;
        }
        // cout<<"Pos: ";for(int i=0;i<n;++i)cout<<pos[i]<<" ";cout<<endl;
        for(int i=0,lcpl=0;i<n;++i,--lcpl){
            if(pos[i]==0)continue;
            // cout<<"doing pos "<<pos[i]<<" and "<<pos[i]-1<<endl;
            if(lcpl<0)lcpl=0;
            while(sa[pos[i]].i+lcpl>=n || sa[pos[i]-1].i+lcpl>=n)--lcpl;
            // cout<<i<<" , "<<lcpl<<endl;
            while(sa[pos[i]].i+lcpl<n && sa[pos[i]-1].i+lcpl<n && s[sa[pos[i]].i+lcpl]==s[sa[pos[i]-1].i+lcpl])++lcpl;
            lcpa[pos[i]]=lcpl;
        }
        // cout<<"sa :";for(int i=0;i<n;++i)cout<<sa[i].i<<" ";cout<<endl;
        // cout<<"lcp:";for(int i=0;i<n;++i)cout<<lcpa[i]<<" ";cout<<endl;
        // for(int i=0;i<n;++i)cout<<sa[i].i<<" "<<lcpa[i]<<endl;
        ll ans=(ll)(n-sa[0].i+1)*(n-sa[0].i)/2; for(int i=1;i<n;++i){
            // cout<<lcpa[i]+1<<" "<<n-sa[i].i<<endl;
            ans+=(ll)(lcpa[i]+1+n-sa[i].i)*(n-sa[i].i-lcpa[i])/2;
        }
        cout<<ans<<endl;
    }
}
