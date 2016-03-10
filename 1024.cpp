#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;


int n;
int a[100100];

void qsort(int s, int t) {
    if(s >= t) return;
    int i = s, j = t, mid = a[(s + t) >> 1];
    while(i <= j){
        while(a[i] < mid) i++;
        while(a[j] > mid) j--;
        if(i <= j) {
            int tem = a[i];
            a[i] = a[j];
            a[j] = tem;
            i++;  j--;
        }
    }
    qsort(s, j);
    qsort(i, t);
}


int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    qsort(1, n);

    for(int i = 1; i <= n; ++i) { printf("%d", a[i]);  printf(" "); }

    return 0;
}
