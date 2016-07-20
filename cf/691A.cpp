#include<vector>
#include<iostream>

using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second
inline int rit(){
    int t=0,k=1;
    char c;
    do{
        c=getchar();
        if(c=='-')k=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n=rit();

if(n==1){
    int t=rit();
    if(t)cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}

    vint a;
    a.rz(n);
    bool get0 = false;

    for(int i=0;i<n;i++){
        a[i] = rit();
        if(a[i]==0){
            // if(i==n-1){
            //     cout<<"NO\n";
            //     return 0;
            // }

            if(get0){
                cout<<"NO\n";
                // for(int i=0;i<n;i++)cout<<a[i]<<" ";
                return 0;
            }
            else{
                // cout<<i<<endl;
                get0 = 1;
            }
        }
    }


    if(get0)cout<<"YES\n";
    else cout<<"NO\n";
}
