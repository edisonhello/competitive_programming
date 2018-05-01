#include<iostream>
#include<fstream>
#include<cstdlib>
#include<sstream>

using namespace std;

void AC(){ cout<<0<<endl; exit(0); }
void WA(){ cout<<-1<<endl; exit(0); }

int a[10005],u[10005];

int main(int argc, char **argv) {
    filebuf f_user,f_in,f_out;
    f_user.open(argv[1],ios::in);
    f_in.open(argv[2],ios::in);
    f_out.open(argv[3],ios::in);

    istream user(&f_user),in(&f_in),out(&f_out);

    int p,k,n; in>>p>>k>>n;

    int ans; out>>ans;
    if(ans==-1){
        int uans; user>>uans;
        if(uans==-1)AC();
        else WA();
    }
    
    for(int i=1;i<=p;++i)in>>a[i];
    for(int i=1;i<=k;++i){
        string s; getline(user,s);
        if(s.empty())WA();
        int z1,z2,z3,z4;
        stringstream ss(s);
        if(!(ss>>z1>>z2))WA();
        int tot=0;
        tot+=z2;
        u[z1]+=z2;
        if(tot!=n){
            if(!(ss>>z3>>z4))WA();
            tot+=z4;
            u[z3]+=z4;
        }
        if(tot!=n)WA();
    }
    for(int i=1;i<=p;++i)if(a[i]!=u[i])WA();
    AC();
}

