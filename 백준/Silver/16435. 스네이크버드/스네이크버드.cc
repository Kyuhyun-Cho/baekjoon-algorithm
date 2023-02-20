#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, len;
int arr[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> len;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr+n);

	for (int i = 0; i < n; i++) {
		if (len >= arr[i]) {
			len++;
		}
	}

	cout << len << '\n';
}