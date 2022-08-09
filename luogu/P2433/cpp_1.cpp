#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double PI = 3.141593;

int main() {
    int T;
    cin >> T;
    switch (T){
        case 1: cout << "I love Luogu!"; break;
        case 2: cout << 2+4 << " " << 10-2-4; break;
        case 3: cout << 14/4 << endl << 14/4*4 << endl << 14%4; break;
        case 4: cout << fixed << setprecision(3) << 500.0/3; break;
        case 5: cout << (260+220)/(12+20);break;
        case 6: cout << sqrt(6*6+9*9); break;
        case 7: cout << 100+10 << endl << 100+10-20 << endl << 0; break;
        case 8: cout << 2*5*PI << endl << 5*5*PI << endl << 5*5*5*PI*4/3; break;
        case 9: cout << (((1+1)*2+1)*2+1)*2; break;
        case 10: cout << 9; break;
        case 11: cout << 100.0/3; break;
        case 12: cout << (int)('M'-'A')+1 << endl << (char)(18+'A'-1); break;
        case 13: cout << (int)pow(PI*(4*4*4+10*10*10)*4/3, 1.0/3); break;
        case 14: cout << 50; break;
    }
}
