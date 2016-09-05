#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second

int t;
double x,y,r,xx,yy,rr,dis,ans;
double pi=acos(-1);

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);

	cin>>t;
	for(int i=0;i<t;i++){
		// memset(&ans,0,sizeof(ans));
		ans=0;
		// cout<<ans<<endl;
		cin>>x>>y>>r>>xx>>yy>>rr;
		dis=sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
		if(dis>=r+rr){
			printf("0.00\n");
			continue;
		}
		if(dis<=abs(r-rr)){
			printf("%.2lf\n",pi*min(r,rr)*min(r,rr));
			continue;
		}
		// cout<<ans<<endl;
		double costheta=(r*r+dis*dis-rr*rr)/(2*r*dis);
		// cout<<"costheta="<<costheta<<endl;
		double theta=acos(costheta);
		// cout<<"theta="<<theta<<endl;
		ans+=r*r*theta;
		// cout<<"r*r*theta = "<<r*r*theta<<endl;
		ans-=r*r*sin(2*theta)/2;
		// cout<<"r*r*sin(2*theta)/2 = "<<r*r*sin(2*theta)/2<<endl;
		// cout<<"now ans="<<ans<<endl;
		double costhetaa=(rr*rr+dis*dis-r*r)/(2*rr*dis);
		// cout<<"costhetaa="<<costhetaa<<endl;
		double thetaa=acos(costhetaa);
		// cout<<"thetaa="<<thetaa<<endl;
		ans+=rr*rr*thetaa;
		// cout<<"rr*rr*thetaa = "<<rr*rr*thetaa<<endl;
		ans-=rr*rr*sin(2*thetaa)/2;
		// cout<<"rr*rr*sin(2*thetaa)/2 = "<<rr*rr*sin(2*thetaa)/2<<endl;
		// printf("%.2lf\n",ans);
		// cout<<ans<<endl;
		printf("%.2lf\n",ans);
	}
}
