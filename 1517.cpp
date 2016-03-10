#include <iostream>
using namespace std;

int strlen(char a[]) {
	int i = 0;
	while (a[i] != '\0') ++i;
	return i;
}



char a[100000], b[100000], result[100000];



int main()
{
	cin >> a >> b;
	int n = strlen(a), m = strlen(b);
	int carry = 0;

//	for (int i = 0; i < 100000; ++i) result[i] = '\0';

	if (n > m ) {
		for (int i = 0; i < m; i++) {
			char tem = a[n - i - 1] - b[m - i - 1] + '0' + carry;
			carry = 0;
			if (tem <= '9' && tem >= '0') result[i] = tem;
			else {
				tem = tem + 10;
				carry = -1;
				result[i] = tem;
			}
		}
		for (int j = m; j < n; ++j) {
			char tem = a[n - j - 1] + carry;
			carry = 0;
			if (tem <= '9' && tem >= '0') result[j] = tem;
			else {
				tem = tem + 10;
				carry = -1;
				result[j] = tem;
			}
		}
		int i = strlen(result) - 1;
		while (result[i] == '0') --i;
		while (i >= 0) {
			cout << result[i];
			--i;
		}
		return 0;
	}

	else if (m == n) {
		bool flag;
		for (int i = n - 1; i >= 0; --i) {
			flag = true;
			if (a[i] < b[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			for (int i = 0; i < m; i++) {
				char tem = a[n - i - 1] - b[m - i - 1] + '0' + carry;
				carry = 0;
				if (tem <= '9' && tem >= '0') result[i] = tem;
				else {
					tem = tem + 10;
					carry = -1;
					result[i] = tem;
				}
			}
			int i = strlen(result) - 1;
			while (result[i] == '0') --i;
			while (i >= 0) {
				cout << result[i];
				--i;
			}
		}
		else {
			for (int i = 0; i < m; i++) {
				char tem = b[n - i - 1] - a[m - i - 1] + '0' + carry;
				carry = 0;
				if (tem <= '9' && tem >= '0') result[i] = tem;
				else {
					tem = tem + 10;
					carry = -1;
					result[i] = tem;
				}
			}
			int i = strlen(result) - 1;
			while (result[i] == '0') --i;
			cout << '-';
			while (i >= 0) {
				cout << result[i];
				--i;
			}
		}
	}

	 else if(m > n){
		int t; t = m; m = n; n = t;
		for (int i = 0; i < m; i++) {
			char tem = b[n - i - 1] - a[m - i - 1] + '0' + carry;
			carry = 0;
			if (tem <= '9' && tem >= '0') result[i] = tem;
			else {
				tem = tem + 10;
				carry = -1;
				result[i] = tem;
			}
		}
		for (int j = m; j < n; ++j) {
			char tem = b[n - j - 1] + carry;
			carry = 0;
			if (tem <= '9' && tem >= '0') result[j] = tem;
			else {
				tem = tem + 10;
				carry = -1;
				result[j] = tem;
			}
		}
		int i = strlen(result) - 1;
		while (result[i] == '0') --i;
		cout << '-';
		while (i >= 0) {
			cout << result[i];
			--i;
		}
	}
	return 0;
}