#include<bits/stdc++.h>
#define For(x) for(int i=0;i<x;i++)
using namespace std;
inline int rit(){
int ji;scanf("%d",&ji);return ji;
}




int n,k,l;
int *people_wait_at,*path,*room_wait;
int main(){
    int t=rit();
    while(t--){                             cout<<"jizz";
        n=rit(),k=rit(),l=rit();            cout<<"jizz";
        people_wait_at=new int[n];          cout<<"jizz";
        path=new int[n];
        room_wait=new int[l];
        For(n)people_wait_at[i]=rit();
        sort(people_wait_at,people_wait_at+n);
        //cout<<"asd";
        if(l%2==0)For(l/2){path[i]=i;path[l-1-i]=i;}
        if(l%2==1)path[l/2+1]=l/2;
        For(l)room_wait[i]=0;
        For(n)room_wait[people_wait_at[i]]++;   For(l)cout<<path[i]<<" ";
        room_wait[0]=0;
        int key=1;
        int time=0,nowgo=0,power=k,jizz=0;bool relaunch=1;
        while(1){       for(int i=0;i<l;i++)cout<<room_wait[i]<<" ";
                cout<<"now go "<<nowgo<<" room_wait[nowgo]:"<<room_wait[nowgo]
                    <<" tp"<<time<<" "<<power<<endl;
            if(nowgo==0){
                bool flag=false;
                for(int i=0;i<l/2;i++){
                    if(room_wait[i]){
                        flag = true;
                    }
                }
                if(!flag){
                    for(int i=1;i<l/2;i++){
                        int tmp = room_wait[l-1-i]; cout<<room_wait[l-1-i];
                        room_wait[l-1-i] = 0;
                        room_wait[i+1] = tmp;         cout<<room_wait[i];
                    }
                }S
            }
            if(power==0){cout<<"recharge\t";time+=path[nowgo];nowgo=0;power=k;continue;}
            if(room_wait[nowgo]==0 && nowgo<l-1){nowgo++;time++;continue;}
            //if(room_wait[nowgo]==0 && nowgo==l-1){time++;break;}

            room_wait[nowgo]--;power--;jizz++;
            if(jizz==n){
                time+=path[nowgo];
                break;
            }
        }
        printf("%d\n",time);
    }
    return 0;
}
