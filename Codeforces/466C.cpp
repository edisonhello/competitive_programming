#include<bits/stdc++.h>
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
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2

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
};

int n;
int a[500025];
int tot;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        tot+=a[i];
    }
    if(tot%3){
        cout<<0<<endl;
        return 0;
    }
    int dist=tot/3;

    int tot1=0;
    int ans=0;
    for(int i=0;i<n;i++){
        tot1+=a[i];
        if(tot1==dist){
            int tot2=0;
            for(int j=i+1;j<n;j++){
                tot2+=a[j];
                if(tot2==dist){
                    int tot3=0;
                    int k;
                    for(k=j+1;k<n;k++){
                        tot3+=a[k];
                    }
                    if(tot3==dist && k==n && j<n-1){
                        // cout<<i<<" "<<j<<" "<<k<<endl;
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}

/*2016/05/22*//*#include<bits/stdc++.h>
using namespace std;
int n,*ary;
int ans=0;
int l,r;
void go(){
    while(1){
        if(l>r){
            return ;
        }
        int lc=0,mc=0,rc=0;
        for(int i=0;i<l;i++){
            lc+=ary[i];
        }
        for(int i=l;i<r;i++){
            mc+=ary[i];
        }
        for(int i=r;i<n;i++){
            rc+=ary[i];
        }
        if(lc==mc && mc==rc){
            ans++;              printf("ans++ @ l%d r%d\n",l,r);
            int oril=l;
            int orir=r;
            r--;
            for(;ary[r]==0 && !(l>r+1);r--){
                for(;ary[l]==0 && !(l>r+1);l++){
                    ans++;      printf("ans++ @ l%d r%d\n",l,r);
                }
                l=oril;
            }
            for(;ary[l]==0&&!(l>r);l++){}
            continue;
        }
        if(lc>mc){
            r--;
        }
        else{
            l++;
        }
    }
}


int main(){
    cin>>n;
    ary=new int[n];
    for(int i=0;i<n;i++){
        cin>>ary[i];
    }
    l=1;
    r=n-1;
    go();
    printf("%d\n",ans);
}
*/
