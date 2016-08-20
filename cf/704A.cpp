#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x+5)
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
struct _noti{
    int f,n,x,l;
    _noti(){
        f = -1;
        n = -1;
        l =  1;
    }
};
_noti noti[300005];
vector<int> appg[300005];
int red[300005];


void d(int l,int r){
    cout<<"lr "<<l<<" "<<r<<endl<<"[";
    int i=l;
    while(i!=-1){
        cout<<noti[i].x<<" ";
        i=noti[i].n;
    }
    cout<<"]"<<endl;
}

int main(){
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    int n=rit(),q=rit();
    int _ptr=0;
    int f = -1;
    int e = -1;
    int unr = 0;
    for(int i=0;i<q;i++){
        int t=rit(),x=rit();
        if(t==1){
            noti[_ptr].f=e;
            noti[_ptr].x=x;
            if(f==-1)f=_ptr;
            if(e!=-1)noti[e].n=_ptr;
            e=_ptr;
            // cout<<e<<endl;
            appg[x].PB(_ptr);
            _ptr++;
            unr++;
        }
        else if(t==2){
            int j;
            // cout<<red[x]<<"|";
            for(j=red[x];j<(int)appg[x].size();j++){
                if(!noti[appg[x][j]].l)continue;
                int this_f=noti[appg[x][j]].f;
                int this_n=noti[appg[x][j]].n;
                if(noti[appg[x][j]].f!=-1)noti[this_f].n=this_n;
                else f=this_n;
                if(noti[appg[x][j]].n!=-1)noti[this_n].f=this_f;
                else e=this_f;
                noti[appg[x][j]].l=0;
                unr--;
            }
            red[x]=j;
            // cout<<red[x]<<endl;
        }
        else if(t==3){
            int j=f;
            while(j<x && j!=-1){
                // cout<<"j="<<j<<endl;
                int this_f=noti[j].f;
                int this_n=noti[j].n;
                if(noti[j].f!=-1)noti[this_f].n=this_n;
                else f=this_n;
                if(noti[j].n!=-1)noti[this_n].f=this_f;
                else e=this_f;
                noti[j].l=0;
                j=this_n;
                unr--;
            }
        }
        cout<<unr<<'\n';
        // d(f,e);
    }
    // cout<<"Af"<<endl;
    return 0;
}
