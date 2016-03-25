#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
#define X first
#define Y second
#define mid (l+r)/2
using namespace std;

int n,m;
vector<int> cloori,posori;
vector<int> clofind,posfind;
vector<pair<int,int> > sw,rec;

int findtime(int l,int r){
    if(l==r){
       return mid; 
    }
    
    clofind = cloori;
    posfind = posori;

    for(int i=0;i<mid;i++){
        int x = sw[i].X;
        int y = sw[i].Y;
        swap(clofind[x],clofind[y]);
        swap(posfind[clofind[x]],posfind[clofind[y]]);
    }
    rec.clear();
    int cnt=0;
    bool can=true;
    for(int i=0;i<n;i++){
        if(clofind[i]!=i){
            swap(clofind[i],clofind[posfind[clofind[i]]]);
            swap(posfind[clofind[i]],posfind[clofind[posfind[clofind[i]]]]);
            rec.push_back(make_pair(posfind[i],posfind[clofind[posfind[clofind[i]]]]));
            cnt++;
            if(cnt>mid){
                can=false;
            }
        }
    }
    if(can){
        return findtime(l,mid);
    }
    else{
        return findtime(mid+1,r);
    }
}

void _(){
    int time = findtime(0,n-1);
    int i;
    for(i=0;i<rec.size();i++){
        int x = sw[i].X;
        int y = sw[i].Y;
        swap(cloori[x],cloori[y]);
        swap(posori[cloori[x]],posori[cloori[y]]);

        x = rec[i].X;
        y = rec[i].Y;
        swap(cloori[posori[x]],cloori[posori[y]]);
        swap(posori[cloori[posori[x]]],posori[cloori[posori[y]]]);

        cout<<x<<" "<<y<<endl;
    }
    if(i==time){
        cout<<"0 0"<<endl;
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cloori.clear();
        cloori.resize(n);
        posori.clear();
        posori.resize(n);
        for(int i=0;i<n;i++){
            scanf("%d",&cloori[i]);
            posori[cloori[i]]=i;
        }
        scanf("%d",&m);
        sw.clear();
        sw.resize(m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&sw[i].X,&sw[i].Y);
        }

        _();
    }
}
