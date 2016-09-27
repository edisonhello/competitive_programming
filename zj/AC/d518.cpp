#include<bits/stdc++.h>
using namespace std;
/*map=AC trie=TLE*/
struct side{
    int num;
    side *con[30];
    side(){
        num=0;
        memset(con,0,sizeof(con));
    }
} *root;

int cnt;

int dfs(string s,int c,side *now){
    // cout<<now<<endl;
    if(c==(int)s.length()){
        if(now->num!=0){
            return -(now->num);
        }
        else{
            return now->num=++cnt;
        }
    }
    if(now->con[s[c]-'a']){
        return dfs(s,c+1,now->con[s[c]-'a']);
    }
    else{
        now->con[s[c]-'a']=new side();
        return dfs(s,c+1,now->con[s[c]-'a']);
    }
}

void emp(side *now){
    for(int i=0;i<30;i++){
        if(now->con[i]){
            emp(now->con[i]);
        }
    }
    delete now;
}

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n,r;
    string s;
    while(cin>>n){
        cnt=0;
        root = new side();
        while(n--){
            cin>>s;
            r=dfs(s,0,root);
            if(r<0){
                cout<<"Old! "<<abs(r)<<'\n';
            }
            else{
                cout<<"New! "<<r<<'\n';
            }
        }
        emp(root);
    }
}
