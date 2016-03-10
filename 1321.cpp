#include <iostream>
using namespace std;

int n;
int cnt = 0;
int a[6] = {1, 2, 3, 5, 7, 9};

bool isprime(int a){
    if(a == 1) return false;
    if(a == 2) return true;
    for(int i = 2; i <= a / 2; ++i){
        if(a % i == 0) return false;
    }
    return true;
}


void zyj(int ans){
    if(cnt == n) {
        cout << ans << '\n';
        return;
    }
    for(int i = 0; i < 6; ++i){
        int tem = ans * 10 + a[i];
        if(isprime(tem)){
            cnt++;
            zyj(tem);
            cnt--;
        }
    }
}


int main()
{
    cin >> n;
    int ans = 0;
    zyj(ans);

    return 0;
}
