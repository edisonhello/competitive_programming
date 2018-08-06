#include<bits/stdc++.h>
using namespace std;

struct pixel{
    int r,g,b;
} pic[500][500];

bool operator<(const pixel &a,const pixel &b){ return tie(a.r,a.g,a.b)<tie(b.r,b.g,b.b); }

double dist(pixel a,pixel b){
    return sqrt(pow(a.r-b.r,2)+pow(a.g-b.g,2)+pow(a.b-b.b,2));
}

int style(int n,int m,int R[500][500],int G[500][500],int B[500][500]){
    int pix=n*m;
    int sumR=0,sumG=0,sumB=0;
    int maxcolor=n*m*256;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j){
        pic[i][j]={R[i][j],G[i][j],B[i][j]};
        sumR+=R[i][j];
        sumG+=G[i][j];
        sumB+=B[i][j];
    }
    int sar10=0,sad10=0;
    set<pixel> diffs;
    for(int i=0;i<n;++i)for(int j=0;j<m-1;++j){
        if(dist(pic[i][j],pic[i][j+1])<=10)++sar10;
    }
    for(int i=0;i<n-1;++i)for(int j=0;j<m;++j){
        if(dist(pic[i][j],pic[i-1][j])<=10)++sad10;
    }
    int dtwexp=0;
    int dtdgexp=0;
    pixel WHITE{255,255,255};
    pixel GREEN{0,255,0};
    for(int i=0;i<n;++i)for(int j=0;j<m;++j){
        if(dist(pic[i][j],WHITE)<=30)++dtwexp;
        if(dist(pic[i][j],GREEN)<=200)++dtdgexp;
    }
    double chance_10=(double)sar10/pix+(double)sad10/pix;
    if(chance_10>0.9){
        // cout<<(double)dtwexp/pix<<endl;
        if(dtwexp>=100)return 1;

        int ano=2;
        pixel sWHITE{255>>ano,255>>ano,255>>ano};
        // int dtswexp=0;
        map<pixel,int> mp;
        for(int i=0;i<n;++i)for(int j=0;j<m;++j){
            pixel p{pic[i][j].r>>ano,pic[i][j].g>>ano,pic[i][j].b>>ano};
            ++mp[p];
        }
        int mx=0;
        for(auto p:mp)mx=max(mx,p.second);
        for(auto p:mp)if(p.second>=mx-500){
            // cout<<p.first.r<<" "<<p.first.g<<" "<<p.first.b<<" "<<p.second<<endl;
            // cout<<dist(p.first,sWHITE)<<endl;
            if(dist(p.first,sWHITE)<=8)return 1;
            if(max(max(p.first.r,p.first.g),p.first.b)-min(min(p.first.r,p.first.g),p.first.b)<=3)return 1;
        }

        
        return 4;
    }
    else{
        if((double)dtdgexp/pix>0.1)return 2;
        return 3;
    }
}

int _R[500][500],_G[500][500],_B[500][500];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand(clock());
    int n,m; while(cin>>n>>m){
        for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>_R[i][j]>>_G[i][j]>>_B[i][j];
        // style(n,m,_R,_G,_B);
        cout<<style(n,m,_R,_G,_B)<<endl;
    }
}
