#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define X first
#define Y second
#define S(x) (int)(x).size()
#define rz(x) reserve(x)
#define PB(x) push_back(x)
#define pii pair<int,int>
#define vint vector<int>

#define DE cout<<"de"<<endl;
#define SS stringstream

#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))

#define PVC(x) for(auto ___:(x))cout<<___<<" ";cout<<endl;
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

struct martix{
    int f[33][33],x,y;
    martix(){
        MS0(f);
        x=y=0;
    }
    martix(string s){
        MS0(f);
        x=y=0;
        SS ss(s);
        string tmp;
        int i=0,j=0;
        while(ss>>tmp && tmp!="]"){
            if(tmp==";"){
                ++i,j=0;
            }
            else{
                SS sss(tmp);int t;sss>>t;
                this->f[i][j]=t;
                ++j;
            }
        }
        this->x=i+1,this->y=j;
    }
    friend ostream& operator<<(ostream& os,const martix &a){
        os<<"[ ";
        for(int i=0;i<a.x;++i){
            if(i)os<<"; ";
            for(int j=0;j<a.y;++j){
                os<<a.f[i][j]<<" ";
            }
        }
        os<<"]";
        return os;
    }
    martix& operator=(const martix &a){
        for(int i=0;i<a.x;++i){
            for(int j=0;j<a.y;++j){
                this->f[i][j]=a.f[i][j];
            }
        }
        this->x=a.x;
        this->y=a.y;
        return *this;
    }
    martix operator+(const martix &a){
        martix t(*this);
        for(int i=0;i<t.x;++i){
            for(int j=0;j<t.y;++j){
                t.f[i][j]+=a.f[i][j];
            }
        }
        return t;
    }
    martix operator-(const martix &a){
        martix t(*this);
        for(int i=0;i<t.x;++i){
            for(int j=0;j<t.y;++j){
                t.f[i][j]-=a.f[i][j];
            }
        }
        return t;
    }
    martix operator*(const martix &a){
        martix t;
        for(int i=0;i<this->x;++i){
            for(int j=0;j<a.y;++j){
                for(int k=0;k<a.x;++k){
                    t.f[i][j]+=this->f[i][k]*a.f[k][j];
                }
            }
        }
        t.x=this->x;
        t.y=a.y;
        return t;
    }
    martix operator*(const int &a){
        martix t(*this);
        for(int i=0;i<t.x;++i){
            for(int j=0;j<t.y;++j){
                t.f[i][j]*=al
            }
        }
        return t;
    }
    martix val(){

    }
    martix inv(){

    }
    martix operator/(const martix &a){

    }
};

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    martix a("1 2 3 ; 4 5 6]");
    martix b("7 8 9 ; 10 11 12 ; 13 14 15]");
    cout<<a*b<<endl;
}
