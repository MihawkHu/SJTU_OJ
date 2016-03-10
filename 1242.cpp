#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

bool isprime(int x) {
    if(x == 1) return false;
    if(x == 2) return true;
    if(x == 3) return true;
    for(int i = 2; i * i <= x; ++i) {
        if(x % i == 0) return false;
    }
    return true;
}




int main()
{
    int a, b;  cin >> a >> b;
    int cnt = 0;
    for(int i = a; i <= b; ++i) {
        if(isprime(i)) cnt++;
    }
    cout << cnt;
    return 0;
}
