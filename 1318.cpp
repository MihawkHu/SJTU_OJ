#include <iostream>
using namespace std;

int n;
int sum = 0;
long long f[40][800];

long long zyj()
{
    int i, j, k;
    for(i = 2; i <= n; i++)
        for(j = 0; j <= (i + 1) * i / 2; j++)
        {
            if(j >= i)
                f[i][j] = f[i - 1][j] + f[i - 1][j - i];
            else if(j<i)
                f[i][j] = f[i - 1][j];
        }
    return f[n][sum];
}

int main()
{
    cin >> n;
    sum = ((n + 1) * n) / 2;
    if(sum % 2 != 0)
    {
        cout<<'0'<<endl;
        return 0;
    }
    sum /= 2;
    f[1][1] = 1;
    f[1][0] = 1;
    long long result = zyj();
    cout << result / 2;
    return 0;
}
