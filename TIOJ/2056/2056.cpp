#include<bits/stdc++.h>
using namespace std;

#include"lib2056.h"

int main(){
	int ts=Testcase(); while(ts--){
	    int n=Init();
	    for(int i=0;i<n;++i){
		    int now=i,prv;
	        do{
	            // cout<<"query "<<now<<" = ";
	            prv=now;
	            now=Query(now);
	            // cout<<now<<endl;
	        }while(now!=i);
	        // cout<<"Answer "<<now<<endl;
	        Answer(prv);
	    }
	}
}
