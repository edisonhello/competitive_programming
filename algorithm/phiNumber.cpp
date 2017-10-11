namespace phiNumber{
#define maxn 0
#include<bitset>
#include<vector>
    std::bitset<maxn> notprime;
    std::vector<int> prime;
    std::vector<int> _phi(maxn+5);
    void init(){
        _phi[1]=1;
        for(int i=2;i<maxn;++i){
            if(!notprime[i])_phi[i]=i-1,prime.push_back(i);
            for(int j=0;i*prime[j]<maxn;++j){
                notprime[i*prime[j]]=1;
                if(i%prime[j]==0){
                    _phi[i*prime[j]]=_phi[i]*prime[j];
                    break;
                }
                else _phi[i*prime[j]]=_phi[i]*(prime[j]-1);
            }
        }
    }
    int phi(const int n){return _phi[n];}
#undef maxn
}
