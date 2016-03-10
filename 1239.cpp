#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int x;

int main()
{
    cin >> x;
    if(x <= 3500) {
        cout << 0;
        return 0;
    }
    x -= 3500;
    if(x <= 1500) {
        cout << (int)(x * 0.03);
        return 0;
    }
    if(x <= 4500) {
        cout << (int)(1500 * 0.03 + (x - 1500) * 0.1);
        return 0;
    }
    if(x <= 9000) {
        cout << (int)(1500 * 0.03 + 3000 * 0.1 + (x - 4500) * 0.2);
        return 0;
    }
    if(x <= 35000) {
        cout << (int)(1500 * 0.03 + 3000 * 0.1 + 4500 * 0.2 + (x - 9000) * 0.25);
        return 0;
    }
    if(x <= 55000) {
        cout << (int)(1500 * 0.03 + 3000 * 0.1 + 4500 * 0.2 + 26000 * 0.25 + (x - 35000) * 0.3);
        return 0;
    }
    if(x <= 80000) {
        cout << (int)(1500 * 0.03 + 3000 * 0.1 + 4500 * 0.2 + 26000 * 0.25 + 20000 * 0.3 + (x - 55000) * 0.35);
        return 0;
    }
    cout << (int)(1500 * 0.03 + 3000 * 0.1 + 4500 * 0.2 + 26000 * 0.25 + 20000 * 0.3 + 25000 * 0.35 + (x - 80000) * 0.45);
    return 0;
}
