#ifndef LIBTEST_H_INCLUDED
#define LIBTEST_H_INCLUDED
#include <stdio.h>

void pop_big();
void pop_small();
void push(int s);
int big();
int small();
void pnt();

int main()
{
   int n;
   scanf("%d", &n);
   while(n--)
   {
       int case_num, s;
       scanf("%d", &case_num);
       if(case_num == 1) pop_big();
       else if (case_num == 2) pop_small();
       else if (case_num == 3)
       {
           scanf("%d", &s);
           push(s);
       }
       else if (case_num == 4) printf("%d\n", big());
       else if (case_num == 5) printf("%d\n", small());
       // else if (case_num == 6) pnt();
       else if (case_num == 7122) return 0;
       else puts("Case number is out of range!!");
   }
   return 0;
}

#endif
