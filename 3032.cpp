#include <iostream>
using namespace std;

int strlen(char a[]) {
	int i = 0;
	while (a[i] != '\0') i++;
	return i;
}


void sub(char a[], char b[], char result[]) {
	int len1 = strlen(a), len2 = strlen(b);
	int carry = 0;
	for (int i = 0; i < len2; i++) {
		result[len1 - i - 1] = a[len1 - i - 1] - b[len2 - 1 - i] + '0' + carry;
		carry = 0;
		if (!(result[len1 - i - 1] <= '9' && result[len1 - i - 1] >= '0')) {
			carry = -1;
			result[len1 - i - 1] += 10;
		}
	}

	for (int i = len2; i < len1; i++) {
		result[len1 - i - 1] = a[len1 - i - 1] + carry;
		carry = 0;
		if (!(result[len1 - i - 1] <= '9' && result[len1 - i - 1] >= '0')) {
			carry = -1;
			result[len1 - i - 1] += 10;
		}
	}
	
	int pos = 0;
	while (result[pos] == 0) pos++;
	for (int i = 0; i < strlen(result) - pos + 3; ++i) {
		result[i] = result[pos + i];
	}
}


bool xiaodeng(char a[], char b[]) {
	int len1 = strlen(a), len2 = strlen(b);
	if (len1 < len2) return true;
	if (len1 > len2) return false;
	for (int i = 0; i < len1; i++) {
		if (a[i] < b[i]) return true;
		if (a[i] > b[i]) return false;
	}
	return true;
}

void cheng2(char a[]) {
	int len = strlen(a);
	for (int i = 0; i < len + 1; i++) {
		a[len + 1 - i] = a[len - i];
	}
	a[0] = '0';

	int carry = 0;
	for (int i = 0; i <= len; ++i) {
		a[len - i] = a[len - i] + a[len - i] - '0' + carry;
		carry = 0;
		if (!(a[len - i] <= '9' && a[len - i] >= '0')) {
			carry = 1;
			a[len - i] -= 10;
		}
	}
	
	if (a[0] == '0') {
		for (int i = 0; i < len + 1; i++) {
			a[i] = a[i + 1];
		}
	}
}


int main()
{
	char n[1010];
	cin.getline(n, 1010);

	char chengfang[1010];
	char result[1010];
	for (int i = 0; i < 1010; ++i) {
		chengfang[i] = '\0';
		result[i] = '\0';
	}
	chengfang[0] = '1';

	while (xiaodeng(chengfang, n)) {
		cheng2(chengfang);
	}

	cheng2(n);
	sub(n, chengfang, result);

	int len = strlen(result);
	result[len - 1] = result[len - 1] + 1;

	
	int pos = 0;
	for (int i = 0; i < len; i++) {
		if (result[i] != '0') {
			pos = i;
			break;
		}
	}

	for (; pos < len; pos++) cout << result[pos];
	return 0;
}