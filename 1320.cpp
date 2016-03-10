#include <cstdio>
using namespace std;

int a[1010][1010];
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= i; ++j)
            scanf("%d", &a[i][j]);
    for(int i = n - 1; i >= 1; --i)
        for(int j = 0; j <= i; ++j)
            a[i][j] = a[i][j] + (a[i + 1][j] > a[i + 1][j + 1] ? a[i + 1][j] : a[i + 1][j + 1]);
    int ans = a[1][1];
    printf("%d", ans);
    return 0;
}
