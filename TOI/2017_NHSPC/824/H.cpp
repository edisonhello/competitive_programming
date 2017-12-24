#include<bits/stdc++.h>
using namespace std;
#define ld long double

const ld pi=acos((ld)-1);
pair<ld,int> a[22];
ld iu[22],x[22],y[22];
bool use[22];
int n,k;

bool too_big(){
    ld sum=0;
    for(int i=1;i<k;++i)sum+=iu[i];
    if(iu[0]-sum>1e-5)return 1;
    return 0;
}

ld getdeg(ld r,ld len){
    // cout<<"get asin of "<<len/2/r <<" is "<<asin(len/2/r)<<endl;
    if(abs(r-len/2)<1e-8)return pi;
    return asin(len/2/r)*2;
}
ld cntdeg(ld r,int k){
    ld tot=0;
    for(int i=0;i<k;++i){
        tot+=getdeg(r,iu[i]);
    }
    // cout<<"when r: "<<r<<" , tot: "<<tot<<endl;
    return tot;
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>a[i].first,a[i].second=i+1;
    sort(a,a+n);
    for(int i=0;i<k;++i)use[i]=1;
    sort(use,use+n);
    do{
        for(int i=0,ptr=0;i<n;++i)if(use[i])iu[ptr++]=a[i].first;
        sort(iu,iu+k); reverse(iu,iu+k);
        // cout<<"b4 tb"<<endl;
        if(too_big())continue;
        // cout<<"af tb"<<endl;
        ld L=iu[0]/2,R=4e4;
        while(R-L>1e-12){
            ld M=(L+R)/2;
            if(cntdeg(M,k)>pi*2)L=M;
            else R=M;
        }
        // cout<<"L: "<<L<<endl;
        // cout<<"cntdeg: "<<cntdeg(L,k)<<endl;
        // for(int i=0;i<k;++i)cout<<"for edge "<<a[i]<<" deg is "<<getdeg(L,iu[i])<<endl;
        // cout<<"delta: "<<fixed<<setprecision(10)<<abs(cntdeg(L,k)-pi*2)<<endl;
        if(abs(cntdeg(L,k)-pi*2)<1e-4 || true){
            ld r=L,nowx=L,nowy=0,nowdeg=0;
            x[0]=r,y[0]=0;
            for(int i=1;i<k;++i){
                nowdeg+=getdeg(r,iu[i]);
                x[i]=r*cos(nowdeg);
                y[i]=r*sin(nowdeg);
            }
            reverse(x+1,x+k); reverse(y+1,y+k);
            for(int i=0;i<k;++i){
                cout<<fixed<<setprecision(6)<<x[i]<<" "<<y[i]<<endl;
            }
            bitset<22> u;
#define gdis(a,b) sqrt((a)*(a)+(b)*(b))
            int countout=0;
            for(int i=1;i<k;++i){
                ld dis=gdis(x[i]-x[i-1],y[i]-y[i-1]);
                // cout<<"dis is "<<fixed<<setprecision(10)<<dis<<endl;
                ld eps=1e-6; bool find=0;
again1:;
                for(int j=0;j<n;++j)if(!u[j] && abs(a[j].first-dis)<eps){
                    cout<<a[j].second<<" ";
                    ++countout;
                    u[j]=1;
                    find=1;
                    break;
                }
                if(!find){
                    eps*=10;
                    goto again1;
                }
            }
            ld dis=gdis(x[k-1]-x[0],y[k-1]-y[0]);
            // cout<<fixed<<setprecision(12)<<abs(a[3]-dis)<<endl;
            // cout<<"dis is "<<fixed<<setprecision(10)<<dis<<endl;
            ld eps=1e-6; bool find=0;
again2:;
            for(int j=0;j<n;++j)if(!u[j] && abs(a[j].first-dis)<eps){
                cout<<a[j].second<<endl;
                ++countout;
                u[j]=1;
                find=1;
                break;
            }
            if(!find){
                eps*=10;
                goto again2;
            }
            assert(countout==k);
            exit(0);
        }
    }while(next_permutation(use,use+n));
}

