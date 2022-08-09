#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a;
int main(){
    cin >> a;
    reverse(a.begin(), a.end());
    cout << a;
}
