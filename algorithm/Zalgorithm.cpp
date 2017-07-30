// Codeforces 432D

int z[100008];
void solve(int n,string &s){
    int l=0,r=0; z[0]=n;
    for(int i=1;i<n;++i){
        z[i]=(i<=r?min(z[i-l],r-i):0);
        PDE4(i,l,r,z[i]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])++z[i];
        if(r<i+z[i])r=i+z[i]-1,l=i;
    }
    // for(int i=0;i<n;++i)cout<<z[i]<<" ";cout<<endl;
}
