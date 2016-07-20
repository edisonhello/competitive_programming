#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
}
int n;
vint a;
vint a1,a2;

int gotry(int now,int what,int brk){
    if(now==n){
        return brk;
    }
    /*if(a[now]==0){
        return gptry(now++,0,brk++);
    }
    else{

    }*/
    int v1=999,v2=999,v3=999;
    int getin=0;
    if(a1[now]&&what!=1){
        // cout<<"go1"<<endl;
        v1=gotry(now+1,1,brk);
        getin++;
    }
    if(a2[now]&&what!=2){
        v2=gotry(now+1,2,brk);
        getin++;
    }
    if(!getin){
        v3=gotry(now+1,0,brk+1);
    }
    return min(v1,min(v2,v3));
}

void sol(){
    printf("%d",gotry(0,0,0));
    /*int brk=0;
    int lst=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            brk++;
            continue;
        }

        if(lst==a[i]&&lst){
            brk++;
            continue;
        }
        else{
            if(lst==1)a[i]=2;
            if(lst==2)a[i]=1;
        }
        int end=-1;
        int j;
        for(j=i+1;j<n;j++){
            if(a[j]!=3){
                end=a[j];
                break;
            }
        }
        if(end==-1){
            break;
        }
        if(((end==a[i]&&(j-i)%2==1)||(end!=a[i]&&(j-i)%2==0))&&!(a[i]==3)){
            brk++;
        }
        lst=a[j];
        i=j;
    }
    cout<<brk<<'\n';*/
}


int main(){
    n=rit();
    a.rz(n);
    a1.rz(n);
    a2.rz(n);
    for(int i=0;i<n;i++){
        a[i]=rit();
        if(a[i]==1||a[i]==3){
            a1[i]=1;
        }
        if(a[i]==2||a[i]==3){
            a2[i]=1;
        }
    }

    sol();


}
