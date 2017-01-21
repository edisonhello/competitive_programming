#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct BigNum
{
    int A[60]; int An;

    BigNum(){ fill(A, A+60, 0); An = 0; }
    BigNum(char *c)
    {
        fill(A, A+60, 0); An = strlen(c);
        for(int cn = strlen(c), ci = 0; ci < cn; ci++)
            A[ci] = c[cn-ci-1]-'0';
    }
    void operator=(const BigNum &p)
    {
        for(int i = 0; i < 60; i++)
            A[i] = p.A[i];
        An = p.An;
    }
    bool operator<=(const BigNum &p)
    {
        for(int i = max(An, p.An); i >= 0; i--)
            if( A[i] < p.A[i] ) return true;
            else if( A[i] > p.A[i] ) return false;

        return true;
    }
    BigNum operator<<(int x)const
    {
        BigNum re = BigNum();

        for(int Ai = 0; Ai < An; Ai++)
            re.A[Ai+x] = A[Ai];
        re.An = An+x;

        return re;
    }
    void operator-=(const BigNum &p)
    {
        for(int Ai = 0; Ai < An; Ai++)
        {
            A[Ai] -= p.A[Ai];
            if( A[Ai] < 0 ) A[Ai] += 10, A[Ai+1]--;
        }
    } // only work if the result is positive
    BigNum operator/(const BigNum &p)const
    {
        BigNum re = BigNum();
        BigNum t = *this;

        re.An = max(An-p.An, 0)+1;

        for(int i = An-p.An; i >= 0; i--)
            while( (p<<i) <= t ) t -= (p<<i), re.A[i]++;

        return re;
    }
};

void print(BigNum const &p)
{
    int i = p.An-1;

    while( !p.A[i] && i > 0 ) i--;
    while( i >= 0 ) printf("%d", p.A[i--]);
    puts("");
}

char s[60], r[60];

int main()
{
    scanf("%s", s);
    scanf("%s", r);

    BigNum Ans = BigNum(s)/BigNum(r);
    print(Ans);
}
