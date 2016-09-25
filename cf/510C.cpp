#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) reserve(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue

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

int n;
vector<string> s;
string t;
bool mp[30][30];
string ans;
bool in[30];
bool stp[30];

int dfs(int now){
    // cout<<"dfsing now="<<(char)(now+'a')<<endl;;
    ans=(char)(now+'a')+ans;
    in[now]=1;
    for(int i=0;i<26;i++){
        if(i==now) continue;
        if(mp[now][i] && !in[i]){
            if(dfs(i)==-1) return -1;
        }
        else if(mp[now][i] && in[i]){
            return -1;
        }
    }
    return 0;
}

int main(){
    cin>>n;
    while(n--){
        cin>>t;
        s.PB(t);
    }
    for(int i=1;i<(int)s.size();i++){
        for(int j=0;j<(int)min(s[i].length(),s[i-1].length());j++){
            if(s[i][j]!=s[i-1][j]){
                // cout<<"mp["<<s[i][j]<<"]["<<s[i-1][j]<<"]=1\n";
                mp[s[i][j]-'a'][s[i-1][j]-'a']=1;
                stp[s[i-1][j]-'a']=1;
                break;
            }
        }
    }
    for(int i=0;i<26;i++){
        if(!in[i] && !stp[i]){
            if(dfs(i)==-1){
                cout<<"Impossible\n";
                return 0;
            }
        }
    }
    // reverse(ans.begin(),ans.end());
    if(ans.length()!=26){
        cout<<"Impossible\n";
        return 0;
    }
    cout<<ans<<endl;
}
