#include "timecard.h"

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <iostream>

int readInt(){
	int i;
	if(scanf("%d",&i)!=1){
		fprintf(stderr,"Error while reading input\n");
		exit(1);
	}
	return i;
}

int main(){
	int n;
	n=readInt();
	init(n);
	
	for(int i=0;i<n;i++){
		std::string s;
		std::cin >> s;
		s = convert(s);
		std::cout << s << std::endl;
	}
}
