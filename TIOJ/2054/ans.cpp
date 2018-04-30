#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define ws jfiodoood

vector<int> ls,ws;
int l[3333],w[3333],_l[3333],_w[3333];
int pre[3333][3333];

inline int get(int x1,int x2,int y1,int y2){
    // cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
    return pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1];
}

int main(){
    int n,lxx,wxx; cin>>n>>wxx>>lxx;
    if(n==1)return cout<<1<<endl,0;
    ls.resize(n); ws.resize(n);
    for(int i=0;i<n;++i){
        cin>>l[i]>>w[i];
        ls[i]=l[i];
        ws[i]=w[i];
    }
    sort(ls.begin(),ls.end());
    sort(ws.begin(),ws.end());
    for(int i=0;i<n;++i){
        _l[i]=lower_bound(ls.begin(),ls.end(),l[i])-ls.begin()+1;
        _w[i]=lower_bound(ws.begin(),ws.end(),w[i])-ws.begin()+1;
        pre[_l[i]][_w[i]]=1;
    }
    for(int i=1;i<3333;++i){
        for(int j=1;j<3333;++j){
            pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    /* for(int i=1;i<=10;++i){
        for(int j=1;j<=10;++j){
            cout<<pre[i][j]<<" ";
        }
        cout<<endl;
    } */
    int mx=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(abs(l[i]-l[j])>lxx || abs(w[i]-w[j])>wxx)continue;
            int l1=min(l[i],l[j]),l2=max(l[i],l[j]),w1=min(w[i],w[j]),w2=max(w[i],w[j]);
            int x1,x2,y1,y2;
            x1=l1,x2=x1+lxx,y1=w1,y2=y1+wxx;
            // x2=min(3332,x2),y2=min(3332,y2);
            x1=min(_l[i],_l[j]);
            y1=min(_w[i],_w[j]);
            x2=upper_bound(ls.begin(),ls.end(),x2)-ls.begin();
            y2=upper_bound(ws.begin(),ws.end(),y2)-ws.begin();
            mx=max(mx,get(x1,x2,y1,y2));

            x2=l2,x1=l2-lxx,y1=w1,y2=y1+wxx;
            // x1=max(1,x1),y2=min(3332,y2);
            x1=lower_bound(ls.begin(),ls.end(),x1)-ls.begin()+1;
            y1=min(_w[i],_w[j]);
            x2=max(_l[i],_l[j]);
            y2=upper_bound(ws.begin(),ws.end(),y2)-ws.begin();
            mx=max(mx,get(x1,x2,y1,y2));

            x1=l1,x2=x1+lxx,y2=w2,y1=y2-wxx;
            // x2=min(3332,x2),y1=max(1,y1);
            x1=min(_l[i],_l[j]);
            y1=lower_bound(ws.begin(),ws.end(),y1)-ws.begin()+1;
            x2=upper_bound(ls.begin(),ls.end(),x2)-ls.begin();
            y2=max(_w[i],_w[j]);
            mx=max(mx,get(x1,x2,y1,y2));

            x2=l2,x1=l2-lxx,y2=w2,y1=y2-wxx;
            // x1=max(1,x1),y1=max(1,y1);
            x1=lower_bound(ls.begin(),ls.end(),x1)-ls.begin()+1;
            y1=lower_bound(ws.begin(),ws.end(),y1)-ws.begin()+1;
            x2=max(_l[i],_l[j]);
            y2=max(_w[i],_w[j]);
            mx=max(mx,get(x1,x2,y1,y2));
        }
    }
    cout<<mx<<endl;
}
