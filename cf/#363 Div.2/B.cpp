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
/*inline int rit(){
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
}*/
int n,m;
vector<string> mp;
vector<vector<int> > cnt1,cnt2;

int tryput(int x,int y){
    // cout<<x<<" "<<y<<endl;
    for(int i=0;i<n;i++){
        if(i==x)continue;
        if(cnt1[i].size()>1){
            // cout<<i<<"rt01"<<endl;
            return 0;
        }
        else if(cnt1[i].size()&&cnt1[i][0]!=y){
            // cout<<i<<"rt02"<<endl;
            return 0;
        }
    }
    for(int i=0;i<m;i++){
        if(i==y)continue;
        if(cnt2[i].size()>1){
            // cout<<i<<"rt03"<<endl;
            return 0;
        }
        else if(cnt2[i].size()&&cnt2[i][0]!=x){
            // cout<<i<<"rt04"<<endl;
            return 0;
        }
    }
    return 1;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>n>>m;
    mp.rz(n);
    for(int i=0;i<n;i++){
        cin>>mp[i];
    }
    cnt1.rz(n);
    cnt2.rz(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='*'){
                cnt1[i].PB(j);
                cnt2[j].PB(i);
            }
        }
    }

    // cout<<"a"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<cnt1[i].size();j++){
            if(tryput(i,cnt1[i][j])){
                cout<<"YES\n"<<i+1<<' '<<cnt1[i][j]+1<<'\n';
                return 0;
            }
        }
    }
    cout<<"NO\n";
}
