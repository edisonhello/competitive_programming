#pragma GCC optimize("Ofast")
#include<cstdio>
#include<algorithm>
#include<utility>
#include<bitset>
#include<vector>
#include<queue>
using namespace std;
#define distance jjafio
#define ref sdifi
#define getchar getchar_unlocked

bitset<1000004> notPrime;
vector<int> prime;
inline void init(){
    notPrime[1]=1;
    for(int i=2;i<1000004;++i){
        if(notPrime[i])continue;
        prime.push_back(i);
        for(long long j=1ll*i*i;j<1000004;j+=i){
            notPrime[j]=1;
        }
    }
}
/* inline bool isPrime(int x){
    for(int i:prime){
        if(i*i>x)break;
        if(x%i==0)return 0;
    }
    return 1;
} */

int distance[1000006];
inline void primefactor(){
    queue<pair<int,pair<int,int>>> q;
    q.emplace(1,pair<int,int>{0,0});
    while(q.size()){
        distance[q.front().first]=q.front().second.first;
        for(int i=q.front().second.second;i<prime.size() && 1ll*q.front().first*prime[i]<=1000000;++i){
            q.emplace(q.front().first*prime[i],pair<int,int>{q.front().second.first+1,i});
        }
        q.pop();
    }
}

vector<int> factor_rem[1000006];
int ref_size[1000006];
pair<int,int> ref[1000006][3];
int a[100005],cntnumber[1000006];

pair<int,int> operator+(const pair<int,int> &p,int x){
    return {p.first+x,p.second};
}

void addRef(int val,int index,int step){
    int &size=ref_size[val];
    ref[val][size]={step,index}; ++size;
    sort(ref[val],ref[val]+size,[](const pair<int,int> &a,const pair<int,int> &b){return a.second==b.second?a.first<b.first:a.second<b.second;});
    if(size>1 && ref[val][1].second==ref[val][0].second)ref[val][1]=ref[val][2],--size;
    if(size>2 && ref[val][2].second==ref[val][1].second)size=2;
    if(size>2)sort(ref[val],ref[val]+size),size=2;
}
pair<int,int> query(int val,int index){
    if(ref_size[val]==0)return {99999,0};
    if(ref[val][0].second==index){
        if(ref_size[val]==1)return {99999,0};
        else return ref[val][1];
    }
    else return ref[val][0];
}

inline int rit(){
    register int x=0; register char c=0;
    while(c=getchar())if(c>='0' && c<='9')break;
    do x=x*10+(c&15),c=getchar(); while(c>='0' && c<='9');
    return x;
}

int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    // for(int i=1007;i<1000000;i+=2)if(isPrime(i))prime.push_back(i);
    primefactor();
    int n=rit();
    for(int i=1;i<=n;++i)a[i]=rit();
    for(int i=1;i<=n;++i){
        ++cntnumber[a[i]];
        if(a[i]>1 && factor_rem[a[i]].empty())for(int j=1,jz;j*j<=a[i];++j){
            if(a[i]%j)continue;
            jz=a[i]/j;
            addRef(j,i,distance[jz]);
            addRef(jz,i,distance[j]);
            factor_rem[a[i]].push_back(j);
        }
        else if(factor_rem[a[i]].size() && cntnumber[a[i]]<=2)for(int &j:factor_rem[a[i]]){
            int jz=a[i]/j;
            addRef(j,i,distance[jz]);
            addRef(jz,i,distance[j]);
        }
        else if(a[i]==1)addRef(1,i,0);
        else ;
        /* for(int j:prime){
            if(a[i]*j>1000000)break;
            addRef(a[i]*j,i,1);
        } */
    }
    for(int i=1;i<=n;++i){
        pair<int,int> ans={99999,0};
        if(a[i]>1)for(int &j:factor_rem[a[i]]){
            int jz=a[i]/j;
            ans=min(ans,min(query(j,i)+distance[jz],query(jz,i)+distance[j]));
        }
        else ans=query(1,i);
        /* for(int j:prime){
            if(a[i]*j>1000000)break;
            ans=min(ans,query(a[i]*j,i)+1);
        } */
        printf("%d\n",ans.second);
    }
}
