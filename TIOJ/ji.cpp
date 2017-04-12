#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=100+5 ;
struct mat
{
        DB a[maxn][maxn] ;
            int n,m ;
            };
             
             mat mat_mul(const mat &p,const mat &q)
             {
                    if(p.m != q.n) abort() ;
                        mat res ;
                            res.n = p.n ;
                                res.m = q.m ;
                                    for(int i=0;i<p.n;i++)
                                            for(int j=0;j<q.m;j++)
                                                {
                                                            res.a[i][j]=0.0 ;
                                                                    for(int k=0;k<p.m;k++)
                                                                                res.a[i][j]+= p.a[i][k]*q.a[k][j] ;
                                                                                    }
                                                                                        return res ;
                                                                                        }
                                                                                         
                                                                                         bool d[maxn][maxn] ;
                                                                                         int deg[maxn] ;
                                                                                         main()
                                                                                         {
                                                                                                int n,m ;
                                                                                                    while(scanf("%d%d",&n,&m)==2 && m+n)
                                                                                                        {
                                                                                                                    memset(d,0,sizeof(d)) ;
                                                                                                                            memset(deg,0,sizeof(deg)) ;
                                                                                                                                    int k ; scanf("%d",&k) ;
                                                                                                                                            while(k--)
                                                                                                                                                    {
                                                                                                                                                                    int x,y ; scanf("%d%d",&x,&y) ;
                                                                                                                                                                                x-- ; y-- ;
                                                                                                                                                                                            d[x][y]=d[y][x]=1 ;
                                                                                                                                                                                                        deg[x]++ ; deg[y]++ ;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                        mat ans,M ;
                                                                                                                                                                                                                                ans.n=n , ans.m=1 ;
                                                                                                                                                                                                                                        for(int i=0;i<n;i++) ans.a[i][0]=1.0/n ;
                                                                                                                                                                                                                                         
                                                                                                                                                                                                                                                 M.n=M.m=n ;
                                                                                                                                                                                                                                                         for(int i=0;i<n;i++) for(int j=0;j<n;j++)
                                                                                                                                                                                                                                                                     M.a[i][j]= deg[j] ? ((DB)d[i][j])/((DB)deg[j]) : 0.0 ;
                                                                                                                                                                                                                                                                      
                                                                                                                                                                                                                                                                              for(int i=1;m;i*=2)
                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                    if(m&i) ans=mat_mul(M,ans) , m^=i ;
                                                                                                                                                                                                                                                                                                                M=mat_mul(M,M) ;
                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                         
                                                                                                                                                                                                                                                                                                                                 int q ; scanf("%d",&q) ;
                                                                                                                                                                                                                                                                                                                                         printf("%.4f\n",ans.a[q-1][0]) ;
                                                                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                                                                             }
