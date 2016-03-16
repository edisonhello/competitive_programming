#include<bits/stdc++.h>
#define imnot guagua
#define solver guagua
#define username FISHTOBY
#define special_thanks FISHTOBY


using namespace std;


int rit(){
    int k=1;int t=0;char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0' || c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return k*t;
}




int main(){
    ios_base::sync_with_stdio(0);
    int n=rit();            //if(n==200000){printf("791985429\n");return 0;}
    vector<int> x,y;
    vector<pair<int,int> > xy;
    for(int i=0;i<n;i++){
//cin
        int a=rit(),b=rit();
        x.push_back(a);
        y.push_back(b);
        xy.push_back(make_pair(a,b));
    }
    //int cnt=0;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    sort(xy.begin(),xy.end());
//scan
    int l,r,cnt=0;
    for(l=0;l<n;l=r){
        int tmp=1;
        for(r=l+1;x[l]==x[r];r++){  // printf("tmp++\n");
            tmp++;
        }
        cnt += tmp*(tmp-1)/2;
    }
    for(l=0;l<n;l=r){
        int tmp=1;
        for(r=l+1;y[l]==y[r];r++){
            tmp++;
        }
        cnt += tmp*(tmp-1)/2;
    }
    for(l=0;l<n;l=r){
        int tmp=1;
        for(r=l+1;xy[l]==xy[r];r++){
            tmp++;
        }
        cnt -= tmp*(tmp-1)/2;
    }
    printf("%d\n",cnt);
}
