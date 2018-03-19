#include<bits/stdc++.h>
using namespace std;
#define ll long long

void no(){cout<<"NO"<<endl; exit(0);}

int n,m;
ll a[555],b[555];

int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;++i)cin>>b[i];
    int ptr=1,i=1,ofs=0;
    vector<pair<int,char>> ans;
    while(ptr<=m){
        ll tot=0;
        int start=i;
        while(tot<b[ptr]){
            if(tot+a[i]>b[ptr])no();
            tot+=a[i];
            ++i;
        }
        int end=i-1;
        // cout<<"start end "<<start<<" "<<end<<endl;
        bool allsame=1;
        for(int ii=start+1;ii<=end;++ii)if(a[ii]!=a[ii-1])allsame=0;
        if(allsame && end!=start)no();
        ll bg=0;
        for(int ii=start;ii<=end;++ii)bg=max(bg,a[ii]);
        int bpos=start;
        for(int ii=start;ii<=end;++ii)if(a[ii]==bg){
            if((ii>start && a[ii-1]<a[ii]) || (ii<end && a[ii+1]<a[ii]))bpos=ii;
        }
        int addofs=0;
        int eatr=end-bpos;
        int eatl=bpos-start;
        // cout<<eatl<<" "<<eatr<<endl;
        if(eatr && a[bpos+1]<a[bpos]){
            ++addofs;
            ans.emplace_back(bpos-ofs,'R');
            --eatr;
        }
        else if(eatl && a[bpos-1]<a[bpos]){
            ans.emplace_back(bpos-ofs,'L');
            ++ofs;
            --eatl;
        }
        else if(start!=end)exit(7122);
        for(int $=0;$<eatr;++$){
            ++addofs;
            ans.emplace_back(bpos-ofs,'R');
        }
        for(int $=0;$<eatl;++$){
            ans.emplace_back(bpos-ofs,'L');
            ++ofs;
        }
        ofs+=addofs;
        ++ptr;
    }
    if(i<=n)no();
    cout<<"YES"<<endl;
    for(auto i:ans)cout<<i.first<<" "<<i.second<<endl;
}
