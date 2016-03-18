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
    //ll t=1;
    while(t--){
        ll n=rit(),k=rit(),l=rit();

        vector<ll> pos,dis;
        pos.clear();dis.clear();
        pos.resize(n);dis.resize(n);
        for(int i=0;i<n;i++){
            pos[i] = rit();
            dis[i] = min(pos[i],l-pos[i]);
                    //printf("pos[%d]=%d,dis[%d]=%d\n",i,pos[i],i,dis[i]);
        }
        //findmid
        ll i=0;
        ll p=k;
        ll time=0;
        bool path=false;
        bool spk = false;
        while(!path){       //printf("now at %d, power left %d,time gone %d\n",i,p,time);
            if(pos[i]>=l/2){  //  printf("go throgh mid\n");
                if(p==0){       //printf("no power, spc case\n");
                    spk=true;
                }
                path=true;
                break;
            }
            if(p<=0){       //printf("repower time %d to",time);
                time+=dis[i]*2;// printf(" %d, at i=%d\n",time,i);
                p=k;
            }
            p--;           // printf("walk power %d,pos[%d] = %d\n",p,i,pos[i]);
            i++;
            if(i==n){
                time+=dis[i-1]*2;
                goto jizz;
            }
        }
        if(spk){               // printf("time %d to ",time);
            time+=dis[i-1]*2;/**///printf("%d\n",time);
            time+=dis[i]*2;
            p=k;
        }
        else{
            while(p){
                i++;p--;
                if(i==n){
                    time+=l;
                    goto jizz;
                }
            }
            time+=l;
            p=k;
            time+=dis[i]*2;
        }
        while(1){
            if(p<=0){
                time+=dis[i]*2;
                p=k;
            }
            i++;
            p--;
            if(i==n){
                goto jizz;
            }
        }
    jizz:
        cout<<time<<endl;









        /*vector<ll> fnt,bak,dis;
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
        printf("%I64d\n",ans);*/
    }
}
