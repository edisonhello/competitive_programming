// UVa 10104
void extgcd(int a,int b,int &x,int &y,int &g){
    if(!b){
        x=1, g=a;
        return;
    }
    extgcd(b,a%b,y,x,g);
    y-=(a/b)*x;
}
int main(){
    int a,b;
    while(cin>>a>>b){
        int x=0,y=0,g=0;
        extgcd(a,b,x,y,g);
        cout<<x<<" "<<y<<" "<<g<<endl;
    }
}
