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
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define SS stringstream
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
// #define getchar getchar_unlocked
// #define putchar putchar_unlocked
#define PVC(x) for(auto ___:(x))cout<<___<<" ";cout<<endl;
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;


struct BIG{
    int length,n[12345];
    BIG(){
        MS0(this->n);
        this->length=0;
    }
    BIG(int a){
        MS0(this->n);
        this->length=0;
        while(a){
            this->n[this->length++]=a%10;
            a/=10;
        }
    }
    void kill0(){
        int i=this->length;
        for(;i>=0;--i){
            if(this->n[i]!=0)break;
        }
        this->length=i+1;
    }

    friend ostream& operator<<(ostream &ostm,BIG a){
        if(a.length==0){
            ostm<<0;
        }
        else{
    		for(int i=a.length-1;i>=0;i--){
    			ostm<<a.n[i];
    		}
        }
		return ostm;
	}

    BIG& operator = (const int &a){
        this->n[0]=a;
        int i=0;
        for(;;++i){
            if(this->n[i]<10)break;
            this->n[i+1]+=this->n[i]/10;
            this->n[i]%=10;
        }
        this->length=i+1;
        return *this;
    }

    BIG& operator *= (const int &a){
        int i=0;
        this->n[0]*=a;
        for(i=0;i<(this->length+15);++i){
            this->n[i+1]*=a;
            this->n[i+1]+=this->n[i]/10;
            this->n[i]%=10;
        }
        this->length=i+1;
        this->kill0();
        return *this;
    }

    BIG& operator += (const BIG &a){
        for(int i=0;i<max(this->length,a.length);++i){
            this->n[i]+=a.n[i];
            if(this->n[i]>9){
                this->n[i+1]+=this->n[i]/10;
                this->n[i]%=10;
            }
        }
        this->length=max(this->length,a.length);
        while(this->n[this->length]){
            ++this->length;
        }
        return *this;
    }

    BIG operator * (const int &a){
        int i=0;
        BIG t(*this);
        t.n[0]*=a;
        for(i=0;i<(t.length+15);++i){
            t.n[i+1]*=a;
            t.n[i+1]+=t.n[i]/10;
            t.n[i]%=10;
        }
        t.length=i+1;
        t.kill0();
        return t;
    }
};

int n;
BIG ans;
BIG _pow;

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    _pow=n;
    for(int i=1;i<=n;++i){
        ans+=_pow*i;
        _pow*=(n-i);
    }
    cout<<ans<<'\n';
}
