#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b){
	while(a != 0 && b != 0){
		int abmin = min(a,b);
		int abmax = max(a,b);

		int t = abmax / abmin;
		abmax -= abmin * t;
		a = abmax;
		b = abmin;
	}

	return a == 0 ? b : a;
}

int main()
{
	ios_base::sync_with_stdio(0);

	int times;
	cin>>times;

	for(int i = 1;i <= times;i++){
		int a,b;
		cin>>a>>b;
		cout<<gcd(a,b)<<endl;;
	}
}
