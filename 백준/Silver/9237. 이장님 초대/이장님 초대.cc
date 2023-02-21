#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	int arr[100001];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n, cmp);
	for (int i = 1; i <= n; i++) {
		arr[i-1] += i;
	}
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	cout << max + 1 << '\n';
}