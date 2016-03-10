#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

char a[10000000], b[10000000];

int main()
{
    cin.getline(a, 10);
    cin.getline(a, 30);
    cin.getline(a, 10000000);
    cin.getline(b, 10000000);

    cout << a << ' ' << b;
    return 0;
}
