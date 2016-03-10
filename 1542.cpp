#include <iostream>
#include <cstdio>
using namespace std;

long long cnt;
int n;
int a[300100], tem[300100];

void msort(int a[], int s, int t, int tem[]) {
    if(s >= t) return;
    int i = s, mid = (s + t) >> 1, j = mid + 1, k = s;
    msort(a, s, mid, tem);  msort(a, j, t, tem);
    while(i <= mid || j <= t){
        if(j > t || (i <= mid && a[i] <= a[j])) tem[k++] = a[i++];
        else {
            tem[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }
    for(int p = s; p <= t; ++p) a[p] = tem[p];
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    msort(a, 1, n, tem);

    cout << cnt;


    return 0;
}
