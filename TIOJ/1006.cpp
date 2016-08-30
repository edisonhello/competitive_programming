#include<bits/stdc++.h>

using namespace std;

struct BIG{
	int n[55];
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

	BIG operator+(int b){
		BIG t;
		int i=0;
		t.n[0]+=b;
		for(;;i++){
			t.n[i]+=this->n[i];
			if(!t.n[i])break;
			if(t.n[i]>9){
				t.n[i+1]+=t.n[i]/10;
				t.n[i]%=10;
			}
		}
		t.length=i;
		return t;
	}
	// BIG operator+(int b,BIG const &a){
	// 	BIG t;
	// 	int i=0;
	// 	t.n[0]+=b;
	// 	for(;;i++){
	// 		t.n[i]+=a.n[i];
	// 		if(!t.n[i])break;
	// 		if(t.n[i]>9){
	// 			t.n[i+1]+=t.n[i]/10;
	// 			t.n[i]%=10;
	// 		}
	// 	}
	// 	t.length=i;
	// 	return t;
	// }

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
string as,bs;



void div(){

}

int main(){
	cin>>a;
	cout<<9898+a<<endl;
}
