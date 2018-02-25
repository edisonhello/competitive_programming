#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

struct info{
    int x,y,r,i;
} a[200006];
int cnt[26],testcnt[26],pos[200006],lcpa[200006];
bitset<200006> goodpre;

const bool debug=0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; while(t--){
        string s,t; cin>>s>>t;
        if(debug){for(int i=0;i<t.size();++i)cout<<i%10; cout<<endl;}

        memset(cnt,0,sizeof(cnt));
        for(char c:s)++cnt[c-'a'];

        goodpre.reset();
        memset(testcnt,0,sizeof(testcnt));
        int start=0,end=0;
        for(;end<s.size();++end)++testcnt[t[end]-'a'];
        auto check=[&](){for(int i=0;i<26;++i)if(testcnt[i]>cnt[i])return 0; return 1;};
        if(check())goodpre[start]=1;
        while(end<t.size()){
            ++testcnt[t[end]-'a']; ++end;
            --testcnt[t[start]-'a']; ++start;
            if(check())goodpre[start]=1;
        }

        for(int i=0;i<t.size();++i)a[i]={t[i],0,0,i};
        auto cmp=[](const info &a,const info &b){return a.x==b.x?a.y<b.y:a.x<b.x;};
        int n=t.size();
        sort(a,a+n,cmp);
        for(int D=1;D<n;D<<=1){
            for(int i=0,r=1;i<n;++i)pos[a[i].i]=i,((i && cmp(a[i-1],a[i]))?a[i].r=++r:a[i].r=r);
            for(int i=0;i<n;++i)a[i].x=a[i].r,a[i].y=(a[i].i+D<n?a[pos[a[i].i+D]].r:0);
            sort(a,a+n,cmp);
        }
        if(debug){printf("sa:  "); for(int i=0;i<n;++i)printf("%2d ",a[i].i); puts("");}

        for(int i=0;i<n;++i)pos[a[i].i]=i;
        int lcpl=0;
        memset(lcpa,0,sizeof(lcpa));
        for(int i=0;i<n;++i,--lcpl){
            if(pos[i]==n-1)continue;
            lcpl=max(lcpl,0);
            lcpl=min(lcpl,min(n-i,n-a[pos[i]+1].i));
            while(lcpl+i<n && lcpl+a[pos[i]+1].i<n && t[lcpl+i]==t[lcpl+a[pos[i]+1].i])++lcpl;
            lcpa[pos[i]]=lcpl;
        }
        if(debug){printf("lcpa:"); for(int i=0;i<n;++i)printf("%2d ",lcpa[pos[i]]); puts("");}
        int mx=0;
        start=-1;
        for(int i=0;i<n;++i){
            if(goodpre[a[i].i]){
                memset(testcnt,0,sizeof(testcnt));
                int nowstart=a[i].i,len=1;
                while(lcpa[i]>=s.size())++len,++i;
                if(len>mx)mx=len,start=nowstart;
                // else if(len==mx && nowstr<ans)ans=nowstr;
            }
        }
        if(start==-1)cout<<start<<endl;
        else{
            for(int i=0;i<s.size();++i)cout<<t[i+start];
            cout<<endl;
        }
    }
}
