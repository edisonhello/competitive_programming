int a[]={0,3,4,5,6,2,1,0,3};
int ori[22],cf[22],n=8;

void add(int *BIT,int x,int v){
    while(x<=n){
        BIT[x]+=v;
        x+=lowbit(x);
    }
}
int query(int *BIT,int x,int v=0){
    while(x>0){
        v+=BIT[x];
        x-=lowbit(x);
    } return v;
}
int sum(int x){
    int ans=0;
    ans+=query(cf,x)*x;
    ans+=query(ori,x);
    return ans;
}

int main(){
    char c; int l,r,v;
    for(int i=1;i<=8;++i)add(ori,i,a[i]);
    while(cin>>c && c!='='){
        if(c=='Q'){
            cin>>l>>r;
            cout<<sum(r)-sum(l-1)<<endl;
        }
        else{
            cin>>l>>r>>v;
            add(ori,l,-v*(l-1));
            add(ori,r+1,v*r);
            add(cf,l,v);
            add(cf,r+1,-v);
        }
    }
}
