#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii; //first: partial->AC, second: 0->partial
vector<pii> high; //高門檻題
vector<int> low; //低門檻題
int lowp[200010];
bool cmp(pii a,pii b)
{
    return a.first+a.second<b.first+b.second;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,t;
    cin>>n>>t;
    int hc=0,lc=0;
    for(int i=0;i<n;i++)
    {
        int h,c;
        cin>>h>>c;
        h-=c;
        if(h<c)
        {
            high.push_back({h,c});
            hc++;
        }
        else
        {
            low.push_back(h);
            low.push_back(c);
            lc+=2;
        }
    }
    sort(low.begin(),low.end());
    sort(high.begin(),high.end(),cmp);
    lowp[0]=0;
    for(int i=1;i<=lc;i++)
        lowp[i]=lowp[i-1]+low[i-1];
    int st=0;
    for(int i=0;i<hc;i++)
        st+=high[i].first+high[i].second;
    int ans=0,mnc=1000000000;
    multiset<int> mxc;
    mxc.insert(0);
    for(int i=0;i<hc;i++)
        mxc.insert(high[i].first);
    for(int i=hc-1;i>=-1;i--)
    {
        auto solv=[t,&ans,lc](int st,int ic)
        {
            if(st<=t)
            {
                int tc=upper_bound(lowp,lowp+lc+1,t-st)-lowp-1;
                ans=max(ans,ic+tc);
            }
        };
        solv(st,(i+1)*2);
        solv(st+mnc,(i+1)*2+1);
        solv(st-*mxc.rbegin(),(i+1)*2-1);
        if(i>=0)
        {
            st-=high[i].first+high[i].second;
            mnc=min(mnc,high[i].second);
            mxc.erase(mxc.find(high[i].first));
        }
    }
    cout<<ans<<endl;
}
