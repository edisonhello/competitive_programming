#include<bits/stdc++.h>

using namespace std;

struct BIG{
	int n[1234];
	int length;
	BIG(){
		memset(n,0,sizeof(n));
		length = 0;
	}

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
		for(int i=0;i<(int)s.length();i++){
			big.n[i]=s[s.length()-1-i]-'0';
		}
		big.length=s.length();
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
};

BIG a,b,c;

void div(){

}

int main(){
	cin>>a>>b;
	cout<<b+a<<endl;
}

map<string,int> m;
void init(){
	int cnt=1;
	for(int a=0;a<26;a++){
		string s;
		s.push(a+'a');
		m[s]=cnt;
		cnt++;
	}
	for(int a=0;a<26;a++){
		for(int b=a+1;b<26;b++){

		}
	}
	for(int a=0;a<26;a++){
		for(int b=a+1;b<26;b++){
			for(int c=b+1;c<26;c++){

			}
		}
	}
	for(int a=0;a<26;a++){
		for(int b=a+1;b<26;b++){
			for(int c=b+1;c<26;c++){
				for(int d=c+1;d<26;d++){

				}
			}
		}
	}
	for(int a=0;a<26;a++){
		for(int b=a+1;b<26;b++){
			for(int c=b+1;c<26;c++){
				for(int d=c+1;d<26;d++){
					for(int e=d+1;e<26;e++){

					}
				}
			}
		}
	}
}
