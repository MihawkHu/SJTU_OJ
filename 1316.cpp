#include <iostream>
#include <cstring>
using namespace std;

int idle[1000010] = { 0 }; //to record the interval time

int main()
{
	int maxcontime = 0;
	int maxidle = 0;

	int minstart = 100000, maxend = 0;

	int n;  cin >> n;

	for (int i = 0; i < n; ++i) {
		int start = 0, end = 0;
		cin >> start >> end;
		if (minstart > start) minstart = start;
		if (maxend < end) maxend = end;
		for (int j = start; j < end; j++) {
			idle[j] = 1;
		}
	}
	
	for (int i = minstart; i < maxend; ++i) {
		if (idle[i] == 0) {
			int idlestart = i;
			while (idle[i] == 0) i++;
			int idleend = i;
			if (maxidle < idleend - idlestart) maxidle = idleend - idlestart;
		}
	}
	for (int i = minstart; i <= maxend; ++i) {
		if (idle[i] == 1) {
			int istart = i;
			while (idle[i] == 1) i++;
			int iend = i;
			if (maxcontime < iend - istart) maxcontime = iend - istart;
		}
	}




	cout << maxcontime << " " << maxidle;

	return 0;
}