#include<stdio.h>
#include<algorithm>
struct W{
	short ti,st;
	friend bool operator < (const W &a,const W &b){
		return a.st < b.st;
	}
};

W v[1000];
short n,m,i,e,d,now,t;
char c;

inline short rit(){
    t=0;
    do{
        c=getchar_unlocked();
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar_unlocked();
    }while(c>='0'&&c<='9');
    return t;
}

int main(){
	n=rit();
	do{
		m=rit();
		for(i=0;i<m;++i){
			e=rit(),d=rit();
			v[i]={e,d};
		}
		std::sort(v,v+m);
        now=0;
		for(i=0;i<m;++i){
            now+=v[i].ti;
			if(now > v[i].st){
				printf("unschedulable\n");
				goto end;
			}
		}
		printf("schedulable\n");
		end:;
	}while(--n);
}
