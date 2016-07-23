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
#define mid (l+r)/2
// inline int rit(){
//     int t=0,k=1;
//     char c;
//     do{
//         c=getchar();
//         if(c=='-')k=-1;
//     }while(c<'0'||c>'9');
//     do{
//         t=t*10+c-'0';
//         c=getchar();
//     }while(c>='0'&&c<='9');
//     return t*k;
// }
int n;
string s;
vint convs;
map<char,int> toint;

int getindex(char c){
    if(toint.find(c)==toint.end()){
        toint[c]=toint.size();
    }
    return toint[c];
}

bool _try(int cnt){
    vint app;
    app.rz(n);
    int cntapp=0;

    int lft=0,rgh=0;
    while(rgh<n){
        app[convs[rgh]]++;
        if(app[convs[rgh]]==1){
            cntapp++;
            // cout<<"rgh="<<rgh<<", cntapp++\n";
        }

        if(rgh-lft>=cnt){
            app[convs[lft]]--;
            if(app[convs[lft]]==0){
                cntapp--;
            }
            lft++;
        }
// cout<<cntapp<<endl;
        if(cntapp==(int)toint.size()){
            return 1;
        }

        rgh++;
    }
    return 0;
}

int bs(int l,int r){
    // cout<<"bs "<<l<<" "<<r<<endl;
    if(l==r)return l;
    if(_try(mid)){
        return bs(l,mid);
    }
    else{
        return bs(mid+1,r);
    }
    return -9;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>n;
    cin>>s;
    convs.rz(n);

    if(s.length()==1){
        cout<<1<<'\n';
        return 0;
    }

    for(int i=0;i<n;i++){
        convs[i]=getindex(s[i]);
    }
// cout<<"afd"<<endl;
    cout<<bs(0,n)<<"\n";
}
