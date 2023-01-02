#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long k, n;
	cin >> k >> n;

	long long lan[k];
	long long max = -1;
	for (int i = 0; i < k; i++) {
		cin >> lan[i];
		if (lan[i] > max) max = lan[i];
	}

	long long start = 1;
	long long mid;
	long long end = max;
	long long cnt;
	long long answer = 0;
	while (start <= end) {
		cnt = 0;
		mid = (start+end)/2;
		for (int i = 0; i < k; i++) {
			cnt += lan[i] / mid;
		}

		if (cnt >= n) {
			answer = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	} 
	cout << answer << '\n';
}