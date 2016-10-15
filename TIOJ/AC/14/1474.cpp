#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define S(x) (int)(x).size()
#define PB(x) push_back(x)
#define pii pair<int,int>
#define vint vector<int>
#define rz(x) reserve(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define PVC(x) for(auto ___:(x))cout<<___<<" ";cout<<endl;
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

int n,mxa;
vint cub[55];

vint ROT(vint va){
    vint t;
    for(int i=1;i<S(va)-1;++i){
        if((va[i-1]-va[i])*(va[i]-va[i+1])<0)return t;
    }
    if(S(va)==1)return t;
    bool smaller=0;for(int i=0;i<S(va)-1;++i)if(va[i+1]!=va[i]){smaller=(va[i+1]<va[i]);break;}
    if(smaller){
        int nowh=va[0];
        for(int i=1;i<S(va);++i){
            if(va[i]<nowh){
                for(;nowh>va[i];nowh--){
                    t.PB(i);
                }
            }
        }
        for(;nowh>0;--nowh){
            t.PB(S(va));
        }
    }
    else{
        reverse(va.begin(),va.end()); // can optimize
        int nowh=va[0];
        for(int i=1;i<S(va);++i){
            if(va[i]<nowh){
                for(;nowh>va[i];--nowh){
                    t.PB(i);
                }
            }
        }
        for(;nowh>0;--nowh){
            t.PB(S(va));
        }
    }
    return t;
}

void sol(int a,int b){
    vint va=cub[a];
    vint vb=cub[b];
    vint rot=ROT(va);
    // PVC(va);PVC(vb);PVC(rot);
    {
        bool SW=0;
        if(S(va)>S(vb)){
            SW=1;
            swap(va,vb);
        }
        for(int mov=0;mov<=S(vb)-S(va);++mov){
            int hei=(mov==0?va[0]:0)+vb[0];
            for(int i=0;i<S(vb);++i){
                if((i-mov>=0 && i-mov<S(va)?va[i-mov]:0)+vb[i]!=hei){
                    goto cant1;
                }
            }
            mxa=max(mxa,hei*S(vb));
            cant1:;
        }
        reverse(va.begin(),va.end());
        for(int mov=0;mov<=S(vb)-S(va);++mov){
            int hei=(mov==0?va[0]:0)+vb[0];
            for(int i=0;i<S(vb);++i){
                if((i-mov>=0 && i-mov<S(va)?va[i-mov]:0)+vb[i]!=hei){
                    goto cant2;
                }
            }
            mxa=max(mxa,hei*S(vb));
            cant2:;
        }
        if(SW)swap(va,vb);
    }
    if(S(rot)){
        va=rot;
        if(S(va)>S(vb))swap(va,vb);
        // cout<<endl;PVC(va);PVC(vb);
        for(int mov=0;mov<=S(vb)-S(va);++mov){
            // cout<<"mov:"<<mov;
            int hei=(mov==0?va[0]:0)+vb[0];
            // cout<<" ,hei="<<hei<<endl;
            for(int i=0;i<S(vb);++i){
                // cout<<"i:"<<i<<" "<<(i-mov>=0 && i-mov<S(va)?va[i-mov]:0)<<"+"<<vb[i]<<endl;
                if((i-mov>=0 && i-mov<S(va)?va[i-mov]:0)+vb[i]!=hei){
                    goto cant3;
                }
            }
            mxa=max(mxa,hei*S(vb));
            cant3:;
        }
        reverse(va.begin(),va.end());
        for(int mov=0;mov<=S(vb)-S(va);++mov){
            int hei=(mov==0?va[0]:0)+vb[0];
            for(int i=0;i<S(vb);++i){
                if((i-mov>=0 && i-mov<S(va)?va[i-mov]:0)+vb[i]!=hei){
                    goto cant4;
                }
            }
            mxa=max(mxa,hei*S(vb));
            cant4:;
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    string s;
    getline(cin,s);
    stringstream ss;
    for(int i=0,t;i<n;++i){
        getline(cin,s);
        ss.clear();
        ss<<s;
        while(ss>>t){
            cub[i].PB(t);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            sol(i,j);
        }
    }
    cout<<mxa<<endl;
}
