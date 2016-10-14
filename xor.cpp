#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define PB(x) push_back(x)
#define pii pair<int,int>
#define rz(x) reserve(x)
#define X first
#define Y second
// #define m (l+r)/2
// #define xm (x1+x2)/2
// #define ym (y1+y2)/2
#define DE cout<<"de"<<endl;
#define PQ priority_queue
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);___++)cout<<x[___]<<" ";cout<<endl;

string cipherTextCode[11] = {
  "0054411A4112001B0A0A071116450E1B451C4F15000C4F1E1809490F471B49581B4E4F3355041C031C454015000D",
  "2B55154D4404531B0C0D165410000803474E001A4C18001A19121D4E4F02000A54414F1F490D1C040D451E4F1A02",
  "080011044E04411B1515165402000F4D4F0C191D4F14531C15",
  "2054461E0012451F11101D13521109080007010045134E151841060000120C0A11",
  "01490D014113594B26151A1A060A0F4A534E0C154D1141190B0F490D4F19080D1A490C13540A061E1B45164906001B006F72",
  "08430202520549050259071B52310908003A06194512",
  "1A48044D540E4C0F452D1B1152310800451D4F15420E55044C555C4E4D1D0B0D00451C5241051D151A4506411F00171266",
  "28430202520549050259071B52290408441D48544102431F190F1D",
  "2249121E450500060059171D000002194C174F1B4E4154180941040155000D",
  "000005024E46544B11111A1A1945081900060E0450044E1508",

  //Target
  "03491B1700084E4B08005304130B15"
}, cipherText[11];


int main(){
    for(int i=0;i<11;i++){
        for(int j=0;j<(int)cipherTextCode[i].length();j+=2){
            cipherText[i].push_back((cipherTextCode[i][j]-'0')*16+cipherTextCode[i][j+1]-'0');
        }
        // cout<<cipherText[i]<<endl;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<min(cipherText[i].length(),cipherText[10].length());j++){
            char c=(cipherText[i][j]^cipherText[10][j]);
            cout<<(((c>='A'&&c<='Z')||(c>='a'&&c<='z'))?c:'-');
        }
        cout<<endl;
    }
}
