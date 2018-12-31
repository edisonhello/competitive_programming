#define DEBUG 0
#include<bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

string s[3003],t[3003];
long long hhs[3003][3003],hht[3003][3003],pp[3003],hhts[3003],hhtt[3003];
pair<int,int> cseg[3003];

#define gethh(a, l, r) ((a[r] - ((l)?a[(l)-1]:0ll) + mod) * pp[3001-(r)] % mod)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    pp[0]=1;
    for(int i=1;i<3003;++i)pp[i]=pp[i-1]*47017%mod;
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>s[i];
    for(int i=1;i<=n;++i)cin>>t[i];

    if(DEBUG){
        for(int i=1;i<=n;++i)cout<<s[i]<<endl<<t[i]<<endl<<endl;
    }
    
    string ts,tt;
    for(int i=1;i<=n;++i){
        int L=1e9,R=0;
        for(int j=0;j<int(s[i].size());++j){
            if(s[i][j]!=t[i][j])L=min(L,j),R=max(R,j);
        }
        cseg[i]={L,R};
        if(L<1e9){
            string cs=s[i].substr(L,R-L+1);
            string ct=t[i].substr(L,R-L+1);
            if(ts=="")ts=cs,tt=ct;
            else{
                if(ts!=cs || tt!=ct)exit((cout<<"NO"<<endl,0));
                else ;
            }
        }
    }
    while (1) {
        bool lexp=1;
        char lsamp=0;
        char tsamp=0;
        for (int i=1;i<=n;++i) {
            if (cseg[i].first == 1e9) continue;
            if (cseg[i].first==0) {
                if(DEBUG){ cout<<"l can not expand at i="<<i<<endl; }
                lexp=0;
                break;
            }
            if (lsamp) {
                if (s[i][cseg[i].first-1]!=lsamp || t[i][cseg[i].first-1]!=tsamp) {
                    lexp=0;
                    if(DEBUG){ cout<<"l can not expand at i="<<i<<endl; }
                    break;
                } else ;
            } else {
                lsamp=s[i][cseg[i].first-1];
                tsamp=t[i][cseg[i].first-1];
            }
        }
        if (!lexp) break;
        ts = string(1, lsamp) + ts;
        tt = string(1, tsamp) + tt;
        for (int i = 1; i <= n; ++i) {
            if (cseg[i].first == 1e9) continue;
            --cseg[i].first;
        }
    }
    while (1) {
        bool rexp = 1;
        char samp = 0;
        char tamp = 0;
        for (int i = 1; i <= n; ++i) {
            if (cseg[i].first == 1e9) continue;
            if (cseg[i].second == int(s[i].size()) - 1) {
                rexp = 0;
                break;
            }
            if (samp) {
                if (s[i][cseg[i].second+1] != samp || t[i][cseg[i].second+1] != tamp) {
                    rexp = 0;
                    break;
                } else ;
            } else {
                samp = s[i][cseg[i].second+1];
                tamp = t[i][cseg[i].second+1];
            }
        }
        if (!rexp) break;
        ts += samp;
        tt += samp;
        for (int i = 1; i <= n; ++i) {
            if (cseg[i].first == 1e9) continue;
            ++cseg[i].second;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < int(s[i].size()); ++j) {
            if (j) hhs[i][j] = (hhs[i][j-1] + s[i][j] * pp[j]) % mod;
            else hhs[i][j] = s[i][j];
            if (j) hht[i][j] = (hht[i][j-1] + t[i][j] * pp[j]) % mod;
            else hht[i][j] = t[i][j];
        }
    }
    for (int j = 0; j < int(ts.size()); ++j) {
        if (j) hhts[j] = (hhts[j-1] + ts[j] * pp[j]) % mod;
        else hhts[j] = ts[j];
        if (j) hhtt[j] = (hhtt[j-1] + tt[j] * pp[j]) % mod;
        else hhtt[j] = tt[j];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j + int(ts.size()) - 1 < int(s[i].size()); ++j) {
            if (gethh(hhs[i], j, j+int(ts.size())-1) == gethh(hhts, 0, int(ts.size())-1)) {
                if (cseg[i].first != j) {
                    cout << "NO" << endl;
                    exit(0);
                } else break;
            }
        }
    }
    cout << "YES" << endl << ts << endl << tt << endl;

}
