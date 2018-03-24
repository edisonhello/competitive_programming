#include<bits/stdc++.h>
using namespace std;
// #define ull unsigned long long
#define ll long long
#define nor(x) ((x%mod+mod)%mod)
#define left dfii

// #include"/home/edison/Coding/cpp/template/debug.cpp"
#define PDE(...) ;

const ll mod=1000000123;
const ll p=131;

int fail[1000006],bit[1000006],left[1000006];
ll pp[1000006],hsh[1000006];

#define lb(x) ((x)&-(x))

void add(int x,int v){
    PDE("add",v,x);
    for(;x<1000006;x+=lb(x))bit[x]=max(bit[x],v);
}
int query(int x,int v=0){
    for(;x;x-=lb(x))v=max(v,bit[x]);
    return v;
}

ll hh(int l,int r){
    return nor(hsh[r]-hsh[l-1])*pp[1000002-r]%mod;
}

void print(multiset<int> st){
    for(int i:st)cout<<i<<" "; cout<<endl;
}

int main(){
    pp[0]=1;
    for(int i=1;i<1000006;++i)pp[i]=pp[i-1]*p%mod;
    string s; 
    getline(cin,s);
    int n=s.size();
    s="."+s;
    for(int i=1;i<=n;++i)hsh[i]=((i?hsh[i-1]:0)+s[i]*pp[i-1])%mod;
    for(int i=2;i<=n;++i){
        int j=i;
        while(j && s[j]!=s[fail[j-1]+1])j=fail[j];
        // cout<<i<<" "<<j<<endl;
        fail[i]=fail[j-1]+(s[i]==s[fail[j-1]+1]);
    }
    for(int i=1;i<=n;++i)left[i]=fail[i];
    /* for(int i=n-1;i>=1;--i){
        if(left[i] && left[i+1]>left[i])left[i]=left[i+1],left[i+1]=0;
    } */
    for(int i=1,j;i<=n;i=j){
        for(j=i+1;j<=n;++j){
            if(left[j]!=left[i]+(j-i))break;
        }
        --j;
        left[i]=left[j];
        for(int k=i+1;k<=j;++k)left[k]=0;
        ++j;
    }
    // for(int i=1;i<=n;++i)cout<<fail[i]<<" "; cout<<endl;
    // for(int i=1;i<=n;++i)cout<<left[i]<<" "; cout<<endl;
    // multiset<int> st;
    // int L=n/3+1,R=n-n/3;
    int L=n/3+1,R=n-n/3;
    PDE(L,R);
    for(int i=L;i<=R;++i){
        if(i-fail[i]+1<L)add(i,left[i]);
        else add(i,fail[i]);
    }
    for(int i=n/3;i>=1;--i){
        // cout<<i<<" "<<hh(1,i)<<" "<<hh(n-i+1,n)<<endl;
        if(hh(1,i)==hh(n-i+1,n)){
            int llz=i+i,rr=n-i;
            PDE(i,llz,rr);
            while(R<rr)++R,add(R,fail[R]);
            // while(L<llz)st.erase(st.find(fail[L])),++L;
            while(L>llz)--L,add(L,left[L]);
            // print(st);
            // cout<<L<<" "<<R<<endl;
            if(query(R)>=i){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    cout<<0<<endl;
}
