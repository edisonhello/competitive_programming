#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
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
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;
struct BIG;
BIG _10pow(int);

struct BIG{
	int n[300];
	int length;
	BIG(){
		memset(n,0,sizeof(n));
		length = 0;
	}
    BIG(int in){
		memset(n,0,sizeof(n));
		length = 0;
        int ptr=0;
        while(in){
            this->n[ptr++]=in%10;
            in/=10;
        }
        this->length=ptr;
    }
    BIG(long in){
		memset(n,0,sizeof(n));
		length = 0;
        int ptr=0;
        while(in){
            this->n[ptr++]=in%10;
            in/=10;
        }
        this->length=ptr;
    }
    BIG(ll in){
		memset(n,0,sizeof(n));
		length = 0;
        int ptr=0;
        while(in){
            this->n[ptr++]=in%10;
            in/=10;
        }
        this->length=ptr;
    }
    BIG(string s){
		memset(n,0,sizeof(n));
		length = 0;
        int i;
        for(i=0;i<(int)s.length();i++){
            if(s[i]>'9'||s[i]<'0'){
                printf("WTF are you input?\n");
                break;
            }
            this->n[i]=s[s.length()-1-i]-'0';
        }
        this->length=i;
    }

    void kill0(BIG &t){
        t.length;
        while(t.n[t.length-1]==0){
            t.length--;
        }
        return;
    }

    void operator=(string const &s){
        stringstream ss;
        ss<<s;
        ss>>*this;
        return;
    }
	void operator=(BIG const &big){
        this->length=big.length;
		for(int i=0;i<this->length;i++){
			this->n[i]=big.n[i];
		}
		return;
    }

    friend ostream &operator<<(ostream &ostm,BIG big){
		for(int i=big.length-1;i>=0;i--){
			ostm<<big.n[i];
		}
		// ostm<<" ("<<big.length<<")";
		if(big.length==0){
			ostm<<0;
		}
		return ostm;
	}
	friend istream &operator>>(istream &istm,BIG &big){
		memset(&big,0,sizeof(big));
		string s;
		istm>>s;
        int i;
		for(i=0;i<(int)s.length();i++){
            if(s[i]>'9'||s[i]<'0'){
                printf("WTF are you input?\n");
                break;
            }
			big.n[i]=s[s.length()-1-i]-'0';
		}
		big.length=i;
		// ostm<<" ("<<big.length<<")";
		return istm;
	}

	operator bool() const{
		return this->length;
	}

	friend BIG operator+(BIG const &a,int b){
		BIG t;
		int i=0;
		t.n[0]+=b;
		for(;i<max((int)a.length,15)+5;i++){
			t.n[i]+=a.n[i];
			// if(!t.n[i])break;
			if(t.n[i]>9){
				t.n[i+1]+=t.n[i]/10;
				t.n[i]%=10;
			}
		}
		t.length=i;
        t.kill0(t);
		return t;
	}
	friend BIG operator+(int b,BIG const &a){
		BIG t;
		int i=0;
		t.n[0]+=b;
		for(;i<max((int)a.length,15)+5;i++){
			t.n[i]+=a.n[i];
			// if(!t.n[i])break;
			if(t.n[i]>9){
				t.n[i+1]+=t.n[i]/10;
				t.n[i]%=10;
			}
		}
		t.length=i;
        t.kill0(t);
		return t;
	}
	friend BIG operator+(BIG const &a,BIG const &b){
		BIG t;
		int i=0;
		for(;i<max((int)a.length,(int)b.length)+5;i++){
			t.n[i]+=(a.n[i]+b.n[i]);
			// if(!t.n[i])break;
			if(t.n[i]>9){
				t.n[i+1]+=t.n[i]/10;
				t.n[i]%=10;
			}
		}
		t.length=i;
        t.kill0(t);
		return t;
	}
};
int m,n;
BIG f[102][102];
bool dan[102][102];

int main(){
    // cin.tie(0);
    ios_base::sync_with_stdio(0);
    // BIG a=460,b=190;
    // cout<<a<<" "<<b<<" "<<a+b<<endl;
    int ts;cin>>ts;while(ts--){
        MS0(f);
        MS0(dan);
        cin>>n>>m;
        cin.ignore();
        string s;
        for(int i=1;i<=n;i++){
            getline(cin,s);
            stringstream ss(s);
            int t;ss>>t;
            while(ss>>t){
                dan[i][t]=1;
            }
        }
        f[0][1]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(dan[i][j])continue;
                f[i][j]=f[i-1][j]+f[i][j-1];
                // cout<<f[i][j]<<"  ";
            }
            // cout<<endl;
        }
        cout<<f[n][m]<<endl;
        if(ts)cout<<endl;
    }
}
