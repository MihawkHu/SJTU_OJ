#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
const int maxlen = 100100;

int le1[maxlen] = { 0 }, ri1[maxlen] = { 0 }, we1[maxlen] = { 0 };
int le2[maxlen] = { 0 }, ri2[maxlen] = { 0 }, we2[maxlen] = { 0 };
bool flag = false;
bool c1[maxlen], c2[maxlen];
int n, m;

void eq(int i, int j) {
    if(we1[i] != we2[j]) {
        cout << "N" << endl;
        flag = true;
        return;
    }
    if(i == 0) return;
    if(!flag) eq(le1[i], le2[j]);
    if(!flag) eq(ri1[i], ri2[j]);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> le1[i] >> ri1[i] >> we1[i];
        c1[le1[i]] = c1[ri1[i]] = true;
    }
    cin >> m;
    if(n != m) {
        cout << "N" << endl;
        return 0;
    }
    for(int i = 1; i <= m; ++i) {
        cin >> le2[i] >> ri2[i] >> we2[i];
        c2[le2[i]] = c2[ri2[i]] = true;
    }
    int r1 = 0, r2 = 0;
    for(int i = 1; i <= n; ++i) {
        if(c1[i] == false) r1 = i;
        if(c2[i] == false) r2 = i;
        if(r1 != 0 && r2 != 0) break;
    }
    eq(r1, r2);
    if(!flag) cout << "Y" << endl;
    return 0;
}
