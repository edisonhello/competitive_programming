#include<iostream>
#include<string>
#include<vector>
using namespace std;

string s;
int hsh[2000005],_hsh[2000005],crs[2000005];
vector<int> ans;

const int P=27644437;

inline int gh1(int &l,int r){
    if(!l)return hsh[r-1];
    else return hsh[r-1]-hsh[l-1];
}
inline int gh2(int l,int r){
    if(!l)return _hsh[r-1];
    else return _hsh[r-1]-_hsh[l-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    int sl=(int)s.length(),sl2=sl<<1;
    s=s+s;

    crs[0]=1;
    for(int i=1;i<sl2;++i)crs[i]=crs[i-1]*P;
    for(int i=sl2-1,p=1;i>=0;--i,p=p*P)_hsh[sl2-1-i]=(s[i]-'0')*p;

    for(int i=0,p=1;i<sl2;++i,p=p*P){
        hsh[i]=(s[i]-'0')*p;
        if(i)hsh[i]+=hsh[i-1];
        if(i)_hsh[i]+=_hsh[i-1];
    }

    for(int i=0;i<sl;++i){
        if(i>sl-i){
            if(gh1(i,i+sl)==(gh2(sl-i,sl2-i)*crs[(i<<1)-sl]))ans.push_back(i);
        }
        else if((gh1(i,i+sl)*crs[sl-(i<<1)])==gh2(sl-i,sl2-i))ans.push_back(i);
    }

    if((int)ans.size()==0)cout<<"none\n";
    else{
        cout<<ans.size()<<":";
        for(int &i:ans)cout<<" "<<i;
        cout<<'\n';
    }
}
