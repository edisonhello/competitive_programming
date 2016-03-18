#include <bits/stdc++.h>

using namespace std;

int main(){
	string a,b;
	cin>>a>>b;

	vector<string> moreB;

	for(int i=0; i<b.length();i++){
        string tmp = b;
        tmp.assign(tmp,tmp.length()-1-i,tmp.length());
        moreB.push_back(tmp);
	}

	for(int i=moreB.size()-1;i>=0;i--){
        if(a.find(moreB[i])<654654){
            cout<<moreB[i].length()<<endl;
            return 0;
        }
	}
	cout<<0<<endl;
}
