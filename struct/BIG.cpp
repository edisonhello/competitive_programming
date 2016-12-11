#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct BIG;
BIG _10pow(int);

struct BIG{
	int n[555];
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

	bool operator<(BIG const &a){
		if(a.length!=this->length)return this->length<a.length;
		for(int i=a.length-1;i>=0;i--){
			if(a.n[i]!=this->n[i])return this->n[i]<a.n[i];
		}
		return false;
	}
	bool operator<=(BIG const &a){
		if(a.length!=this->length)return this->length<=a.length;
		for(int i=a.length-1;i>=0;i--){
			if(a.n[i]!=this->n[i])return this->n[i]<=a.n[i];
		}
		return true;
	}

	bool operator>(BIG const &a){
		return !(*this<=a);
	}
    bool operator>=(BIG const &a){
		return !(*this<a);
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
    friend BIG operator+(BIG const &a,int bi){
        BIG b(bi);
		return a+b;
	}
	friend BIG operator+(int bi,BIG const &a){
        BIG b(bi);
		return a+b;
	}
	BIG& operator++(){
		this->n[0]++;
		for(int i=0;i<this->length;i++){
			if(n[i]>9){
				n[i+1]+=n[i]/10;
				n[i]%=10;
			}
			else{
				break;
			}
		}
		return *this;
	}
	BIG& operator++(int){
		BIG tmp(*this);
		operator++();
		return tmp;
	}


	friend BIG operator-(BIG &a,BIG &b){
		BIG t=a;
		if(b>a){
			printf("Wtf are you doing?\n");
			return 0;
		}
		for(int i=0;i<b.length;i++){
			t.n[i]-=b.n[i];
		}
		for(int i=0;i<t.length-1;i++){
			if(t.n[i]<0){
				t.n[i+1]+=((t.n[i]+1)/10-1);
				t.n[i]%=10;
				if(t.n[i])t.n[i]+=10;
			}
		}
		int i;
		for(i=t.length-1;i>=0;i--){
			if(t.n[i])break;
		}
		t.length=i+1;
		return t;
	}
    BIG operator-(int b){
		BIG t;
		int i=0;
		t.n[0]-=b;
		for(;;i++){
			t.n[i]+=this->n[i];
			if(t.n[i]==0)break;
			if(t.n[i]<0){
				t.n[i+1]+=((t.n[i]+1)/10-1);
				t.n[i]%=10;
				if(t.n[i])t.n[i]+=10;
			}
		}
		t.length=i;
		return t;
	}

	friend BIG operator*(BIG const &a,BIG const &b){
		BIG t;
		int mxl=a.length+b.length;
		for(int i=0;i<a.length;i++){
			for(int j=0;j<b.length;j++){
				t.n[i+j]+=a.n[i]*b.n[j];
			}
		}
		for(int i=0;i<mxl+1;i++){
			t.n[i+1]+=t.n[i]/10;
			t.n[i]%=10;
		}
		int i;
		for(i=mxl+1;i>=0;i--){
			if(t.n[i])break;
		}
		t.length=i+1;
		return t;
	}
	friend BIG operator*(BIG const &a,int const &bi){
		BIG b(bi);
		return a*b;
	}
	friend BIG operator*(BIG const &a,long const &bi){
		BIG b(bi);
		return a*b;
	}
	friend BIG operator*(BIG const &a,ll const &bi){
		BIG b(bi);
		return a*b;
	}
	friend BIG operator*(int const &bi,BIG const &a){
		BIG b(bi);
		return a*b;
	}
	friend BIG operator*(long const &bi,BIG const &a){
		BIG b(bi);
		return a*b;
	}
	friend BIG operator*(ll const &bi,BIG const &a){
		BIG b(bi);
		return a*b;
	}

	friend BIG operator/(BIG a,BIG &b){
		BIG t;
		int mxl=a.length-b.length+1;
		while(a>=b){
			int _l=a.length-b.length;
            nodid:
			if(a<b)break;
			int k=1;
			while(k*b*_10pow(_l)<=a){
				k++;
			}
			t.n[_l]+=k-1;
            BIG tt = b*_10pow(_l)*(k-1);
            if(tt.length==0){
                _l--;
                goto nodid;
            }
			a=a-tt;
		}
		for(int i=0;i<mxl+2;i++){
			t.n[i+1]+=t.n[i]/10;
			t.n[i]%=10;
		}
		int i;
		for(i=mxl+4;i>=0;i--){
			if(t.n[i])break;
		}
		t.length=i+1;
		return t;
	}
};

BIG _10pow(int l){
	BIG t;
	t.n[l]=1;
	t.length=l+1;
	return t;
}

int main(){

}
