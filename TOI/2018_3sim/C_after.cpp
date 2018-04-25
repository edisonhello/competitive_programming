#include<bits/stdc++.h>
using namespace std;

int tb[100005],tbz;
vector<pair<int,int>> pt;
vector<pair<int,int>> pol[20];
double area[20];

int main(){
    auto gx=[&](int pa,int pb){return pt[pb].first-pt[pa].first;};
    auto gy=[&](int pa,int pb){return pt[pb].second-pt[pa].second;};
    auto sq=[&](int x){return x*x;};
    auto jizz=[&](int p1,int p2,int p3)->bool{
        return gx(p3,p2)*gy(p1,p2)-gy(p3,p2)*gx(p1,p2)>=0;
    };
    auto gen_tb=[&](){
        sort(pt.begin(),pt.end());
        pt.resize(unique(pt.begin(),pt.end())-pt.begin());
        tbz=0;
        for(int i=0;i<pt.size();++i){
            while(tbz>1 && jizz(tb[tbz-2],tb[tbz-1],i))--tbz;
            tb[tbz]=i; ++tbz;
        }
        int tmp=tbz;
        for(int i=pt.size()-2;i>=0;--i){
            while(tbz>tmp && jizz(tb[tbz-2],tb[tbz-1],i))--tbz;
            tb[tbz]=i; ++tbz;
        }
    };

    int k,l; cin>>k>>l;
    for(int i=1;i<=k;++i){
        int n; cin>>n;
        pol[i].resize(n);
        for(int j=0;j<n;++j){
            cin>>pol[i][j].first>>pol[i][j].second;
        }
        pol[i].push_back(pol[i][0]);
        double ta=0;
        for(int j=1;j<pol[i].size();++j){
            ta+=pol[i][j-1].first*pol[i][j].second-pol[i][j-1].second*pol[i][j].first;
        }
        pol[i].pop_back();
        ta=abs(ta); ta/=2;
        area[i]=ta;
        pt=pol[i];
        gen_tb();
        pol[i].clear();
        for(int j=0;j<tbz-1;++j)pol[i].push_back(pt[tb[j]]);
        // cout<<"tbz: "<<tbz<<endl;
        // for(auto p:pol[i])cout<<"("<<p.first<<","<<p.second<<") "; cout<<endl;
    }


    auto sol=[&]()->bool{
        gen_tb();
        double len=0;
        for(int i=1;i<tbz;++i){
            len+=sqrt(sq(gx(tb[i],tb[i-1]))+sq(gy(tb[i],tb[i-1])));
        }
//        cout<<len<<endl;
        return len-1e-10<=l;
    };

    double ans=0;
    for(int i=1;i<(1<<k);++i){
        pt.clear();
        double aaa=0;
        for(int j=1;j<=k;++j)if(i&(1<<(j-1))){
            for(auto &p:pol[j])pt.push_back(p);
            aaa+=area[j];
        }
//        cout<<"points: "<<endl;
//        for(auto p:pt)cout<<p.first<<" "<<p.second<<endl;
        if(sol())ans=max(ans,aaa);
    }
    cout<<fixed<<setprecision(1)<<ans<<endl;
}
// AC
