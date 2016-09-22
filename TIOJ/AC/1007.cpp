#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long

ull rec[100];

int n,m;
int main(){
	cin>>n>>m;m++;n++;
	memset(rec,0,sizeof(rec));
    rec[0]=1;
	rec[1]=1;
	/*if(n==1)rec[2]=3;
	if(n==2)rec[2]=4;*/

    for(int i=2;i<=m;i++){

        for(int j=1;j<=n;j++){
            if(i-j<0)break;
            else{
                rec[i] += rec[i-j];
            }
        }
    }


	//int res = dp(m);

//for(int i=1;i<10;i++)cout<<rec[i]<" ";//

	cout<<rec[m]<<endl;
}
