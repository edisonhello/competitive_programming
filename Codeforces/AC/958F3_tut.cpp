#include<bits/stdc++.h>
using namespace std;
#define cplx complex<double>

cplx a[524288],b[524288],r[524288],o[524289];

void fft(cplx *x,int n,int base){
    int size=0,mask=(n>>1)-1;
    for(int i=base-1;i>=0;--i,size=(size<<1)|1,mask>>=1){
        for(int j=0;j<n;++j){
            int front=j>>i,back=j&mask;
            int a=(front&size)<<1,b=a|1;
            r[j]=x[(a<<i)|back]+o[(front<<i)*(524288/n)]*x[(b<<i)|back];
        }
        for(int j=0;j<n;++j)x[j]=r[j];
    }
}
void ifft(cplx *x,int n,int base){
    fft(x,n,base);
    reverse(x+1,x+n);
    for(int i=0;i<n;++i)x[i]/=n;
}

void pin(vector<int> *v){
    cout<<v->size()<<" :";
    for(int i:*v)cout<<i<<" ";
    cout<<endl;
}

vector<int>* mg(vector<int>* pa,vector<int>* pb){
    // pin(pa); pin(pb);

    int nn=pa->size()+pb->size()+2,base=0;
    while((1<<base)<nn)++base;
    nn=(1<<base);

    for(int i=0;i<pa->size();++i)a[i]=cplx((*pa)[i],0);
    for(int i=pa->size();i<=nn;++i)a[i]=cplx(0,0);
    for(int i=0;i<pb->size();++i)b[i]=cplx((*pb)[i],0);
    for(int i=pb->size();i<=nn;++i)b[i]=cplx(0,0);
    fft(a,nn,base);
    fft(b,nn,base);
    for(int i=0;i<nn;++i)a[i]*=b[i];
    ifft(a,nn,base);

    vector<int> *rt=new vector<int>();
    for(int i=0;i<nn;++i)rt->push_back(((long long)(real(a[i])+0.5))%1009);
    while(rt->size() && rt->back()==0)rt->pop_back();

    delete pa;
    delete pb;

    // pin(rt);
    return rt;
}

int cnt[524288];
const double PI=acos(-1);

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<=524288;++i)o[i]=exp(2.*i*PI/524288*cplx(0,1));
    int n,m,k; cin>>n>>m>>k;
    while(n--){
        int t; cin>>t;
        ++cnt[t];
    }
    
    auto cmp=[&](const vector<int> *a,const vector<int> *b){return a->size()>b->size();};
    priority_queue<vector<int>*,vector<vector<int>*>,decltype(cmp)> pq(cmp);
    for(int i=1;i<=m;++i){
        if(cnt[i]==0)continue;
        vector<int> *v=new vector<int>();
        for(int j=0;j<=cnt[i];++j)v->push_back(1);
        pq.push(v);
    }
    while(pq.size()>1u){
        vector<int> *p1,*p2;
        p1=pq.top(); pq.pop();
        p2=pq.top(); pq.pop();
        pq.push(mg(p1,p2));
    }
    vector<int> *ans=pq.top();
    cout<<(ans->size()>k?(*ans)[k]:0)<<endl;
}
