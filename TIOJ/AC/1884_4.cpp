#include<bits/stdc++.h>
#define ll long long


using namespace std;

inline ll rit(){
    ll t=0;
    char j;
    do{j=getchar();}while((j<'0' || j>'9'));
    do{
        t = t*10+j-'0';
        j=getchar();

    }while((j>='0' && j<='9'));
    return t;
}

int main(){
    ll t=rit();
    while(t--){
        ll n=rit(),k=rit(),l=rit();
        vector<ll> fnt,bak,dis;
        fnt.clear();
        bak.clear();
        dis.clear();
        fnt.resize(n+2);
        bak.resize(n+2);
        dis.resize(n+2);
        for(int i=1;i<=n;i++){
            dis.at(i)=rit();   //     cout<<wait.at(i)<<" "<<l-wait.at(i)<<endl;;
        }

        dis.at(0) = fnt.at(0) = bak.at(n+1) = 0;dis.at(n+1) = l;
        for(int i=1;i<=n;i++){
            dis.at(i) = min(dis.at(i) , l-dis.at(i));       //  cout<<dis.at(i)<<endl;

            if(i-k>=0){fnt.at(i) = fnt.at(i-k)+dis.at(i)*2;}
            else{fnt.at(i) = dis.at(i)*2;}
        }
        for(int i=n;i>0;i--){
            if(i+k<=n+1){bak.at(i)=bak.at(i+k)+dis.at(i)*2;}
            else{bak.at(i)=dis.at(i)*2;}
        }

        ll ans=1000000000;
        for(int i=0;i<=n;i++){
            ans = min(ans, fnt.at(i) + bak.at(i+1));
        }
        printf("%I64d\n",ans);
    }
}
