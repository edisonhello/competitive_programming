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
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;cin>>s;

    int t = s.find('.');
    if(t<9898989){
        // cout<<t<<endl;

        string sa = s;
        sa.assign(sa,0,t);
        string sd = s;
        sd.assign(sd,t+1,s.length());
        cout<<sa<<endl<<sd<<endl;

        string nsa = "";
        int i;
        for(i=0;i<(int)sa.length();i++){
            if(sa[i]!='0')break;
        }
        nsa += sa[i++];
        nsa += '.';
        for(;i<(int)sa.length();i++){
            nsa += sa[i];
        }

        string nsd = "";
        for(i=sd.length()-1;i>=0;i--){
            if(sd[i]!='0')break;
        }
        // nsd += '.';
        for(;i>=0;i--){
            nsd = sd[i] + nsd;
        }

        cout<<nsa<<endl<<nsd<<endl;

        if(!nsa.length()<=1){
            if(nsa.length()-2){
                cout<<nsa<<nsd<<'E'<<nsa.length()-2<<'\n';
            }
            else{
                cout<<nsa<<nsd<<'\n';
            }
        }
        else{
            string ns = nsd;
            int i=0;
            for(;i<(int)ns.length();i++){
                if(ns[i]!='0')break;
            }
            string san = "";
            san += ns[i++];
            san += '.';
            int rec = i;
            for(;i<(int)ns.length();i++){
                san += ns[i];
            }
            cout<<san<<"E-"<<rec<<'\n';
        }
    }
    else{
        string ns = "";
        int i;
        for(i=0;i<(int)s.length();i++){
            if(s[i]!='0')break;
        }
        ns += s[i++];
        ns += '.';
        for(;i<(int)s.length();i++){
            ns += s[i];
        }
        s = ns;

        if(s.length()-2){
            cout<<s<<'E'<<ns.length()-2<<'\n';
        }
        else{
            cout<<s<<'\n';
        }
        return 0;
    }
}
