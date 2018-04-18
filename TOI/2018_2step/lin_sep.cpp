#include<bits/stdc++.h>
using namespace std;
// #include"/home/edison/Coding/cpp/template/debug.cpp"
#define PDE(...) ;

vector<pair<double,double>> a,b;

int main(){
    int ts; cin>>ts; while(ts--){
        int n; cin>>n;
        a.clear(); b.clear();
        for(int i=0;i<n;++i){
            int x,y,t; cin>>x>>y>>t;
            if(t==1)a.emplace_back(x,y);
            else b.emplace_back(x,y);
        }
        auto ok=[&](int ap,int bp){
            vector<pair<pair<double,double>,int>> online;
            int posa=0,posb=0,nega=0,negb=0;
            auto pa=a[ap],pb=b[bp];
            double la,lb,lc;
            if(pa.first==pb.first)lb=0,la=1,lc=pa.first;
            else la=(pa.second-pb.second)/(pa.first-pb.first),lb=-1,lc=-(pa.second-la*pa.first);
            for(auto aa:a){
                double v=la*aa.first+lb*aa.second;
                if(abs(v-lc)<1e-9)online.emplace_back(aa,1);
                else if(v>lc)++posa;
                else ++nega;
            }
            for(auto aa:b){
                double v=la*aa.first+lb*aa.second;
                if(abs(v-lc)<1e-9)online.emplace_back(aa,2);
                else if(v>lc)++posb;
                else ++negb;
            }
            sort(online.begin(),online.end(),[](const auto &a,const auto &b){
                return abs(a.first.first-b.first.first)<1e-9?a.first.second<b.first.second:a.first.first<b.first.first;
            });
            if(posa&&posb)return 0;
            if(posa&&nega)return 0;
            if(nega&&negb)return 0;
            if(negb&&posb)return 0;
            int al=1e9,ar=-1e9,bl=1e9,br=-1e9;
            for(int i=0;i<online.size();++i){
                if(online[i].second==1){
                    al=min(al,i);
                    ar=max(ar,i);
                }
                else{
                    bl=min(bl,i);
                    br=max(br,i);
                }
            }
            al=max(al,bl);
            ar=min(ar,br);
            if(ar>=al)return 0;
            PDE(la,lb,lc);
            PDE(pa,pb);
            PDE(al,ar,bl,br);
            PDE(posa,posb,nega,negb);
            PDE(online);
            return 1;
        };
        int ans=0;
        for(int i=0;i<a.size();++i){
            for(int j=0;j<b.size();++j){
                if(ok(i,j)){ans=1; break;}
            }
            if(ans)break;
        }
        cout<<ans<<endl;
    }
}
