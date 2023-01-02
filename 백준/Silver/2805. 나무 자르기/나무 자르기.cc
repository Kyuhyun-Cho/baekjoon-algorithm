#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long n, m;
	cin >> n >> m;

	long long tree[n];
	long long start = 0;
	long long mid = 0;
	long long end = -1;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		if (tree[i] > end) end = tree[i];
	}
	long long sum = 0;
	long long answer = 0;
	while(start <= end) {
		sum = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			if (tree[i] - mid > 0) {
				sum += tree[i] - mid;
			}
		}
		if (sum > m) {
			answer = mid;
			start = mid + 1;
		}
		else if (sum == m) {
			cout << mid;
			return 0;
		}
		else {
			end = mid - 1;
		}
	}
	cout << answer;
}