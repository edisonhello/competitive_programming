// cf 429D
struct pnt{ll x,y;} p[100009],t[100009];
inline ll D(int i,int j){return (p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);}

ll meow(int l,int r){
    if(l==r)return 1e15;
    if(r==l+1)return D(l,r);
    int llim=(l+r)>>1,rlim=llim+1,lp=llim,rp=rlim;
    ll lds=meow(l,llim),
       rds=meow(rlim,r),
       nm=min(lds,rds);
    int pt=0;
    while(lp>=l && (p[llim].x-p[lp].x)*(p[llim].x-p[lp].x)<nm)t[pt++]=p[lp--];
    while(rp<=r && (p[rp].x-p[rlim].x)*(p[rp].x-p[rlim].x)<nm)t[pt++]=p[rp++];
    sort(t,t+pt,[](const pnt &a,const pnt &b){return a.y<b.y;});
    for(int i=0;i<pt;++i){
        for(int j=1;i+j<pt && j<4;++j){
            nm=min(nm,(t[i].x-t[i+j].x)*(t[i].x-t[i+j].x)+(t[i].y-t[i+j].y)*(t[i].y-t[i+j].y));
        }
    }
    return nm;
}

int main(){
    int n;cin>>n; ll pre=0;
    for(int i=1;i<=n;++i){
        ll t; cin>>t; pre+=t;
        p[i-1]={i,pre};
    }
    sort(p,p+n,[](const pnt &a,const pnt &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
    ll ans=meow(0,n-1);
    cout<<ans<<endl;
}
