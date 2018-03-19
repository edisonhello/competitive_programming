#include<bits/stdc++.h>
using namespace std;

bool mp[222][222];
int pre[222][222];

string gen(int x1,int x2,int y1,int y2){
    // cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
    int ara=(x2-x1+1)*(y2-y1+1);
    int cnt=pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1];
    // cout<<ara<<" "<<cnt<<endl;
    if(cnt==ara)return "1";
    else if(!cnt)return "0";
    else{
        string rt="D";
        int xmid=(x1+x2)>>1;
        int ymid=(y1+y2)>>1;
        rt+=gen(x1,xmid,y1,ymid);
        if(ymid<y2)rt+=gen(x1,xmid,ymid+1,y2);
        if(xmid<x2)rt+=gen(xmid+1,x2,y1,ymid);
        if(ymid<y2 && xmid<x2)rt+=gen(xmid+1,x2,ymid+1,y2);
        return rt;
    }
}
void get(int x1,int x2,int y1,int y2,string &s,int &ptr){
    // cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<" "<<s[ptr]<<endl;
    if(ptr>=s.size())return;
    if(s[ptr]=='0'){++ptr; return;}
    else if(s[ptr]=='1'){
        for(int i=x1;i<=x2;++i){
            for(int j=y1;j<=y2;++j){
                mp[i][j]=1;
            }
        }
        ++ptr;
        return;
    }
    else{
        ++ptr;
        int xmid=(x1+x2)>>1;
        int ymid=(y1+y2)>>1;
        get(x1,xmid,y1,ymid,s,ptr);
        if(ymid<y2)get(x1,xmid,ymid+1,y2,s,ptr);
        if(xmid<x2)get(xmid+1,x2,y1,ymid,s,ptr);
        if(ymid<y2 && xmid<x2)get(xmid+1,x2,ymid+1,y2,s,ptr);
    }
}

int main(){
    string t; getline(cin,t); while(1){
        if(t=="#")break;
        int type=t[0];
        memset(mp,0,sizeof(mp));
        memset(pre,0,sizeof(pre));
        stringstream ss(t.substr(2,t.size()-2));
        int n,m; ss>>n>>m;
        t="";
        string s;
        while(getline(cin,t)){
            // cout<<"get t: \""<<t<<"\""<<endl;
            if((t.size()>1u && t[1]==' ') || t=="#")break;
            else s+=t;
        }
        if(type=='B'){
            int ptr=0;
            for(int i=1;i<=n;++i){
                for(int j=1;j<=m;++j){
                    mp[i][j]=(s[ptr]=='1');
                    ++ptr;
                }
            }
            for(int i=1;i<=n;++i){
                for(int j=1;j<=m;++j){
                    pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+mp[i][j];
                    // cout<<i<<" "<<j<<" "<<pre[i][j]<<endl;
                }
            }
            string ans=gen(1,n,1,m);
            printf("D%4d%4d\n",n,m);
            int cnt=0;
            for(char c:ans){
                if(cnt==50)cnt=0,cout<<'\n';
                cout<<c;
                ++cnt;
            }
            cout<<endl;
        }
        else{
            int ptr=0;
            get(1,n,1,m,s,ptr);
            printf("B%4d%4d\n",n,m);
            int cnt=0;
            for(int i=1;i<=n;++i){
                for(int j=1;j<=m;++j){
                    if(cnt==50)cnt=0,cout<<'\n';
                    cout<<mp[i][j];
                    ++cnt;
                }
            }
            cout<<endl;
        }
    }
}
