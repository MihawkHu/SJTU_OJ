#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int n;
int a[20100] = { 0 };
int size = 0;

void qsort(int s, int t) {
    if(s >= t) return;
    int i = s, j = t, mid = a[(i + j) >> 1];
    while(i <= j) {
        while(a[i] > mid) ++i;
        while(a[j] < mid) --j;
        if(i <= j) {
            int tem = a[i];
            a[i] = a[j];
            a[j] = tem;
            ++i;  --j;
        }
    }
    qsort(s, j);
    qsort(i, t);
}



int main()
{
    cin >> n;
    char op[10];
    bool flag = false;
    for(int i = 1; i <= n; ++i) {
        cin >> op;
        if(op[0] == 'i') {
            cin >> a[++size];
            flag = true;
        }
        else if(op[0] == 'd') {
            if(flag) qsort(1, size);
            size--;
        }
        else if(op[0] == 'm') {
            if(flag) qsort(1, size);
            cout << a[size] << endl;
        }
    }
    return 0;
}
