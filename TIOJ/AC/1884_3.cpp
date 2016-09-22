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
        vector<ll> wait,fnt,bak,dis;
        //wait.resize(n+2);
        fnt.clear();
        bak.clear();
        dis.clear();
        wait.clear();
        wait.resize(n+2);
        fnt.resize(n+2);
        bak.resize(n+2);
        dis.resize(n+2);
        for(int i=1;i<=n;i++){
            wait.at(i)=rit();   //     cout<<wait.at(i)<<" "<<l-wait.at(i)<<endl;;
        }

        for(int i=1;i<=n;i++){
            dis.at(i) = min(wait.at(i) , l-wait.at(i));       //  cout<<dis.at(i)<<endl;

            if(i-k>0){fnt.at(i) = fnt.at(i-k)+dis.at(i)*2;}
            else{fnt.at(i) = dis.at(i)*2;}
        }
        for(int i=n;i>0;i--){
            if(i+k<=n+1){bak.at(i)=bak.at(i+k)+dis.at(i)*2;}
            else{bak.at(i)=dis.at(i)*2;}
        }

        ll findmid=0;
        while(wait.at(findmid)<l/2 && findmid<n){findmid++;}
        ll cas1,cas2 = 1000000000;
        cas1 = fnt.at(findmid-1) + bak.at(findmid);   //  cout<<cas1<<endl;
        for(int i=0;i<=k;i++){                          // cout<<cas2<<endl;
            cas2 = min(cas2, fnt.at(findmid-i-1)+bak.at(findmid-1+i-k)+l);
        }


        ll ans=min(cas1,cas2);

        printf("%I64d\n",ans);
    }
}
