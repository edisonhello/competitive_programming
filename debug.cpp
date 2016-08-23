#include<iostream>
#include<sstream>
#include<cstring>

using namespace std;
int arr[1000010];
int main()
{
	string line;
	while(getline(cin,line)){
		int count=0;
		int x=0,y=0;
		int w=0;
		int e=1;
		memset(arr,0,sizeof(arr));
		for(int i=0;i<(int)line.size();i++){
			if(line[i]=='/'){
				line[i]=' ';
				e=1;
				for(int j=1;j<=i;j++){
					if(line[i-j]==' ')break;
					else{
						x+=(line[i-j]-'0')*e;
						line[i-j]=' ';
						e*=10;
					}
				}
				for(int j=1;j<=(int)line.size()-i-1;j++){
					if(line[i+j]==' ')break;
					else{
						y*=10;
						y+=line[i+j]-'0';
						line[i+j]=' ';
					}
				}
				if(x%y==0){
					arr[w]=x/y;
					w++;
				}
				x=y=0;
			}
		}
		istringstream in(line);
		long long d;
		while(in>>d){
			count+=(d);
	    }
	    for(int i=0;arr[i]!=0;i++){
	    	count+=(arr[i]);
		}
		cout<<count<<endl;
		count=0;
		w=0;
	}
}
