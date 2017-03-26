#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<int> xnums,ynums;
struct rec{int x1,y1,x2,y2,w;} a[200005];
int x[500006],y[500006];

main(){
    int n;cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2>>a[i].w;
        xnums.push_back(a[i].x1);
        xnums.push_back(a[i].x2);
        ynums.push_back(a[i].y1);
        ynums.push_back(a[i].y2);
    }

    sort(xnums.begin(),xnums.end());xnums.resize(unique(xnums.begin(),xnums.end())-xnums.begin());
    sort(ynums.begin(),ynums.end());ynums.resize(unique(ynums.begin(),ynums.end())-ynums.begin());

    for(int i=0;i<n;++i){
        a[i].x1=lower_bound(xnums.begin(),xnums.end(),a[i].x1)-xnums.begin();
        a[i].x2=lower_bound(xnums.begin(),xnums.end(),a[i].x2)-xnums.begin();
        a[i].y1=lower_bound(ynums.begin(),ynums.end(),a[i].y1)-ynums.begin();
        a[i].y2=lower_bound(ynums.begin(),ynums.end(),a[i].y2)-ynums.begin();
        // cout<<a[i].x1<<" "<<a[i].y1<<" "<<a[i].x2<<" "<<a[i].y2<<endl;
    }
    int mxw=0;
    for(int i=0;i<=(int)xnums.size();++i){
        int xw=0;
        memset(y,0,sizeof(y));
        for(int j=0;j<n;++j){
            if(a[j].x1<=i && i<=a[j].x2){
                xw+=a[j].w;
                continue;
            }
            y[a[j].y1]+=a[j].w;
            y[a[j].y2]-=a[j].w;
        }
        int nowy=0,mxy=0;
        for(int j=0;j<=(int)ynums.size();++j){
            nowy+=y[j];
            mxy=max(mxy,nowy);
        }
        assert(nowy==0);
        mxw=max(mxw,xw+mxy);
    }
    cout<<mxw<<endl;
}
