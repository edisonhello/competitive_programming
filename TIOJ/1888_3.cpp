#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
#define X first
#define Y second
#define mid (l+r)/2

using namespace std;

inline ull rit(){
    ull t=0,k=1;char c;
    do{
        c = getchar();
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c = getchar();
    }while(c>='0'&c<='9');
    return t*k;
}

int n,sw_t;
vector<int> ori_clo,clo_pos,oricpy,poscpy,oricpy2,poscpy2;
vector<pair<int,int> > sw,sw_do_rec;


bool can_do_in_time(int timeset){
    oricpy2.clear();
    poscpy2.clear();
    oricpy2=oricpy;
    poscpy2=poscpy;
    sw_do_rec.clear();
    int currectime=0;
    for(int i=0;i<n;i++){
        if(oricpy2[i]!=i){
            sw_do_rec.push_back(make_pair(oricpy2[i],oricpy2[poscpy2[i]]));
            swap(oricpy2[i],oricpy2[poscpy2[i]]);//jizz
            swap(poscpy2[oricpy2[i]],poscpy2[oricpy2[poscpy2[i]]]);
            currectime++;
        }
        if(currectime>timeset){
            return 0;
        }
    }

//    printf("swap rec = ");for(int i=0;i<sw_do_rec.size();i++)printf("(%d %d) ",sw_do_rec[i].X,sw_do_rec[i].Y);printf("\n");

    return 1;
}

void real_do(int timeset){
    int nowtime=0;
    cout<<timeset<<endl;
//    printf("real do at timeset %d\n",timeset);
    for(int i=0;i<sw_do_rec.size();i++){
        int ax = sw[i].X;
        int ay = sw[i].Y;
        int  x = sw_do_rec[i].X;
        int  y = sw_do_rec[i].Y;
        
        swap(ori_clo[ax],ori_clo[ay]);
        swap(clo_pos[ori_clo[ax]],clo_pos[ori_clo[ay]]);

//        printf("after auto swap %d, \n",i);
//        printf("ori_clo[n] = ");for(int j=0;j<n;j++)printf("%d ",ori_clo[j]);printf("\n");
//        printf("clo_pos[n] = ");for(int j=0;j<n;j++)printf("%d ",clo_pos[j]);printf("\n");

        swap(ori_clo[clo_pos[x]],ori_clo[clo_pos[y]]);
        swap(clo_pos[x],clo_pos[y]);
        
//        printf("after my swap %d, \n",i);
//        printf("ori_clo[n] = ");for(int j=0;j<n;j++)printf("%d ",ori_clo[j]);printf("\n");
//        printf("clo_pos[n] = ");for(int j=0;j<n;j++)printf("%d ",clo_pos[j]);printf("\n");

        cout<<clo_pos[sw_do_rec[i].X]<<" "<<clo_pos[sw_do_rec[i].Y]<<endl;
        nowtime++;
    }
    if(nowtime<timeset){
        cout<<"0 0"<<endl;
    }
    return ;
}

int sch(int l,int r){
//            printf("sch %d %d\n",l,r);
    
    oricpy.clear();
    poscpy.clear();
    oricpy = ori_clo;
    poscpy = clo_pos;

    for(int i=0;i<mid;i++){
        int x=sw[i].X;
        int y=sw[i].Y;

        swap(oricpy[x],oricpy[y]);
        swap(poscpy[oricpy[x]],poscpy[oricpy[y]]);
    }


    if(l==r){           
//        printf("return mid %d\n",mid);
        return mid;
    }
    
    if(can_do_in_time(mid)){    
//        printf("can do in time mid %d\n",mid);
        return sch(l,mid);
    }
    else{
//        printf("cant o in time mid %d\n",mid);
        return sch(mid+1,r);
    }
}

void _(){
/*    oricpy.clear();
    poscpy.clear();
    oricpy = ori_clo;
    poscpy = clo_pos;*/
    int time = sch(0,n-1);
    real_do(time);
/*    for(int i=0;i<n;i++){
        int x = sw[i].X;
        int y = sw[i].Y;
        
        swap(oricpy[x],oricpy[y]);
        swap(poscpy[oricpy[x]],poscpy[oricpy[y]]);

//        printf("after auto swap %d, \n",i);
//        printf("oricpy[n] = ");for(int j=0;j<n;j++)printf("%d ",oricpy[j]);printf("\n");
//        printf("poscpy[n] = ");for(int j=0;j<n;j++)printf("%d ",poscpy[j]);printf("\n");

        if(can_do_in_time(i+1)){
//            printf("get can do in time %d\n",i+1);
            real_do(i+1);
            break;
        }        
    }*/
    return;
}

int main(){
    int t=rit();
    while(t--){
        n = rit();
        ori_clo.clear();
        clo_pos.clear();
        ori_clo.resize(n);
        clo_pos.resize(n);
        sw.clear();
        for(int i=0;i<n;i++){
            ori_clo[i] = rit();
            clo_pos[ori_clo[i]] = i;
        }
        sw_t=rit();
        sw.resize(sw_t);
        for(int i=0;i<sw_t;i++){
            sw[i].X=rit();
            sw[i].Y=rit();
        }

//        printf("ori_clo[n] = ");for(int i=0;i<n;i++)printf("%d ",ori_clo[i]);printf("\n");
//        printf("clo_pos[n] = ");for(int i=0;i<n;i++)printf("%d ",clo_pos[i]);printf("\n");
//        printf("sw[sw_t] = ");for(int i=0;i<sw_t;i++)printf("(%d %d) ",sw[i].X,sw[i].Y);printf("\n");

        _();
    }
}
