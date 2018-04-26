#include<bits/stdc++.h>
using namespace std;

pair<int,int> bar[100005];
int de[200005],mxdep[100005],mndep[100005],c1[100005],c2[100005];

pair<int,int> dfs(int now,int dep){
    if(now<0){
        // cout<<"item "<<-now<<" dep :"<<dep<<endl;
        de[-now]=dep;
        return pair<int,int>(dep,dep);
    }
    auto r1=dfs(bar[now].first,dep+1),r2=dfs(bar[now].second,dep+1);
    mxdep[now]=max(r1.first,r2.first);
    mndep[now]=min(r1.second,r2.second);
    return pair<int,int>(mxdep[now],mndep[now]);
}

void prec(int now,int n1,int n2){
    if(now<0)return;
    if(bar[now].first<0){
        if(de[-bar[now].first]==n1)++c1[now];
        else ++c2[now];
    }
    else{
        prec(bar[now].first,n1,n2);
        c1[now]+=c1[bar[now].first];
        c2[now]+=c2[bar[now].first];
    }
    if(bar[now].second<0){
        if(de[-bar[now].second]==n1)++c1[now];
        else ++c2[now];
    }
    else{
        prec(bar[now].second,n1,n2);
        c1[now]+=c1[bar[now].second];
        c2[now]+=c2[bar[now].second];
    }
    // cout<<"prec "<<now<<" "<<c1[now]<<" "<<c2[now]<<endl;
}

int meow(int now,int n1,int ne1,int n2,int ne2){
    // cout<<"meow "<<now<<" "<<n1<<" "<<ne1<<" "<<n2<<" "<<ne2<<endl;
    if(now<0)return 0;
    if(bar[now].first<0 && bar[now].second<0){
        if(mndep[now]==n2){
            if(ne2!=2)exit((cout<<-1<<endl,0));
            return 0;
        }
        else{
            if(ne1!=2)exit((cout<<-1<<endl,0));
            return 0;
        }
    }
    if(bar[now].first<0){
        return 1+meow(bar[now].second,n1,ne1-1,n2,ne2);
    }
    if(bar[now].second<0){
        return meow(bar[now].first,n1,ne1-1,n2,ne2);
    }
    if(c2[bar[now].first]==ne2 && c1[bar[now].second]==ne1)return 0;
    if(c1[bar[now].first]==ne1 && c2[bar[now].second]==ne2)return 1;
    if(c2[bar[now].first]<=ne2 && !c1[bar[now].first]){
        return meow(bar[now].second,n1,ne1-c1[bar[now].first],n2,ne2-c2[bar[now].first]);
    }
    if(c2[bar[now].second]<=ne2 && !c1[bar[now].second]){
        return 1+meow(bar[now].first,n1,ne1-c1[bar[now].second],n2,ne2-c2[bar[now].second]);
    }
    if(c1[bar[now].first]<=ne1 && !c2[bar[now].first]){
        return 1+meow(bar[now].second,n1,ne1-c1[bar[now].first],n2,ne2-c2[bar[now].first]);
    }
    if(c1[bar[now].second]<=ne1 && !c2[bar[now].second]){
        return meow(bar[now].first,n1,ne1-c1[bar[now].second],n2,ne2-c2[bar[now].second]);
    }
    exit((cout<<-1<<endl,0));
}

int main(){
    int n; cin>>n;
    int item=0;
    for(int i=1;i<=n;++i){
        cin>>bar[i].first>>bar[i].second;
        // swap(bar[i].first,bar[i].second);
        if(bar[i].first<0)bar[i].first=--item;
        if(bar[i].second<0)bar[i].second=--item;
    }
    tie(mxdep[1],mndep[1])=dfs(1,0);
    if(mxdep[1]-mndep[1]>1)exit((cout<<-1<<endl,0));
    if(mxdep[1]==mndep[1])exit((cout<<0<<endl,0));
    int c1=0,c2=0;
    for(int i=1;i<=-item;++i)if(de[i]==mndep[1])++c1;else ++c2;
    prec(1,mndep[1],mxdep[1]);
    cout<<meow(1,mndep[1],c1,mxdep[1],c2)<<endl;
    
}
