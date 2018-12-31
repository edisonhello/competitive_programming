#include<bits/stdc++.h>
using namespace std;

#define B 7

int main(){
    srand(time(0));
    while(1){
        vector<int> q;
        int cnt[B]={0};
        for(int i=0;i<B;++i){
            int x=0;
            while(bitset<B>(x).count()!=3)x=rand()%(1<<B);
            for(int j=0;j<B;++j){
                if((1<<j)&x)++cnt[j];
            }
            q.push_back(x);
        }
        bool no=0;
        for(int z=0;z<B;++z)if(cnt[z]>3)no=1;
        if(no)continue;
        int tt=0;
        for(int i=0;i<(1<<B);++i){
            int z=0;
            for(int j=0;j<B;++j){
                if(i&(1<<j)){
                    z^=q[j];
                }
            }
            if(bitset<B>(z).count()==1){
                tt^=z;
            }
        }
        if(tt==(1<<B)-1){
            for(int i=0;i<B;++i){
                // cout<<bitset<B>(q[i])<<endl;
                cout<<"int q"<<i<<"=query(";
                for(int z=0;z<B;++z){
                    if((1<<z)&q[i])cout<<"v["<<z<<"],";
                }
                cout<<");"<<endl;
            }
            cout<<endl;
            for(int i=0;i<(1<<B);++i){
                int z=0;
                for(int j=0;j<B;++j){
                    if(i&(1<<j)){
                        z^=q[j];
                    }
                }
                if(bitset<B>(z).count()==1){
                    for(int x=0;x<B;++x){
                        if(z&(1<<x)){
                            cout<<"a[v["<<x<<"]]=";
                            for(int j=0;j<B;++j){
                                if(i&(1<<j)){
                                    cout<<"q"<<j<<"^";
                                }
                            }
                            cout<<";"<<endl;
                        }
                    }
                }
            }
            break;
        }
    }
}
