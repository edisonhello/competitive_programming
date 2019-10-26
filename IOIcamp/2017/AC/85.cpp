#include<algorithm>
#include<iostream>
using namespace std;

#define int long long

string s;
struct inf{int x,y,r,i;} sa[100005];
bool cmp_xy(const inf &a,const inf &b){return a.x==b.x?a.y<b.y:a.x<b.x;}
bool dif(int a,int b){return (sa[a].x==sa[b].x)&&(sa[a].y==sa[b].y);}
int n,pos[100005],lcpa[100005];

void pnt(int i){while(i<n)cout<<s[i++];}
main(){
    int ts;cin>>ts;while(ts--){
        {
            cin>>s; n=(int)s.length();
            for(int i=0;i<n;++i)sa[i].x=s[i],sa[i].y=sa[i].r=0,sa[i].i=i,pos[i]=0,lcpa[i]=0;
        }
        {
            //for(int i=0;i<n;++i)cout<<"("<<sa[i].x<<","<<sa[i].y<<") ";cout<<endl;
            sort(sa,sa+n,cmp_xy);
            sa[0].r=1;for(int i=1;i<n;++i)if(!dif(i-1,i))sa[i].r=sa[i-1].r+1;else sa[i].r=sa[i-1].r;
            for(int i=0;i<n;++i)sa[i].x=sa[i].r,pos[sa[i].i]=i;
            // for(int i=0;i<n;++i)cout<<sa[i].i<<endl;cout<<endl;
            for(int D=1;D<n;D<<=1){
                // for(int i=0;i<n;++i)cout<<"("<<sa[i].x<<","<<sa[i].y<<") ";cout<<endl;
                for(int i=0;i<n;++i)sa[i].y=(sa[i].i+D>=n?0:sa[pos[sa[i].i+D]].x);
                // for(int i=0;i<n;++i)cout<<"("<<sa[i].x<<","<<sa[i].y<<") ";cout<<endl;
                sort(sa,sa+n,cmp_xy);
                // for(int i=0;i<n;++i)cout<<"("<<sa[i].x<<","<<sa[i].y<<") ";cout<<endl;cout<<endl;
                sa[0].r=1;for(int i=1;i<n;++i)if(!dif(i-1,i))sa[i].r=sa[i-1].r+1;else sa[i].r=sa[i-1].r;
                for(int i=0;i<n;++i)sa[i].x=sa[i].r,pos[sa[i].i]=i;
                // for(int i=0;i<n;++i)cout<<sa[i].i<<endl;cout<<endl;
            }
            // for(int i=0;i<n;++i){cout<<sa[i].i<<" ";pnt(sa[i].i);cout<<endl;}
        }
        {
            int lcpl=0;
            for(int i=0;i<n;++i){
                if(pos[i]==0)continue;
                --lcpl;
                if(lcpl<0)lcpl=0;
                while(sa[pos[i]].i+lcpl>=n || sa[pos[i]-1].i+lcpl>=n)--lcpl;
                while(sa[pos[i]].i+lcpl<n && sa[pos[i]-1].i+lcpl<n && s[sa[pos[i]].i+lcpl]==s[sa[pos[i]-1].i+lcpl])++lcpl;
                lcpa[i]=lcpl;
            }
            // for(int i=0;i<n;++i)cout<<lcpa[i]<<" ";cout<<endl;
        }
        {
            int ans=0;
            for(int i=0;i<n;++i)ans+=n-sa[i].i-lcpa[i];
            cout<<ans<<endl;
        }
    }
}
