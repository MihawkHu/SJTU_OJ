#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

char n1[1000100], n2[1000100], ans[1000100];

int strlen(char * a){
    int i = 0;
    while(a[i] != '\0') ++i;
    return i;
}

int main()
{
    cin >> n1 >> n2;
    int i;  ans[1] = '0';
    int len1 = strlen(n1), len2 = strlen(n2), len3 = 0;
    for(i = 1; i <= len1 || i <= len2 || ans[i] != '0'; ++i) {
        if(i <= len1) ans[i] += n1[len1 - i] - '0';
        if(i <= len2) ans[i] += n2[len2 - i] - '0';
        if(ans[i] > '9') {
            ans[i + 1] = '1';
            ans[i] -= 10;
        }
        else ans[i + 1] = '0';
    }
    len3 = i - 1;
    if(len3 == 0) len3 = 1;
    for(int i = len3; i >= 1; --i) cout << ans[i];
    return 0;
}
