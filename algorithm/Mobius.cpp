void mobius(){
    for(int i=1;i<=10000000;++i){
        pre[i]=pre[i-1]+u[i];
        for(int j=i*2;j<=10000000;j+=i){
            u[j]-=u[i];
        }
    }
}
