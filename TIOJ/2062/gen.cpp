#include<bits/stdc++.h>
using namespace std;

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
}

int nrand(){ 
    int r; do{
        r=rand();
    }while(r==RAND_MAX);
    return r;
}

int rrand(int l,int r){
    return (double)nrand()/RAND_MAX*(r-l+1)+l;
}

string file_in,file_out;
ofstream in,out;

int grp[2000006];
void gen(int n,int m){
    cout<<"gen: "<<n<<" "<<m<<endl;
    multiset<pair<int,int>> st;
    if(rand()&1)while(int(st.size())<m){
        int u,v;
        do{
            u=rrand(1,n);
            v=rrand(1,n);
        }while(u==v);
        st.insert({u,v});
    }
    else{
        bool a1=1,a0=1;
        while(a1 || a0)for(int i=1;i<=n;++i)grp[i]=rand()&1,a1&=grp[i],a0&=!grp[i];
        while(int(st.size())<m){
            int u,v;
            do{
                u=rrand(1,n);
                v=rrand(1,n);
            }while(grp[u]==grp[v]);
            st.insert({u,v});
        }
    }
    in<<n<<" "<<m<<'\n';
    vector<pair<int,int>> v;
    for(auto p:st)v.push_back(p);
    random_shuffle(v.begin(),v.end());
    for(auto p:v)in<<p.first<<" "<<p.second<<'\n';
    in.close();
    exec(("./sol < "+file_in+" > "+file_out).c_str());
}

void makefile(int x){
    stringstream ss; ss<<x;
    string s; ss>>s;
    file_in=s+".in";
    file_out=s+".out";
    cout<<file_in<<" "<<file_out<<endl;
    if(in.is_open())in.close();
    in.open(file_in);
    // if(out.is_open())out.close();
    // out.open(file_out);
}

void gen(int N,int l,int r){
    for(int i=l;i<=r;++i){
        makefile(i);
        int n=N-rrand(0,min(N-1,100));
        n=max(1,n);
        if(rand()%3){ // dense
            int maxm=min(1ll*n*(n-1)/2,2000000ll);
            gen(n,rrand(max(0,maxm-rrand(1,maxm/100)),min((int)min(1ll*n*(n-1)/2,2000000ll),maxm+rrand(1,maxm/100))));
        }
        else{
            int maxm=n;
            gen(n,rrand(max(0,maxm-rrand(1,maxm/100)),min((int)min(1ll*n*(n-1)/2,2000000ll),maxm+rrand(1,maxm/100))));
        }
    }
}

int main(){
    cout<<"testset: "; fflush(stdout);
    int ts; cin>>ts; switch(ts){
        case 1: gen(10,0,17); break;
        case 2: gen(20,18,27); break;
        case 3: gen(3000,28,42); break;
        case 4: gen(1000000,43,59); break;
    }
}
