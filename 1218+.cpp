#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
const int maxlen = 1000100;

int a[maxlen], b[maxlen], size = 0;
int n;

bool find(int x, int a[], int size) {
    for(int i = 1; i <= size; ++i) {
        if(a[i] == x) return true;
    }
    return false;
}

void qsort(int s, int t) {
    if(s >= t) return;
    int i = s, j = t, mid = a[(i + j) >> 1];
    while(i <= j) {
        while(a[i] < mid) i++;
        while(a[j] > mid) --j;
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

void output() {
    qsort(1, size);
    for(int i = 1; i <= size; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    cin >> n;
    char op;
    for(int p = 1; p <= n; ++p) {
        cin >> op;
        if(op == '+') {
            int m;  cin >> m;
            for(int i = 1; i <= m; ++i) {
                int x;  cin >> x;
                if(!find(x, a, size)) a[++size] = x;
            }
            output();
        }
        else if(op == '-') {
            int m;  cin >> m;
            int size2 = 0;
            for(int i = 1; i <= m; ++i) {
                cin >> b[i];
                size2++;
            }
            int j = 0;
            for(int i = 1; i <= size; ++i) {
                if(!find(a[i], b, size2)) a[++j] = a[i];
            }
            size = j;
            output();
        }
        else if(op == '*') {
            int m;  cin >> m;
            int j = 0;
            for(int i = 1; i <= m; ++i) {
                int x;  cin >> x;
                if(find(x, a, size)) b[++j] = x;
            }
            for(int i = 1; i <= j; ++i) a[i] = b[i];
            size = j;
            output();
        }
    }
    return 0;
}
