#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct BIG{
	int n[1234];
	int length;
	BIG(){
		memset(n,0,sizeof(n));
		length = 0;
	}
    BIG(int in){
        int ptr=0;
        while(in){
            this->n[ptr++]=in%10;
            in/=10;
        }
        this->length=ptr;
    }
    BIG(long in){
        int ptr=0;
        while(in){
            this->n[ptr++]=in%10;
            in/=10;
        }
        this->length=ptr;
    }
    BIG(ll in){
        int ptr=0;
        while(in){
            this->n[ptr++]=in%10;
            in/=10;
        }
        this->length=ptr;
    }
    BIG(string s){
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

    /* friend void operator=(BIG const &a,string const &s){
        stringstream ss;
        ss<<s;
        ss>>a;
        return a;
    } */

	friend ostream &operator<<(ostream &ostm,BIG big){
		for(int i=big.length-1;i>=0;i--){
			ostm<<big.n[i];
		}
		// ostm<<" ("<<big.length<<")";
		return ostm;
	}
	friend istream &operator>>(istream &istm,BIG &big){
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

	bool operator<(BIG const &a){
		if(a.length!=this->length)return this->length<a.length;
		for(int i=a.length-1;i>=0;i--){
			if(a.n[i]!=this->n[i])return this->n[i]<a.n[i];
		}
		return false;
	}

	bool operator>(BIG const &a){
		return !(*this<a);
	}

	friend BIG operator+(BIG const &a,int b){
		BIG t;
		int i=0;
		t.n[0]+=b;
		for(;;i++){
			t.n[i]+=a.n[i];
			if(!t.n[i])break;
			if(t.n[i]>9){
				t.n[i+1]+=t.n[i]/10;
				t.n[i]%=10;
			}
		}
		t.length=i;
		return t;
	}
	friend BIG operator+(int b,BIG const &a){
		BIG t;
		int i=0;
		t.n[0]+=b;
		for(;;i++){
			t.n[i]+=a.n[i];
			if(!t.n[i])break;
			if(t.n[i]>9){
				t.n[i+1]+=t.n[i]/10;
				t.n[i]%=10;
			}
		}
		t.length=i;
		return t;
	}
	friend BIG operator+(BIG const &a,BIG const &b){
		BIG t;
		int i=0;
		for(;;i++){
			t.n[i]+=(a.n[i]+b.n[i]);
			if(!t.n[i])break;
			if(t.n[i]>9){
				t.n[i+1]+=t.n[i]/10;
				t.n[i]%=10;
			}
		}
		t.length=i;
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
				// cout<<t.n[i]/10<<endl;
				t.n[i]%=10;
				if(t.n[i])t.n[i]+=10;
			}
		}
		t.length=i;
		return t;
	}
	/* friend BIG operator-(BIG const &a,BIG const &b){
		BIG t;
		int i=0;
		t.n[0]-=b;
		for(;;i++){
			t.n[i]+=this->n[i];
			if(t.n[i]==0)break;
			if(t.n[i]<0){
				t.n[i+1]+=((t.n[i]+1)/10-1);
				// cout<<t.n[i]/10<<endl;
				t.n[i]%=10;
				if(t.n[i])t.n[i]+=10;
			}
		}
		t.length=i;
		return t;
	} */
};

BIG a,b,c;

void div(){

}

int main(){
    b=99898989898;
    cout<<b<<endl;
}
