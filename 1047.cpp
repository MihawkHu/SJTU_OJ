#include <iostream>
using namespace std;

int m[10] = { 0 }; // the method
int result[10];

int main()
{
	int clock[10]; // the clock
	for (int i = 1; i <= 9; i++) {
		cin >> clock[i];
		if (clock[i] == 12) clock[i] = 0;
	}

	
	int result[10];

	int count = 0;
	int mincount = 1000;

	int b[10] = { 0 };
	for (b[1] = 0; b[1] <= 3; b[1]++)
		for (b[2] = 0; b[2] <= 3; b[2]++)
			for (b[3] = 0; b[3] <= 3; b[3]++)
				for (b[4] = 0; b[4] <= 3; b[4]++)
					for (b[5] = 0; b[5] <= 3; b[5]++)
						for (b[6] = 0; b[6] <= 3; b[6]++)
							for (b[7] = 0; b[7] <= 3; b[7]++)
								for (b[8] = 0; b[8] <= 3; b[8]++)
									for (b[9] = 0; b[9] <= 3; b[9]++) {
										int a[10];
										for (int i = 1; i <= 9; ++i) {
											a[i] = clock[i];
										}

										for (int c = 0; c < b[1]; ++c) {
											a[1] = (a[1] + 3) % 12;
											a[2] = (a[2] + 3) % 12;
											a[4] = (a[4] + 3) % 12;
											a[5] = (a[5] + 3) % 12;
										}
										for (int c = 0; c < b[2]; ++c) {
											a[1] = (a[1] + 3) % 12;
											a[2] = (a[2] + 3) % 12;
											a[3] = (a[3] + 3) % 12;
										}
										for (int c = 0; c < b[3]; ++c) {
											a[2] = (a[2] + 3) % 12;
											a[3] = (a[3] + 3) % 12;
											a[5] = (a[5] + 3) % 12;
											a[6] = (a[6] + 3) % 12;
										}
										for (int c = 0; c < b[4]; ++c) {
											a[1] = (a[1] + 3) % 12;
											a[4] = (a[4] + 3) % 12;
											a[7] = (a[7] + 3) % 12;
										}
										for (int c = 0; c < b[5]; ++c) {
											a[2] = (a[2] + 3) % 12;
											a[4] = (a[4] + 3) % 12;
											a[5] = (a[5] + 3) % 12;
											a[6] = (a[6] + 3) % 12;
											a[8] = (a[8] + 3) % 12;
										}
										for (int c = 0; c < b[6]; ++c) {
											a[3] = (a[3] + 3) % 12;
											a[6] = (a[6] + 3) % 12;
											a[9] = (a[9] + 3) % 12;
										}
										for (int c = 0; c < b[7]; ++c) {
											a[4] = (a[4] + 3) % 12;
											a[5] = (a[5] + 3) % 12;
											a[7] = (a[7] + 3) % 12;
											a[8] = (a[8] + 3) % 12;
										}
										for (int c = 0; c < b[8]; ++c) {
											a[7] = (a[7] + 3) % 12;
											a[8] = (a[8] + 3) % 12;
											a[9] = (a[9] + 3) % 12;
										}
										for (int c = 0; c < b[9]; ++c) {
											a[5] = (a[5] + 3) % 12;
											a[6] = (a[6] + 3) % 12;
											a[8] = (a[8] + 3) % 12;
											a[9] = (a[9] + 3) % 12;
										}

										bool flag = true;
										for (int i = 1; i <= 9; i++) {
											if (a[i] != 0) {
												flag = false;
												break;
											}
										}

										if (flag) {
											count = b[1] + b[2] + b[3] + b[4] + b[5] + b[6] + b[7] + b[8] + b[9];
											if (count < mincount) {
												mincount = count;
												for (int i = 1; i <= 9; ++i) result[i] = b[i];
											}
										}
									}
	bool flag = false;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= result[i]; j++) {
			if (flag) cout << " ";
			else flag = true;
			cout << i;
		}
	}



	return 0;
}