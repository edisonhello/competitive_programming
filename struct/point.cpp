#include<iostream>
struct pnt{
    int x,y;
    pnt(){x=y=0;}
    pnt(int x){this->x=this->y=x;}
    pnt(int x,int y){this->x=x;this->y=y;}
    pnt& operator=(const pnt &a){this->x=a.x;this->y=a.y;return *this;}
    friend std::istream& operator>>(std::istream &istm,pnt &a){istm>>a.x>>a.y;return istm;}
    friend std::ostream& operator<<(std::ostream &ostm,pnt &a){ostm<<"("<<a.x<<","<<a.y<<")";return ostm;}
    operator bool()const{return this->x||this->y;}
    pnt operator+(const pnt &a)const{pnt t=*this;t.x+=a.x;t.y+=a.y;return t;}
    pnt operator-(const pnt &a)const{pnt t=*this;t.x-=a.x;t.y-=a.y;return t;}
    pnt operator*(const int &a)const{pnt t=*this;t.x*=a;t.y*=a;return t;}
    pnt operator/(const int &a)const{pnt t=*this;t.x/=a;t.y/=a;return t;}
    pnt& operator+=(const pnt &a){this->x+=a.x;this->y+=a.y;return *this;}
    pnt& operator-=(const pnt &a){this->x-=a.x;this->y-=a.y;return *this;}
    pnt& operator*=(const int &a){this->x*=a;this->y*=a;return *this;}
    pnt& operator/=(const int &a){this->x/=a;this->y/=a;return *this;}
};
