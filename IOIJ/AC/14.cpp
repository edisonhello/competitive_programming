#include <bits/stdc++.h>
using namespace std;
vector<string> V;
void parse(string &p) {
  V.clear();
  string w="";
  for(int i=0;i<p.length();i++)
    if(p[i]==' '&&"w"!=""){
        V.push_back(w);
        w="";
    }
    else w+=p[i];
  if(w!="")V.push_back(w);
}
bool isword(int &c) {
  if(c>='a'&&c<='z') return true;
  if(c>='A'&&c<='Z') {c=c-'A'+'a';return true;}
  return c=='-';
}
void input() {
  string poem="";
  int c;
  while(c=getchar()) {
    if(c=='.') break;
    if(isword(c))poem+=c;
    else poem+=' ';
  }
  parse(poem);
}
int calc() {
  int like = 0;
  for(auto w:V)
    if(w.length()<4)continue;
    else if(w=="meow") like += 3;
    else{
      if(w[0]=='m' && w[1]=='e' && w[2]=='o' && w[3]=='w') like += 1;
      int l=w.length();
      if(w[l-1]=='w' && w[l-2]=='o' && w[l-3]=='e' && w[l-4]=='m') like += 5;
    }
  return like;
}
int main() {
  int T;
  scanf("%d",&T);
  getchar();
  while(T--) {
    input();
    printf("%d\n",calc());
  }
}
