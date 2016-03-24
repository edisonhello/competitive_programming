#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
#define X first
#define Y second
using namespace std;

inline ull rit(){
    ull t=0,k=1;char c;
    do{
        c=getchar();
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
}
int n,sw_t;
vector<int> ori_clo,doinjizz,doinif;
vector<pair<int,int> > sw,sw_rec;

bool can_done_in_time(int time){
    sw_rec.clear();
    doinif=doinjizz;
    int real=0;
    for(int i=0;i<n;i++){
        if(doinif[i]!=i){
            for(int j=i+1;j<n;j++){
                if(doinif[j]==i){
                    swap(doinif[i],doinif[j]);
                    sw_rec.push_back(make_pair(i,j));
                    real++;
                    break;
                }
            }
            if(real>time){
                return 0;
            }
        }
    }
    return 1;
}

void realdo(int time){
    int cnt=0;
    cout<<time<<endl;
    for(int i=0;i<sw_rec.size();i++){
        cnt++;
        swap(ori_clo[sw_rec[i].X],ori_clo[sw_rec[i].Y]);
        for(int j=0;j<n;j++){
            if(ori_clo[j]==sw_rec[i].X){
                cout<<j<<" ";
                break;
            }
        }
        for(int j=0;j<n;j++){
            if(ori_clo[j]==sw_rec[i].Y){
                cout<<j<<endl;
                break;
            }
        }
    }
    if(cnt!=sw_rec.size()){
        cout<<"0 0"<<endl;
    }
    return ;
}

void jizz(){
    doinjizz = ori_clo;
    for(int i=0;i<sw_t;i++){
        swap(doinjizz[sw[i].X],doinjizz[sw[i].Y]);
        for(int i=0;i<n;i++)printf("%d ",doinjizz[i]);printf("\n");
        if(can_done_in_time(i+1)){
            printf("can done in time %d\n",i+1);
            realdo(i+1);
            return;
        }
    }
}

int main(){
    int t=rit();
    while(t--){
        n=rit();
        ori_clo.clear();
        ori_clo.resize(n);
        for(int i=0;i<n;i++)ori_clo[i]=rit();
        printf("original cloth ");
        for(int i=0;i<n;i++)printf("%d ",ori_clo[i]);printf("\n");
        sw_t=rit();
        sw.clear();
        sw.resize(sw_t);
        for(int i=0;i<sw_t;i++){
            sw[i].first=rit();
            sw[i].second=rit();
        }
        printf("swap pair : ");
        for(int i=0;i<sw_t;i++)printf("(%d,%d) ",sw[i].X,sw[i].Y);
        printf("\ngo jizz\n");
        jizz();
    }
}
