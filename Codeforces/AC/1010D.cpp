#include<bits/stdc++.h>
using namespace std;

string gate[1000006];
int input[1000006][2];
bitset<1000006> ou,nof,aff;

int dfs(int now){
    if(gate[now][0]=='I')return input[now][0];
    if(gate[now][0]=='X')return dfs(input[now][0])^dfs(input[now][1]);
    if(gate[now][0]=='N')return !dfs(input[now][0]);
    if(gate[now][0]=='A'){
        int r1=dfs(input[now][0]);
        int r2=dfs(input[now][1]);
        if(!r1 && !r2)nof[input[now][0]]=nof[input[now][1]]=1;
        else if(r1 && !r2)nof[input[now][0]]=1;
        else if(!r1 && r2)nof[input[now][1]]=1;
        return r1 && r2;
    }
    if(gate[now][0]=='O'){
        int r1=dfs(input[now][0]);
        int r2=dfs(input[now][1]);
        if(r1 && r2)nof[input[now][0]]=nof[input[now][1]]=1;
        else if(r1 && !r2)nof[input[now][1]]=1;
        else if(!r1 && r2)nof[input[now][0]]=1;
        return r1 || r2;
    }
    assert(0);
}

void ddffss(int now){
    if(nof[now])return;
    aff[now]=1;
    if(gate[now][0]=='I')return;
    if(gate[now][0]=='X')return ddffss(input[now][0]),ddffss(input[now][1]),void();
    if(gate[now][0]=='N')return ddffss(input[now][0]),void();
    if(gate[now][0]=='A')return ddffss(input[now][0]),ddffss(input[now][1]),void();
    if(gate[now][0]=='O')return ddffss(input[now][0]),ddffss(input[now][1]),void();
    assert(0);
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>gate[i];
        int in=2;
        if(gate[i][0]=='N' || gate[i][0]=='I')in=1;
        if(in==2)cin>>input[i][0]>>input[i][1];
        else cin>>input[i][0];
        if(gate[i][0]!='I')ou[input[i][0]]=ou[input[i][1]]=1;
    }
    int out=-1;
    for(int i=1;i<=n;++i)if(!ou[i])out=i;
    int ov=dfs(out);
    ddffss(out);
    for(int i=1;i<=n;++i){
        if(gate[i][0]!='I')continue;
        if(aff[i])cout<<!ov;
        else cout<<ov;
    }
    cout<<endl;
}
