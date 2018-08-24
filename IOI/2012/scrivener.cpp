#include<ext/rope>
#define a auto

__gnu_cxx::crope r[1<<20];
int x;

void Init(){}
void TypeLetter(char c){
    ++x;
    r[x]=r[x-1];
    r[x].push_back(c);
}
void UndoCommands(int u){
    ++x;
    r[x]=r[x-u-1];
}
char GetLetter(int p){
    return r[x][p];
}
